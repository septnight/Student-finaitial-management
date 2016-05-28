//
// Created by Jim on 16/5/28.
//
#include "FileDataStorage.h"
#include <iostream>

using namespace std;

FileDataStorage::FileDataStorage(string filename) : filename(filename)
{
	
}

bool FileDataStorage::init_cache()
{
	RecordEntry entry;

	if (!fs.is_open()) return false;

	fs.seekg(0);
	id_allocation_cache.clear();
	nr_entries = 0;
	while (!fs.eof()) {
		fs.read(reinterpret_cast<char*>(&entry), sizeof(RecordEntry));
		streamsize count = fs.gcount();
		if (!count) break;
		if (count != sizeof(RecordEntry)) return false; /* corrupted */

		if (entry.id == -1) {
			id_allocation_cache.push_back(nr_entries);
		}
		nr_entries++;
	}

	fs.clear(ios::eofbit);
	return true;
}

int FileDataStorage::allocate_id()
{
	int index;
	if (id_allocation_cache.size()) {
		index = id_allocation_cache.back();
		id_allocation_cache.pop_back();
	} else {
		index = nr_entries++;
	}

	return index;
}

bool FileDataStorage::prepare()
{
	fs.open(filename, ios::in | ios::out | ios::binary);

	if (!fs) {
		fs.open(filename, ios::out | ios::binary);
		fs.close();

		fs.open(filename, ios::in | ios::out | ios::binary);
		if (!fs) return false;
	}

	return init_cache();
}

bool FileDataStorage::read(Record* rec)
{
	int id = rec->get_id();
	if (id < 0 || id >= nr_entries) {
		return false;
	}

	RecordEntry entry;
	fs.seekg(id * sizeof(entry));
	fs.read(reinterpret_cast<char*>(&entry), sizeof(entry));
	if (fs.gcount() != sizeof(entry)) return false;

	extract_entry(&entry, rec);
	rec->set_id(id);
	return true;
}

int FileDataStorage::write(Record* rec)
{
	if (!fs.is_open()) return -1;

	if (rec->get_id() == -1) {
		rec->set_id(allocate_id());
	}
	
	if (rec->get_id() >= nr_entries) {
		return -1;
	}

	RecordEntry entry;
	make_entry(rec, &entry);
	fs.seekg(rec->get_id() * sizeof(entry));
	fs.write(reinterpret_cast<char*>(&entry), sizeof(entry));

	int bit = fs.fail();

	return rec->get_id();
}

static void str2pchar(const string& str, char* p, int max_size)
{
	for (streamsize i = 0; i < str.length() && i < max_size; i++) {
		*p++ = str[(unsigned int)i];
	}
	*p = 0;
}

void FileDataStorage::make_entry(Record* rec, RecordEntry* entry)
{
	entry->id = rec->get_id();
	entry->amount = rec->get_amount();
	str2pchar(rec->get_time().serialize(), entry->time, sizeof(entry->time));
	str2pchar(rec->get_name(), entry->name, MAX_NAME);
	str2pchar(rec->get_tag(), entry->tag, MAX_TAG);
	if (rec->get_account()) {
		entry->account = rec->get_account()->getUserNumber();
	}
	else {
		entry->account = -1;
	}
	entry->income = rec->get_income();
}

void FileDataStorage::extract_entry(RecordEntry* entry, Record* rec)
{
	rec->set_id(entry->id);
	rec->set_amount(entry->amount);
	rec->set_name(string(entry->name));
	rec->set_tag(string(entry->tag));
	Localtime time;
	time.deserialize(string(entry->time));
	rec->set_time(time);
	rec->set_income(entry->income);
}

int FileDataStorage::fetch_all(vector<Record*>& v)
{
	RecordEntry entry;

	if (!fs.is_open()) return false;

	v.clear();
	fs.seekg(0);
	while (!fs.eof()) {
		fs.read(reinterpret_cast<char*>(&entry), sizeof(RecordEntry));
		streamsize count = fs.gcount();
		if (!count) break;
		if (count != sizeof(RecordEntry)) return -1; /* corrupted */

		if (entry.id != -1) {
			Record* rec = new Record();
			extract_entry(&entry, rec);
			v.push_back(rec);
		}
	}

	fs.clear(ios::eofbit);
	return v.size();
}

void FileDataStorage::finish()
{
	if (fs.is_open()) {
		fs.close();
	}
}
