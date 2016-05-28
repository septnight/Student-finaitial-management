//
// Created by Jim on 16/5/28.
//
#include "Record.h"

using std::string;

Record::Record(int id, double amount, Localtime time, string name, string tag, User* account, double income)
{
	set_id(id);
	set_amount(amount);
	set_time(time);
	set_name(name);
	set_tag(tag);
	set_account(account);
	set_income(income);
}

int Record::get_id() const
{
	return id;
}

void Record::set_id(int id)
{
	this->id = id;
}

double Record::get_amount() const
{
	return amount;
}

void Record::set_amount(double amount)
{
	this->amount = amount;
}

Localtime Record::get_time() const
{
	return time;
}

void Record::set_time(Localtime time)
{
	this->time = time;
}
std::string Record::get_name() const
{
	return name;
}
void Record::set_name(std::string name)
{
	this->name = name;
}
std::string Record::get_tag() const
{
	return tag;
}
void Record::set_tag(std::string tag) 
{
	this->tag = tag;
}
User* Record::get_account() const
{
	return account;
}
void Record::set_account(User* account)
{
	this->account = account;
}
double Record::get_income() const
{
	return income;
}
void Record::set_income(double income)
{
	this->income = income;
}