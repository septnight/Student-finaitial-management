//
// Created by 墨林 on 16/5/29.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_URECORD_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_URECORD_H

#include "Localtime.h"
struct Urecord{
    std::string Username = "";
    int userNumber = 0;
    Localtime createDate;
    std::string Password;
    bool isEmpty();
};

#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_URECORD_H
