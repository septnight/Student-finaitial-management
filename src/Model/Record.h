//
// Created by Jim on 16/5/28.
//
#ifndef RECORD_H
#define RECORD_H

#include "../Localtime.h"
#include "../User.h"

#include <string>

/* representation for single account record */
class Record {
public:
	Record(int = -1, double = 0.0, Localtime = {}, std::string = "", std::string = "", User* = nullptr, double = 0.0);

	int get_id() const;
	void set_id(int id);
	double get_amount() const;
	void set_amount(double amount);
	Localtime get_time() const;
	void set_time(Localtime time);
	std::string get_name() const;
	void set_name(std::string name);
	std::string get_tag() const;
	void set_tag(std::string tag);
	User* get_account() const;
	void set_account(User* user);
	double get_income() const;
	void set_income(double income);

private:
	int id; /* Record id used in data storage */
	double amount;
	Localtime time;
	std::string name;
	std::string tag;
	User* account;
	double income;
};

#endif
