#include"Deal.h"
#include "File.h"
#include<iomanip>
#include<fstream>

using namespace std;

static int counter = 0;
// function to clear file
void Deal::initializeFile(fstream &fRef)
{
	File blankItem;
	// fill file with blank records
	for (int i = 0; i < 100; i++)
		fRef.write(reinterpret_cast< char * >(&blankItem), sizeof(File));
}
// function that receives input
void Deal::inputData(fstream &fRef)
{
	File temp; // temporary user object
			   // temporary variables used to hold user input
	double tmoney;
	string tdate;
	string tname;
	string tlable;
	char goon = 'n';

	while (goon == 'y' || goon == 'Y')
	{
		cout << "Enter the cost money, cost date, cost name, cost lable : " << endl;
		cin >> tmoney;
		cin.ignore(); // ignore the newline on the input stream
		getline(cin, tdate);
		getline(cin, tname);
		getline(cin, tlable);
		temp.setCostMoney(tmoney);
		temp.setCostDate(tdate);
		temp.setCostName(tname);
		temp.setCostLable(tlable);

		cout << "Enter the money you made: " << endl;
		cin >> tmoney;
		temp.setMakeMoney(tmoney);
		// place file position pointer at next write location
		fRef.seekp(temp.getUser() * sizeof(File));
		// write data to file
		fRef.write(reinterpret_cast< char * >(&temp), sizeof(File));
		// ask user for next part number
		cout << "Continue to add the record? ( Y (y) or N (n) ) " << endl;
		cin >> goon;
		counter++;
	}
}
// function that lists users in file
void Deal::listUsers(fstream &fRef)
{
	File temp;

	// display column headings
	cout << setw(39) << "Record Table" << endl
		<< left << setw(13) << "User's ID" << endl
		<< setw(13) << "Cost Money" << left
		<< setw(13) << "Cost Date" << left
		<< setw(13) << "Cost Name" << left
		<< setw(13) << "Cost Labl" << left
		<< setw(13) << "Make Money" << endl;

	// continue until 100 users displayed or end of file reached
	for (int count = 0; count < 100 && !fRef.eof(); count++)
	{
		// set file position pointer and begin reading
		fRef.seekg(count * sizeof(File));
		fRef.read(reinterpret_cast<char *>(&temp), sizeof(File));

		// if user ID is valid, display information
		if (temp.getUser() > 0 && temp.getUser() < 100)
		{
			cout << fixed << showpoint << setprecision(2);
			cout << left << setw(13) << temp.getUser()
				<< left << setw(13) << temp.getCostMoney()
				<< left << setw(13) << temp.getCostDate()
				<< left << setw(13) << temp.getCostName()
				<< left << setw(13) << temp.getCoatLable()
				<< left << setw(13) << temp.getMakeMoney() << endl;
		}
	}
}
