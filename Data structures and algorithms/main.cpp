#include "SDAfinalproject.h"
#include <QtWidgets/QApplication>
#include "Test.h"
int main(int argc, char *argv[])
{

	Test tests;
	tests.runTests();


	QApplication a(argc, argv);
	SDAfinalproject w{NULL,"data.txt"};
	w.show();
	return a.exec();
}
