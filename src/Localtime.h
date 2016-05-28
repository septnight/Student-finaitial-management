//
// Created by 墨林 on 16/5/24.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_LOCALTIME_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_LOCALTIME_H
#include <string>
class Localtime{
public:
    Localtime();
    void getLocaltime();
    void output(std::ofstream&);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_LOCALTIME_H
