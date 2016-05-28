//
// Created by 墨林 on 16/5/24.
//
#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#include <string>
#include <fstream>
#include "Localtime.h"

/* XXX: should be composition, not inheritance */
class User:Localtime{
public:
    User();
	virtual ~User();
	bool initializeFile();
	std::string getName();
	std::string getPass();
	void setUsername(std::string);
	void setCreatedate(Localtime);
	void setPassword(std::string);
	int getUserNumber();
	void createUser();

	void createUser(std::string name);
private:
	std::string Username = "null";
	Localtime createDate;
	std::string Password;
	std::ifstream loadUser;


    int idCode;
};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
