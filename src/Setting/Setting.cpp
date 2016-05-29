//
// Created by 墨林 on 16/5/28.
//
#include "Setting.h"
#include "../User.h"
#include <fstream>
using namespace std;

Setting::Setting(){

}

Setting::Setting(User u1){

}

void Setting::importUser() {
    ifstream import("userslist.txt");

}

void Setting::saveSet() {
    Setting writeSet;
    writeSet.numberofUser = this->numberofUser;
    fstream ifExist("setting.dat", ios::binary|ios::out|ios::in|ios::app);
    if (!ifExist){
        ofstream outSet("setting.dat", ios::binary);
        outSet.write(reinterpret_cast<const char*>(&writeSet),
                     sizeof(writeSet));

    }
    else{
        Setting readSet;
        ifExist.read(reinterpret_cast< char*>(&readSet),
                     sizeof(readSet));
        while(ifExist&&!ifExist.eof()){

    }

}

void Setting::saveNewSet() {

}
