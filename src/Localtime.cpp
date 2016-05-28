//
// Created by 墨林 on 16/5/24.
//
#include "Localtime.h"
#include <iostream>
#include <fstream>
using namespace std;

Localtime::Localtime() {

}

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