#include "Finallaboop14.h"
#include "Controller.h"
#include "FilePickClass.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
Finallaboop14::Finallaboop14(QWidget *parent, Controller& ctrl)
	: QMainWindow(parent), ctrl{ ctrl }
{
	ui.setupUi(this);
	initTutorialList();
	//add button connection
	QObject::connect(ui.addButton, &QPushButton::clicked, this, [this]() { addButtonEventHandler();	});

	//remove button connection
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, [this]() { removeButtonEventHandler();	});

	//update button connection
	QObject::connect(ui.updateButton, &QPushButton::clicked, this, [this]() { updateButtonEventHandler();	});

	//filter button connection
	QObject::connect(ui.filterButton, &QPushButton::clicked, this, [this]() { filterButtonEventHandler();	});

	//add to watchlist button connection
	QObject::connect(ui.addToWatchListButton, &QPushButton::clicked, this, [this]() { addToWatchListButtonEventHandler();	});

	//play button connection
	QObject::connect(ui.playButton, &QPushButton::clicked, this, [this]() { playButtonEventHandler();	});

	//next button event handler
	QObject::connect(ui.nextButton, &QPushButton::clicked, this, [this]() { nextButtonEventHandler();	});

	//print button event handler
	QObject::connect(ui.printFileButton, &QPushButton::clicked, this, [this]() { printFileButtonEventHandler();	});
	//combobox
	QObject::connect(ui.showComboBox, QOverload<const QString&>::of(&QComboBox::currentTextChanged),
		[=](const QString &text) {if (text == "Detailed")initTutorialList(); else list_short(); });
	QObject::connect(ui.undoButton, &QPushButton::clicked, this, [this]() {undoButtonEventHandler();	});
	QObject::connect(ui.redoButton, &QPushButton::clicked, this, [this]() {redoButtonEventHandler();	});
	QObject::connect(ui.undoWatchListButton, &QPushButton::clicked, this, [this]() {undoWatchListButtonEventHandler();	});
	QObject::connect(ui.redoWatchListButton, &QPushButton::clicked, this, [this]() {redoWatchListButtonEventHandler();	});



}
void Finallaboop14::initWatchList()
{
	ui.watchList->clear();
	for (auto elem : ctrl.getWatchList()->getTutorials())
	{

		std::string x = elem.getTitle();
		x += ", ";
		x += elem.getPresenter();
		x += ", ";
		x += to_string((int)elem.getDuration().getMinutes());
		x += ":";
		x += to_string((int)elem.getDuration().getSeconds());
		x += ", ";
		x += to_string((int)elem.getLikes());
		x += ", ";
		x += elem.getLink();
		ui.tutorialsList->addItem(x.c_str());
	}
}
void Finallaboop14::initTutorialList()
{
	ui.tutorialsList->clear();
	for (auto elem : ctrl.getRepo().getTutorials())
	{

		std::string x = elem.getTitle();
		x += ", ";
		x += elem.getPresenter();
		x += ", ";
		x += to_string((int)elem.getDuration().getMinutes());
		x += ":";
		x += to_string((int)elem.getDuration().getSeconds());
		x += ", ";
		x += to_string((int)elem.getLikes());
		x += ", ";
		x += elem.getLink();
		ui.tutorialsList->addItem(x.c_str());
	}
}

void Finallaboop14::addButtonEventHandler()
{
	string title = ui.titleLineEdit->text().toStdString();
	string presenter = ui.presenterLineEdit->text().toStdString();
	int minutes = ui.minutesLineEdit->text().toInt();
	int seconds = ui.secondsLineEdit->text().toInt();
	int likes = ui.likesLineEdit->text().toInt();
	string link = ui.linkLineEdit->text().toStdString();
	try
	{
		ctrl.add(title, presenter, (double)minutes, (double)seconds, likes, link);
		initTutorialList();
		ui.errorLabel->setText("ITEM ADDED");
	}
	catch (TutorialException& e)
	{
		string er;
		for (auto m : e.get_errors())
			er += m;
		ui.errorLabel->setText(er.c_str());
		//to cout er
	}
	catch (RepositoryException& e)
	{
		ui.errorLabel->setText(e.what());
		//cout << e.what() << '\n';
	}
	catch (FileException& f)
	{
		ui.errorLabel->setText(f.what());
		//cout << f.what() << '\n';
	}
}

void Finallaboop14::removeButtonEventHandler()
{
	string title = ui.titleLineEdit->text().toStdString();
	try
	{
		ctrl.remove(title);
		initTutorialList();
		ui.errorLabel->setText("Item removed!");
	}
	catch (TutorialException& e)
	{
		string er;
		for (auto m : e.get_errors())
			er += m;
		ui.errorLabel->setText(er.c_str());
		//to cout er
	}
	catch (RepositoryException& e)
	{
		ui.errorLabel->setText(e.what());
		//cout << e.what() << '\n';
	}
	catch (FileException& f)
	{
		ui.errorLabel->setText(f.what());
		//cout << f.what() << '\n';
	}
}

