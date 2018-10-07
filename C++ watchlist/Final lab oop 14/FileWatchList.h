#pragma once
#include <stdio.h>
#include "WatchList.h"

class FileWatchList : public WatchList
{
protected:
	std::string filename;
public:
	FileWatchList();
	virtual ~FileWatchList() {}
	void set_filename(const std::string& filename);
	virtual void write_to_file() = 0;
	virtual void display_watchlist() const = 0;
};
