#ifndef DEAL_H
#define DEAL_H

#include<fstream>

using namespace std;
class Deal
{
public:
	void initializeFile(fstream &);
	void inputData(fstream &);
	void listUsers(fstream &);
};

#endif // !DEAL_H\
