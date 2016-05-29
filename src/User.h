//
// Created by 墨林 on 16/5/24.
//

#ifndef STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#define STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H
#include <string>
#include <fstream>
#include <vector>
#include "Localtime.h"
#include "Urecord.h"

/* XXX: should be composition, not inheritance */
class User{
public:
	User();
	User(std::string = "");
	int getUserNumber();
	bool prepare();
	bool read(std::string);
	int write(Urecord*);
	int fetch_all(std::vector<Urecord*>& u);
	void finish();

	/* TODO: 添加以user number查找user的方法 */
	int getUserNumber() const { return userNumber; }
private:
	std::string Username = "null";
	Localtime createDate;
	std::string Password;
	std::ifstream loadUser;
	int userNumber = 1;
	std::string idCode;
	Urecord data;
	std::string filename;
	std::fstream fs;
	bool init_cache();
	int id;
	static void extract_entry(Urecord* from, Urecord* to);
};
#endif //STUDENT_PERSONAL_FINANCIAL_MANAGEMENT_USERSYSTEM_H