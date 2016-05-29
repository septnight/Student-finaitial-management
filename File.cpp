#include<iostream>
#include<string>
#include"File.h"
using namespace std;


File::File(double cmoney, string cdate, string cname, string clable, int cuser, double mmoney)
{
	setCostMoney(cmoney);
	setCostDate(cdate);
	setCostName(cname);
	setCostLable(clable);
	setUser(cuser);
	setMakeMoney(mmoney);
}

void File::setCostMoney(double cmoney)
{
	costMoney = cmoney;
}
double File::getCostMoney() const
{
	return costMoney;
}

void File::setCostDate(string cdate)
{
	int length = cdate.size();
	length = (length < SIZE ? length : SIZE - 1);
	cdate.copy(costDate, length);
	costDate[length] = '\0';
}
string File::getCostDate() const
{
	return costDate;
}

void File::setCostName(string cname)
{
	int length = cname.size();
	length = (length < SIZE ? length : SIZE - 1);
	cname.copy(costName, length);
	costName[length] = '\0';
}
string File::getCostName() const
{
	return costName;
}

void File::setCostLable(string clable)
{
	int length = clable.size();
	length = (length < SIZE ? length : SIZE - 1);
	clable.copy(costLable, length);
	costLable[length] = '\0';
}
string File::getCoatLable() const
{
	return costLable;

}
/*
void File::setUser(int cuser)
{
	user = cuser;
}
int File::getUser() const
{
	return user;
}*/

void File::setMakeMoney(double mmoney)
{
	makeMoney = mmoney;
}
double File::getMakeMoney() const
{
	return makeMoney;
}