//
// Created by 墨林 on 16/5/4.
//

#include <iostream>
#include "uinput.h"
#include <stdexcept>
#include <fstream>
using namespace std;
uinput::uinput() {
    double money;
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int account;

    for(int i = 1;i<6;i++){
        propose(i);
        try{
            switch(i){
                case 1:
                    if(cin>>money)
                        Money = money;
                    else
                        throw invalid_argument{
                                "The type of input does not match double"
                        };
                    break;

                case 2: {
                    if (cin >> day)
                        Day = day;
                    else
                        throw invalid_argument{
                                "The type of input does not match unsigned int"
                        };
                    break;
                }
                case 3:
                {
                    if (cin >> month)
                        Month = month;
                    else
                        throw invalid_argument{
                                "The type of input does not match unsigned int"
                        };
                    break;
                }
                case 4:
                {
                    if (cin >> year)
                        Year = year;
                    else
                        throw invalid_argument{
                                "The type of input does not match unsigned int"
                        };
                    break;
                }
                case 5:
                {
                    if(cin>>account)
                        Account = account;
                    else
                        throw invalid_argument{
                                "The type mimatch"
                        };
                }
                default:
                    throw invalid_argument{
                            "Cannot reach!"
                    };

            }
        }
        catch(invalid_argument &e){
            cout<<e.what()<<endl;
        }
    }
}

void uinput::propose(int pass) const {
    int check[6] = {1, 2, 3, 4, 5, 6};
    bool flag = false;
    for(int i = 0;i<6;i++){
        if(check[i] == pass) {
            flag = true;
            break;
        }
    }
    if(!flag)
        throw invalid_argument{
                "The value of pass is invalid"
        };
    switch(pass){
        case 1:
            cout<<"Please input the amount of the money:";
            break;
        case 2:
            cout<<"Please input the date:";
            break;
        case 3:
            cout<<"Please input the name of the item:";
            break;
        case 4:
            cout<<"Please input the tag:";
            break;
        case 5:
            cout<<"Please input the account:";
            break;
        case 6:
            cout<<"Please input the income:";
            break;
        default:
            throw invalid_argument{
                    "Cannot reach"
            };
    }
}
