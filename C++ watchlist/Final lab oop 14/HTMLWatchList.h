#pragma once
#include <stdio.h>
#include "FileWatchList.h"

class HTMLWatchlist : public FileWatchList
{
public:
	void write_to_file() override;
	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/

	void display_watchlist() const override;
};

