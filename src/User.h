//
// Created by 墨林 on 16/5/24.
//
#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#include <string>
#include <fstream>
#include "Localtime.h"

/* XXX: should be composition, not inheritance */

struct User{
	User();
	std::string Username;
	Localtime createDate;
	std::string Password;
	std::string idCode = "000";
	int getUserNumber();
};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
