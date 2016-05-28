#ifndef FILE_H
#define FILE_H
#include<string>
#include<iostream>
using namespace std;

class File
{
public:
	static const int SIZE = 100;
	File(double = 0.0, string = " ", string = " ", string = " ", int = 0, double = 0.0);

	void setCostMoney(double);
	double getCostMoney() const;
	void setCostDate(string);
	string getCostDate() const;
	void setCostName(string);
	string getCostName() const;
	void setCostLable(string);
	string getCoatLable() const;
	void setUser(int);
	int getUser() const;
	void setMakeMoney(double);
	double getMakeMoney() const;
private:
	double costMoney;
	char costDate[SIZE];
	char costName[SIZE];
	char costLable[SIZE];
	int user;
	double makeMoney;
};

#endif


