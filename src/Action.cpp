//
// Created by 墨林 on 16/5/28.
//
#include "User.h"
#include "Action.h"
#include <iostream>
#include <sstream>

using namespace std;

Action::Action() {

}


void Action::userLogin() {
    ifstream compare("userslist.dat", ios::in|ios::binary);
    string buf;
    char chose;
    read:
    compare.seekg(0);
    compare.read(reinterpret_cast<char*>(&demo), sizeof(User));
    cout<<"Enter your username:"<<endl;
    cin>>buf;
    while(!(compare.eof())) {
        compare.read(reinterpret_cast<char*>(&demo), sizeof(User));
        if (buf == demo.Username) {
            break;
        }
        else
        {
            if(compare.eof())
            {
                cout<<"The user is not exist, do you want to create a new user? Y/N"<<endl;
                cin>>chose;
                switch(chose){
                    case 'n':
                    case 'N':
                        goto read;
                    case'y':
                    case'Y':
                        createUser(buf);
                        goto welcome;
                    default:
                        cerr<<"Error, cannot reach!"<<endl;
                }
            }
        }
    }
    enterpass:
    cout << "Enter the password:" << endl;
    cin >> buf;
    if (buf != demo.Password) {
        cout << "Incorrect password!" << endl;
        goto enterpass;

    }
    else {
        welcome:
        cout << "Welcome " << demo.Username << endl;
    }

    compare.close();
}

void Action::startApp() {
    loadUser.open("userslist.dat", ios::binary|ios::in);
    if(!loadUser)
    {
        if(initializeFile()) {
            createUser();
        }
        else
            cerr<<"Fail to create the initialization file"<<endl;
    }
    else{
        userLogin();
    }
}

void Action::createUser() {
    User createU;
    cout<<"New man? Let's create a account!"<<endl;
    cout<<"First, please enter the username:"<<endl;
    string Username;
    cin>>Username;//做界面的时候在这里要勾选PASSWORD
    createU.Username = Username;
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
    createU.Password = password;
    Localtime createTime;
    createTime.getLocaltime();
    createU.createDate = createTime;
    stringstream code;
    code<<createU.createDate.getYear()
    <<createU.createDate.getMonth()
    <<createU.createDate.getDay()
    <<createU.createDate.getHour()
    <<createU.createDate.getMinute()
    <<createU.createDate.getSecond();
    code>>createU.idCode;
    std::ofstream output;
    output.open("userslist.dat", ios::app|ios::binary);
    output.write(reinterpret_cast<const char*>(&createU), sizeof(User));
}

void Action::createUser(std::string Username) {

    demo.Username = Username;
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
    demo.Password = password;
    Localtime createTime;
    createTime.getLocaltime();
    demo.createDate = createTime;
    stringstream code;
    code<<demo.createDate.getYear()
    <<demo.createDate.getMonth()
    <<demo.createDate.getDay()
    <<demo.createDate.getHour()
    <<demo.createDate.getMinute()
    <<demo.createDate.getSecond();
    code>>demo.idCode;
    std::ofstream output;
    output.open("userslist.dat", ios::app|ios::binary);
    output.write(reinterpret_cast<const char*>(&demo), sizeof(User));
}

bool Action::initializeFile() {
    ofstream out("userslist.dat", ios::binary|ios::out);
    if(!out){
        cerr<<"Cannot open the file"<<endl;
        return false;
    }
    User blankUser;
    for( int i = 0; i<5; i++){
        out.write(reinterpret_cast<const char*>(&blankUser),
                  sizeof(User));
    }
    out.close();
    return true;
}









