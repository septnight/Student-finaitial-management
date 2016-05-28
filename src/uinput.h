//
// Created by 墨林 on 16/5/3.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_UINPUT_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_UINPUT_H
#include <iostream>

class check{
public:

};

class uinput{
    friend class check;
public:
    void propose(int flag) const;
    uinput();
    void outport();
private:
    double Money;
    unsigned int Day;
    unsigned int Month;
    unsigned int Year;
    unsigned int Account;
};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_UINPUT_H
