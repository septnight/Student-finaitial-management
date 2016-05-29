//
// Created by 墨林 on 16/5/28.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_SETTING_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_SETTING_H
#include "../User.h"

class Setting:public User{
public:
    Setting();
    Setting(User);
    void importUser();
    void saveSet();
    void saveNewSet();
private:
    int numberofUser;

};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_SETTING_H
