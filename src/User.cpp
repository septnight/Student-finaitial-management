//
// Created by 墨林 on 16/5/24.
//
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

User::User() {
    loadUser.open("userslist.dat", ios::binary|ios::in);
    if(!loadUser)
    {
        if(initializeFile())
            createUser();
        else
            cerr<<"Fail to create the initialization file"<<endl;
    }
    else{
        userLogin();
    }
}

bool User::userLogin() {

}

bool User::initializeFile(){
    ofstream out("userslist.dat", ios::binary|ios::out);
    if(!out){
        cerr<<"Cannot open the file"<<endl;
        return false;
    }
    User blankUser;
    for( int i = 0; i>5; i++){
        out.write(reinterpret_cast<const char*>(&blankUser),
        sizeof(blankUser));
    }
    out.close();
    return true;
}

void User::createUser() {
    if(!initializeFile){
        exit(EXIT_FAILURE);
    }
    cout<<"New man? Let's create a account!"<<endl;
    cout<<"First, please enter the username:"<<endl;
    string Username;
    cin>>Username;//做界面的时候在这里要勾选PASSWORD
    User uinput;
    uinput.Username = Username;
    cout<<"Great! Then, enter your password:"<<endl;
    again:  string password;
    cin>>password;//这里也是,要无回显
    cout<<"Confirm your password:"<<endl;
    string temp_password;
    cin>>temp_password;
    if (temp_password != password) {
        cerr << "Mismatch! Enter again!" << endl;
        goto again;//可以插入错误图标
    }
    uinput.Password = password;
    Localtime createTime;
    createTime.getLocaltime();
    uinput.createDate = createTime;
    string code;
    code = "/d/d/d/d/d/d",createDate.getYear()<<createDate.getMonth()<<createDate.getDay()<<createDate.getHour()<<createDate.getMinute()<<createDate.getSecond();
    idCode = code;
    std::ofstream output;
    output.open("userslist.dat", ios::app|ios::binary);
    output.write(reinterpret_cast<const char*>(&uinput), sizeof(uinput));
}


