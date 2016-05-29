//
// Created by 墨林 on 16/5/28.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_ACTION_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_ACTION_H
#include "User.h"
#include "Localtime.h"
#include <fstream>
class Action{
public:
    Action();
    User demo;
    void userLogin();
    void startApp();
private:
    std::ifstream loadUser;
};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_ACTION_H
