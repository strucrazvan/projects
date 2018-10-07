#include "CSVWatchList.h"
#include <Windows.h>
#include <shellapi.h>

void CSVWatchList::write_to_file()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw FileException("CSV file for watchlist can't be opened! \n");
	f << "Title,";
	f << "Presenter,";
	f << "Duration,";
	f << "Likes,";
	f << "Link" << endl;
	for (auto m : this->tutorials)
		f << m;
	f.close();
}

void CSVWatchList::display_watchlist() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}


