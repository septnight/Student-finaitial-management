//
// Created by Jim on 16/5/28.
//
#ifndef BASE_DATA_STORAGE_H
#define BASE_DATA_STORAGE_H

#include "Record.h"
#include <vector>

class BaseDataStorage {
public:
	virtual ~BaseDataStorage() { };
	
	/* prepare the data storage for access */
	virtual bool prepare() = 0;
	/* read the specified record, rec->id must be set to the correct slot into the data storage */
	virtual bool read(Record* rec) = 0;
	/* write the record, if rec->id == -1 then a free slot will be automatically assigned to the record,
	 * otherwise the record is written to the slot given by its id */
	virtual int write(Record* rec) = 0;
	/* fetch all records from the data storage */
	virtual int fetch_all(std::vector<Record*>& v) = 0;
	/* cleanup */
	virtual void finish() = 0;
};

#endif
