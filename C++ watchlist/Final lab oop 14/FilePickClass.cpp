#include "FilePickClass.h"
#include "Controller.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "Finallaboop14.h"
FilePickClass::FilePickClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.csvButton, &QPushButton::clicked, this, [this]()
	{

		CSV();
		close();
	});
	QObject::connect(ui.htmlButton, &QPushButton::clicked, this, [this]()
	{

		HTML();
		close();
	});

}

void FilePickClass::CSV()
{
	Repository repo{ "data.txt" };
	FileWatchList* p = new CSVWatchList;
	Controller ctrl{ repo ,p };
	Finallaboop14 *f = new Finallaboop14(NULL, ctrl);
	f->show();
}

void FilePickClass::HTML()
{
	Repository repo{ "data.txt" };
	FileWatchList* p = new HTMLWatchlist;
	Controller ctrl{ repo ,p };
	Finallaboop14 *f = new Finallaboop14(NULL, ctrl);
	f->show();
}

FilePickClass::~FilePickClass()
{
}
