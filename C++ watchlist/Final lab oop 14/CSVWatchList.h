#pragma once
#include <stdio.h>
#include "FileWatchList.h"
#include "RepositoryExceptions.h"
#include <stdio.h>
#include <fstream>
using namespace std;

class CSVWatchList : public FileWatchList
{
public:
	CSVWatchList() {};
	void write_to_file() override;
	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/

	void display_watchlist() const override;
};
