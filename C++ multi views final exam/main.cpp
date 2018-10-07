#include "PracticalExam.h"
#include "Programmer.h"
#include "ProgrammerWindow.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include "Tests.h"

using namespace std;

int main(int argc, char *argv[])
{	
	Tests t;
	t.TestAll();
	QApplication a(argc, argv);
	Repository repo{ "Tasks.txt" };
	Controller ctrl{ repo };

	vector<Programmer> pr;
	Programmer p;

	ifstream f("Programmers.txt");
	while (f >> p)
		pr.push_back(p);

	ProgrammerWindow w1{ctrl, pr[0]	};
	ProgrammerWindow w2{ ctrl, pr[1] };
	w1.show();
	w2.show();
	return a.exec();
}
