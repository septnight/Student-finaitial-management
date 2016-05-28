//
// Created by 墨林 on 16/5/24.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#include <string>
#include <fstream>
#include "Localtime.h"

class User:Localtime{
public:
    User();
    bool userLogin();
    bool haveLogon();
    void createUser();
    void organize();
private:
    std::string Username;
    Localtime createDate;
    std::string Password;
    std::ifstream loadUser;

};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
