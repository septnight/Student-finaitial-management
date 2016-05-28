//
// Created by Jim on 16/5/28.
//
#ifndef FILE_DATA_STORAGE_H
#define FILE_DATA_STORAGE_H

#include "BaseDataStorage.h"
#include <fstream>
#include <vector>

class FileDataStorage : public BaseDataStorage {
public:
	static const int MAX_NAME = 30;
	static const int MAX_TAG = 20;
	FileDataStorage(std::string = "");

	/* open the file for reading-writing */
	virtual bool prepare();
	virtual bool read(Record* rec);
	virtual int write(Record* rec);
	virtual int fetch_all(std::vector<Record*>& v);
	virtual void finish();

private:
	/* in-file record */
	struct RecordEntry {
		int id;
		double amount;
		char time[20];
		char name[30];
		char tag[20];
		int account;
		double income;
	};

	std::fstream fs;
	std::string filename;
	std::vector<int> id_allocation_cache; /* index of empty holes in the data file */
	int nr_entries;

	static void make_entry(Record* rec, RecordEntry* entry);
	static void extract_entry(RecordEntry* entry, Record* rec);

	bool init_cache();
	int allocate_id();
};

#endif
