#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <qstring.h>
#include <qtextedit.h> 
#include "Tests.h"
#include "ui.h"
#include <vector>
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "Finallaboop14.h"
#include "FilePickClass.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FilePickClass f{ NULL };
	f.show();



	Repository repo{ "data.txt" };
	FileWatchList* p;
	return a.exec();
}
