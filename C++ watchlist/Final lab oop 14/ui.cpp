#include "ui.h"
#include <string>
#include "RepositoryExceptions.h"
using namespace std;
int readInteger();
void ui::printMenu()
{
	cout << "\n1. Go as administrator\n";
	cout << "2. Go as user\n";
	cout << "\n Please insert a command: ";

}
void ui::printAdministratorMenu()
{
	cout << "\n1. Add a new Tutorial";
	cout << "\n2. Print all tutorials";
	cout << "\n3. Remove a tutorial";
	cout << "\n4. Update a tutorial";
	cout << "\n\n Please insert a command: ";
}
void ui::ui_printAllTutorials()
{
	bool da = 0;
	for (int i = 0; i < ctrl.getRepo().getTutorials().size(); i++)
	{
		cout << ctrl.getRepo().getTutorials()[i].getTitle() << " "
			<< ctrl.getRepo().getTutorials()[i].getPresenter() << " "
			<< ctrl.getRepo().getTutorials()[i].getLikes() << " \n";
		da = 1;
	}
	if (da == 0)
		cout << "NO ITEMS!";
}
void ui::ui_remove()
{
	std::string title;
	cin.ignore(1000, '\n');
	cout << "Please insert the title to be removed: ";
	getline(cin, title);
	try
	{
		ctrl.remove(title);
		cout << "Item removed!";
	}
	catch (TutorialException& e)
	{
		for (auto m : e.get_errors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << '\n';
	}
	catch (FileException& f)
	{
		cout << f.what() << '\n';
	}


}
void ui::ui_update()
{
	std::string title1, title, presenter, link;
	int likes, minutes, seconds;
	cin.ignore(1000, '\n');
	cout << "Please insert the title to be updated: ";
	getline(cin, title1);
	cout << "Now insert new data: \n";
	cout << "Please insert the title: ";
	getline(cin, title);
	cout << "Please insert the presenter: ";
	getline(cin, presenter);
	cout << "Please insert the link:  ";
	getline(cin, link);
	cout << "Please insert the number of likes: ";
	likes = readInteger();
	cout << "Please insert the minutes: ";
	minutes = readInteger();
	cout << "Please insert the seconds: ";
	seconds = readInteger();
	if (minutes < 61 && minutes>0 && seconds < 61 && seconds>0)
	{

		try
		{
			ctrl.update(title1, title, presenter, (double)minutes, (double)seconds, likes, link);
			cout << "Item updated!";
		}
		catch (TutorialException& e)
		{
			for (auto m : e.get_errors())
				cout << m;
		}
		catch (RepositoryException& e)
		{
			cout << e.what() << '\n';
		}
		catch (FileException& f)
		{
			cout << f.what() << '\n';
		}

	}
	else
		cout << "INVALID MINUTES OR SECONDS!";
}
void ui::ui_add()
{
	std::string title, presenter, link;
	int likes, minutes, seconds;
	cin.ignore(1000, '\n');
	cout << "Please insert the title: ";
	getline(cin, title);
	cout << "Please insert the presenter: ";
	getline(cin, presenter);
	cout << "Please insert the link:  ";
	getline(cin, link);
	cout << "Please insert the number of likes: ";
	likes = readInteger();
	cout << "Please insert the minutes: ";
	minutes = readInteger();
	cout << "Please insert the seconds: ";
	seconds = readInteger();

	try
	{
		ctrl.add(title, presenter, (double)minutes, (double)seconds, likes, link);
		cout << "Item added!";
	}
	catch (TutorialException& e)
	{
		for (auto m : e.get_errors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << '\n';
	}
	catch (FileException& f)
	{
		cout << f.what() << '\n';
	}
}
void ui::administrator()
{
	int option;
	while (1)
	{
		printAdministratorMenu();
		option = readInteger();
		switch (option) {
		case 1:
			ui_add();
			break;
		case 2:
			ui_printAllTutorials();
			break;
		case 3:
			ui_remove();
			break;
		case 4:
			ui_update();
			break;
		default:
			cout << "Invalid command!";
			break;
		}

	}
}
void ui::ui_printTutorialsByPresenter()
{
	bool da = 0;
	std::string presenter, like = "";
	cin.ignore(1000, '\n');
	cout << "Please insert the presenter: ";
	getline(cin, presenter);
	Tutorial t{};

	if (presenter != "")
		for (int i = 0; i < ctrl.getRepo().getTutorials().size(); i++)
		{
			if (ctrl.getRepo().getTutorials()[i].getPresenter() == presenter)
			{
				t = ctrl.getRepo().getTutorials()[i];
				cout << "Title: " << ctrl.getRepo().getTutorials()[i].getTitle() << "  Presenter: "
					<< ctrl.getRepo().getTutorials()[i].getPresenter() << " Duration: "
					<< ctrl.getRepo().getTutorials()[i].getDuration().getMinutes() << ":"
					<< ctrl.getRepo().getTutorials()[i].getDuration().getSeconds() << " Likes: "
					<< ctrl.getRepo().getTutorials()[i].getLikes() << " \n";
				da = 1;
			}

		}
	else
		for (int i = 0; i < ctrl.getRepo().getTutorials().size(); i++)
		{

			t = ctrl.getRepo().getTutorials()[i];
			cout << "Title: " << ctrl.getRepo().getTutorials()[i].getTitle() << "  Presenter: "
				<< ctrl.getRepo().getTutorials()[i].getPresenter() << " Duration: "
				<< ctrl.getRepo().getTutorials()[i].getDuration().getMinutes() << ":"
				<< ctrl.getRepo().getTutorials()[i].getDuration().getSeconds() << " Likes: "
				<< ctrl.getRepo().getTutorials()[i].getLikes() << " \n";
			da = 1;
		}
	while (like != "0" && da == 1)
	{

		if (presenter != "")
			for (int i = 0; i < ctrl.getRepo().getTutorials().size() && like != "0"; i++)
			{
				if (ctrl.getRepo().getTutorials()[i].getPresenter() == presenter)
				{
					t = ctrl.getRepo().getTutorials()[i];
					da = 1;
					like = play(t);
				}

			}
		else
			for (int i = 0; i < ctrl.getRepo().getTutorials().size() && like != "0"; i++)
			{

				t = ctrl.getRepo().getTutorials()[i];
				da = 1;
				like = play(t);
			}

		if (da == 0)
		{
			cout << "NO ITEMS!";
			like = "0";
		}


	}

}
void ui::ui_printWatchList()
{
	bool da = 0;
	for (int i = 0; i < ctrl.getWatchList()->getTutorials().size(); i++)
	{
		cout << "Title: " << ctrl.getWatchList()->getTutorials()[i].getTitle() << "  Presenter: "
			<< ctrl.getWatchList()->getTutorials()[i].getPresenter() << " Duration: "
			<< ctrl.getWatchList()->getTutorials()[i].getDuration().getMinutes() << ":"
			<< ctrl.getWatchList()->getTutorials()[i].getDuration().getSeconds() << " Likes: "
			<< ctrl.getWatchList()->getTutorials()[i].getLikes() << " \n";
		da = 1;
	}
	if (da == 0)
	{
		cout << "\nNO ITEMS!\n";
	}
}

std::string ui::play(Tutorial& t)
{
	std::string like = "";
	cout << "\nCurrent tutorial: Title: " << t.getTitle() << "  Presenter: "
		<< t.getPresenter() << " Duration: "
		<< t.getDuration().getMinutes() << ":"
		<< t.getDuration().getSeconds() << " Likes: "
		<< t.getLikes() << " \n";
	t.accessLink();
	cout << "Do you like the tutorial?(insert yes or no or 0 TO STOP): ";
	getline(cin, like);
	if (like == "yes")
	{
		ctrl.addTutorialToWatchList(t);
		cout << "\nTutorial added to playlist!\n";
	}
	else if (like != "0")
	{
		cout << "\n Too bad you don't like it, here is another one: \n";
	}
	return like;
}
void ui::printUserMenu()
{
	cout << "\n1. See all the tutorials from a given presenter";
	cout << "\n2. Print watch list";
	cout << "\n3. Remove a tutorial from watchList";
	cout << "\n4. Save watchList";
	cout << "\n5. See saved watchlist";
	cout << "\n\n Please insert a command: ";
}
void ui::ui_removeTutorialFromWatchList()
{
	cin.ignore(1000, '\n');
	if (ctrl.getWatchList()->isEmpty() == 1)
		cout << "\nWatch list is empty!\n";
	else
	{
		cout << "Do you really want to remove the tutorial?(yes or no)";
		std::string remove = "";
		getline(cin, remove);

		if (remove == "yes")
		{
			cout << "Do you want to like that tutorial?(yes or no)";
			getline(cin, remove);
			if (remove == "yes")
				ctrl.removeTutorialFromWatchList(true);
			else
				ctrl.removeTutorialFromWatchList(false);
		}
	}


}

void ui::save_watchlist_to_file()
{
	std::string filename;
	cin.ignore(1000, '\n');

	cout << "Filename: ";
	getline(cin, filename);

	try
	{
		ctrl.save_watchlist(filename);
		if (ctrl.getWatchList() == nullptr)
		{
			cout << "Watchlist can't be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}


void ui::user()
{
	int option;
	while (1)
	{
		printUserMenu();
		option = readInteger();
		switch (option) {
		case 1:
			ui_printTutorialsByPresenter();
			break;
		case 2:
			ui_printWatchList();
			break;
		case 3:
			ui_removeTutorialFromWatchList();
			break;
		case 4:
			save_watchlist_to_file();
			break;
		case 5:
			ctrl.open_watchlist();
			break;
		default:
			cout << "Invalid command!";
			break;
		}
	}
}
int readInteger()
{
	int x = 0;
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	return x;
}

void ui::run()
{
	int option;


	while (1)
	{
		printMenu();
		option = readInteger();
		if (option == 1)
			administrator();
		else if (option == 2)
			user();
		else
			cout << "Not a valid command!";

	}

}
