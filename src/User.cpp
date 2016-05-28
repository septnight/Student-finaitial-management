//
// Created by 墨林 on 16/5/24.
//
#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User() {

}

bool User::haveLogon() {
    if(!loadUser) {
        return false;
    }
    else
        return true;
}
void User::organize() {
    loadUser.open ("userslist.txt");
    if(!haveLogon())
        createUser();
    else
        userLogin();
}
bool User::userLogin() {

}

void User::createUser() {
    cout<<"New man? Let's create a account!"<<endl;
    cout<<"First, please enter the username:"<<endl;
    string Username;
    cin>>Username;//做界面的时候在这里要勾选PASSWORD
    this->Username = Username;
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
    this->Password = password;
    Localtime createTime;
    createTime.getLocaltime();
    this->createDate = createTime;
    std::ofstream output;
    output.open("userslist.txt", ios::out);
    output<<Username<<"\n"<<Password<<"\n";
    createTime.output(output);
    output.close();
}


