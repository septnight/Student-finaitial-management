//
// Created by 墨林 on 16/5/28.
//
#include "User.h"
#include "Action.h"
#include <iostream>
#include <sstream>

using namespace std;

Action::Action() {
    cerr<<"Action:"<<this<<endl;
}


void Action::userLogin() {
    ifstream compare("userslist.dat", ios::in|ios::binary);
    cerr<<"readUser"<<endl;
    string buf;
    char chose;
    read:
    compare.seekg(0);
    compare.read(reinterpret_cast<char*>(&demo), sizeof(User));
    cout<<"Enter your username:"<<endl;
    cin>>buf;
    while(!(compare.eof())) {
        compare.read(reinterpret_cast<char*>(&demo), sizeof(User));
        if (buf == demo.getName()) {
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
                        demo.createUser(buf);
                        break;
                    default:
                        cerr<<"Error, cannot reach!"<<endl;
                }
            }
        }
    }

    bool flag = true;
    while(flag) {
        cout << "Enter the password:" << endl;
        cin >> buf;
        if (buf != demo.getPass()) {
            cout << "Incorrect password!" << endl;
        }
        else {
            cout << "Welcome " << demo.getName() << endl;
            flag = false;
        }
    }
    compare.close();
}

void Action::startApp() {
    loadUser.open("userslist.dat", ios::binary|ios::in);
    if(!loadUser)
    {
        if(demo.initializeFile()) {
            demo.createUser();
        }
        else
            cerr<<"Fail to create the initialization file"<<endl;
    }
    else{
        userLogin();
    }
}



