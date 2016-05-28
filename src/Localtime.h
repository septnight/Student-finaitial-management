//
// Created by 墨林 on 16/5/24.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_LOCALTIME_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_LOCALTIME_H
#include <string>
class Localtime{
public:
    Localtime(int year = 1970, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0);
	virtual ~Localtime();
    void getLocaltime();
    void output(std::ofstream&);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();

	/* conversion between blob and "yyyy/MM/dd hh:mm:ss" string */
	std::string serialize();
	void deserialize(const std::string& s);
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_LOCALTIME_H
