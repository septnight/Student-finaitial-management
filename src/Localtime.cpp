//
// Created by 墨林 on 16/5/24.
//
#include "Localtime.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

using namespace std;

Localtime::Localtime(int year, int month, int day, int hour, int minute, int second) 
	: year(year), month(month), day(day), hour(hour), minute(minute), second(second) {

}
int Localtime::getDay() {return day;}
int Localtime::getHour() {return hour;}
int Localtime::getMinute(){return minute;}
int Localtime::getYear(){return year;}
int Localtime::getMonth(){return month;}
int Localtime::getSecond() { return second; }

void Localtime::getLocaltime() {
    time_t now_time=time(0);
    struct tm * timeinfo;
    timeinfo = localtime ( &now_time );
    cout<<asctime (timeinfo);

    year = 1900+timeinfo->tm_year; //年
    month = 1+timeinfo->tm_mon;//月
    day = timeinfo->tm_mday;   //日
    hour = timeinfo->tm_hour;  //时
    minute = timeinfo->tm_min; //分
    second = timeinfo->tm_sec; //秒
}
void Localtime::output(std::ofstream &output) {
    output<<year<<"-"<<month<<
    "-"<<day<<" "<<hour<<":"<<minute
    <<":"<<second<<endl;
}

string Localtime::serialize()
{
	char buf[100];
	sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
	return string(buf);
}

void Localtime::deserialize(const string& s)
{
	sscanf(s.c_str(), "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
}
Localtime::~Localtime() {
    cerr<<"Localtime:"<<this<<endl;
}