void Finallaboop14::updateButtonEventHandler()
{
	string oldTitle = ui.titleUpdateLineEdit->text().toStdString();
	string title = ui.titleLineEdit->text().toStdString();
	string presenter = ui.presenterLineEdit->text().toStdString();
	int minutes = ui.minutesLineEdit->text().toInt();
	int seconds = ui.secondsLineEdit->text().toInt();
	int likes = ui.likesLineEdit->text().toInt();
	string link = ui.linkLineEdit->text().toStdString();
	try
	{
		ctrl.update(oldTitle, title, presenter, (double)minutes, (double)seconds, likes, link);
		initTutorialList();
		ui.errorLabel->setText("Item updated!");
	}
	catch (TutorialException& e)
	{
		string er;
		for (auto m : e.get_errors())
			er += m;
		ui.errorLabel->setText(er.c_str());
		//to cout er
	}
	catch (RepositoryException& e)
	{
		ui.errorLabel->setText(e.what());
		//cout << e.what() << '\n';
	}
	catch (FileException& f)
	{
		ui.errorLabel->setText(f.what());
		//cout << f.what() << '\n';
	}
}

void Finallaboop14::filterButtonEventHandler()
{
	string presenter = ui.presenterFilterLineEdit->text().toStdString();
	Tutorial elem{};
	ui.tutorialsList->clear();
	if (presenter != "")
		for (int i = 0; i < ctrl.getRepo().getTutorials().size(); i++)
		{
			if (ctrl.getRepo().getTutorials()[i].getPresenter() == presenter)
			{
				elem = ctrl.getRepo().getTutorials()[i];
				std::string x = elem.getTitle();
				x += ", ";
				x += elem.getPresenter();
				x += ", ";
				x += to_string((int)elem.getDuration().getMinutes());
				x += ":";
				x += to_string((int)elem.getDuration().getSeconds());
				x += ", ";
				x += to_string((int)elem.getLikes());
				x += ", ";
				x += elem.getLink();
				ui.tutorialsList->addItem(x.c_str());
			}

		}
	else
		initTutorialList();
	ui.errorLabel->setText("Filter done");
}

void Finallaboop14::addToWatchListButtonEventHandler()
{


	ui.watchList->addItem(ui.tutorialsList->currentItem()->text().toStdString().c_str());

	std::string title = ui.tutorialsList->currentItem()->text().toStdString().substr(0, ui.tutorialsList->currentItem()->text().toStdString().find(","));

	ctrl.addTutorialToWatchList(ctrl.getRepo().findTutorialByTitle(title));
	if (ui.watchList->count() == 1)
		ui.watchList->item(0)->setSelected(true);
	ui.errorLabel->setText("Tutorial added to watchList");

}

void Finallaboop14::playButtonEventHandler()
{
	if (ui.watchList->count())
	{
		ctrl.getRepo().findTutorialByTitle(ui.tutorialsList->currentItem()->text().toStdString().substr(0, ui.tutorialsList->currentItem()->text().toStdString().find(","))).accessLink();
		ui.errorLabel->setText("Tutorial is playing!");

	}
}

void Finallaboop14::nextButtonEventHandler()
{
	for (int i = 0; i < ui.watchList->count(); i++)
		if (ui.watchList->item(i)->isSelected() != 0)
		{
			if (i == ui.watchList->count() - 1)
				ui.watchList->item(0)->setSelected(true);
			else
				ui.watchList->item(i + 1)->setSelected(true);
			break;
		}
}

void Finallaboop14::printFileButtonEventHandler()
{
	string fileName = ui.fileNameLineEdit->text().toStdString();

	try
	{
		ctrl.save_watchlist(fileName);
		ctrl.open_watchlist();
		ui.errorLabel->setText("ITEMS SAVED IN THE FILE!");
	}
	catch (FileException& e)
	{
		ui.errorLabel->setText(e.what());
	}
}

void Finallaboop14::list_short()
{
	ui.tutorialsList->clear();
	for (auto elem : ctrl.getRepo().getTutorials())
	{

		std::string x = elem.getTitle();
		ui.tutorialsList->addItem(x.c_str());
	}
}

void Finallaboop14::undoButtonEventHandler()
{
	try
	{
		ctrl.undo();
		ui.errorLabel->setText("UNDO DONE!");
		initTutorialList();

	}
	catch (UndoException& e)
	{
		ui.errorLabel->setText(e.what());
	}
	
}

void Finallaboop14::redoButtonEventHandler()
{
	try
	{
		ctrl.redo();
		ui.errorLabel->setText("REDO DONE!");
		initTutorialList();
	}
	catch (UndoException& e)
	{
		ui.errorLabel->setText(e.what());
	}
}

void Finallaboop14::undoWatchListButtonEventHandler()
{
	try
	{
		ctrl.undoWatchList();
		ui.errorLabel->setText("UNDO DONE!");
		initWatchList();

	}
	catch (UndoException& e)
	{
		ui.errorLabel->setText(e.what());
	}
}

void Finallaboop14::redoWatchListButtonEventHandler()
{
	try
	{
		ctrl.redoWatchList();
		ui.errorLabel->setText("REDO DONE!");
		initWatchList();
	}
	catch (UndoException& e)
	{
		ui.errorLabel->setText(e.what());
	}
}





