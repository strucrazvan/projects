#include "HTMLWatchList.h"
#include "RepositoryExceptions.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

void HTMLWatchlist::write_to_file()
{

	ofstream f(this->filename);
	if (!f.is_open())
		throw FileException("HTML file for watchlist can't be opened! \n");
	f << "<!DOCTYPE html>" << endl;
	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Watchlist</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<table border=\"1\", style=\"width:100%\">" << endl;
	f << "<tr style=\"background-color:powderblue;text-align:center;font-size:120%;\">" << endl;
	f << "<td>" << "<b>Title</b>" << "</td>" << endl;
	f << "<td>" << "<b>Presenter</b>" << "</td>" << endl;
	f << "<td>" << "<b>Duration</b>" << "</td>" << endl;
	f << "<td>" << "<b>Likes</b>" << "</td>" << endl;
	f << "<td>" << "<b>Link</b>" << "</td>" << endl;
	f << "</tr>" << endl;
	for (auto m : this->tutorials)
	{
		f << "<tr style=\"text-align:center;\">" << endl;
		f << "<td>" << m.getTitle() << "</td>" << endl;
		f << "<td>" << m.getPresenter() << "</td>" << endl;
		f << "<td>" << m.getDuration().getMinutes() << ":" << m.getDuration().getSeconds() << "</td>" << endl;
		f << "<td>" << m.getLikes() << "</td>" << endl;
		f << "<td>" << "<a href = \" " << m.getLink() << "\">Link</a>" << "</td>" << endl;
		f << "</tr>" << endl;
	}
	f.close();
}

void HTMLWatchlist::display_watchlist() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}

