//
// Created by д╚аж on 16/5/28.
//

#ifndef ACTION_H
#define ACTION_H
#include "User.h"
#include "Localtime.h"
#include <fstream>

class Action {
public:
	User demo;
	void userLogin();
	void startApp();
	void createUser();
	void createUser(std::string);
	bool initializeFile();
	void saveSet();
private:
	std::ifstream loadUser;
};
#endif //ACTION_H
