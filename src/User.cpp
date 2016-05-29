//
// Created by 墨林 on 16/5/24.
//

#include "User.h"
#include <iostream>

using namespace std;

User::User() {

}

int User::getUserNumber() {
    return id;
}


User::User(std::string Filename) {
    filename = Filename;
}
bool User::prepare() {
    fs.open(filename, ios::in | ios::out | ios::binary);

    if (!fs) {
        fs.open(filename, ios::out | ios::binary);
        fs.close();

        fs.open(filename, ios::in | ios::out | ios::binary);
        if (!fs) return false;
    }

    return init_cache();
}

int User::write(Urecord* from){
    if(from->isEmpty()|fs.is_open()) return -1;
    fs.seekg(id*sizeof(Urecord));
    fs.write(reinterpret_cast<char*>(&from), sizeof(from));
    id += 1;
    return id;
}

bool User::read(std::string username){

    vector<Urecord*> v;
    fetch_all(v);
    for(auto user:v){
        if(user->Username == username){
            Username = username;
            extract_entry(user, &data);
            return true;
        }
    }
    return false;

}

bool User::init_cache() {
    Urecord entry;
    if(!fs.is_open()) return false;
    return true;
}

int User::fetch_all(vector<Urecord*>& u) {
    Urecord entry;
    if(!fs.is_open()) return false;

    u.clear();
    fs.seekg(0);
    while(!fs.eof()){
        fs.read(reinterpret_cast<char*>(&entry), sizeof(Urecord));
        streamsize count = fs.gcount();
        if (!count) break;
        if (count != sizeof(Urecord)) return -1; /* corrupted */
        if(!entry.isEmpty()){
            Urecord* rec = new Urecord;
            extract_entry(&entry, rec);
            u.push_back(rec);
        }
    }
    id = u.size();
}

void User::extract_entry(Urecord *from, Urecord *to) {
    to->Username = from->Username;
    to->createDate = from->createDate;
    to->Password = from ->Password;
}

void User::finish() {
    fs.close();
}

void User::searchUser(int usernumber, Urecord*back) {
    vector<Urecord*> find;
    fetch_all(find);
    for(auto user:find){
        if(user->userNumber == usernumber) {
            extract_entry(user, back);
            return;
        }
    }
}
