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
    ifstream check("setting.dat", ios::binary|ios::in);
    if (!check){
        ofstream initialize("setting.dat", ios::binary|ios::out);
        for( int i = 0; i<5; i++){
//            initialize.write(reinterpret_cast<const char*>(&))
        }

    }

}

void Setting::saveNewSet() {

}
