#include "Controller.h"
#include "Validation.h"


void Controller::add(const std::string& title, const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link)
{
	Duration d{ minutes,seconds };

	Tutorial t{ title,presenter,d,likes,link };
	this->validator.validate(t);
	repo.addTutorial(t);
	UndoAction* action = new UndoAdd{ t, repo };
	this->undoStack.push_back(action);
}
void Controller::remove(const std::string& title)
{
	Tutorial t = repo.findTutorialByTitle(title);
	repo.removeTutorial(t);
	UndoAction* action = new UndoRemove{ t, repo };
	this->undoStack.push_back(action);
}
void Controller::removeTutorialFromWatchList(bool like)
{
	Tutorial t = this->watchList->getCurrentTutorial();
	this->watchList->remove(t);

	UndoActionWatchList* action = new UndoRemoveWatchList{ t, *watchList };
	this->undoWatchListStack.push_back(action);

	if (like == true)
	{
		update(t.getTitle(), t.getTitle(), t.getPresenter(), t.getDuration().getMinutes(), t.getDuration().getSeconds(), t.getLikes() + 1, t.getLink());
	}

}

void Controller::update(const std::string& oldTitle, const std::string& title, const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link)
{
	Tutorial old = repo.findTutorialByTitle(oldTitle);

	Duration d{ minutes,seconds };
	Tutorial t{ title,presenter,d,likes,link };
	this->validator.validate(t);
	repo.updateTutorial(old, t);

}

void Controller::addTutorialToWatchList(const Tutorial& tutorial)
{
	this->watchList->add(tutorial);
	UndoActionWatchList *action = new UndoAddWatchList{ tutorial, *watchList };
	this->undoWatchListStack.push_back(action);
}
void Controller::startWatchList()
{
	this->watchList->play();
}
void Controller::nextTutorialWatchList()
{
	this->watchList->next();
}

void Controller::save_watchlist(const std::string& filename)
{
	if (this->watchList == nullptr)
		return;
	this->watchList->set_filename(filename);
	this->watchList->write_to_file();
}

void Controller::open_watchlist() const
{
	if (this->watchList == nullptr)
		return;
	this->watchList->display_watchlist();
}






void Controller::undo() {

	if (undoStack.size() == 0)
		throw UndoException("Can't undo!");

	UndoAction* action = undoStack.back();
	redoStack.push_back(action);
	action->executeUndo();

	undoStack.pop_back();
	
}

void Controller::redo() {

	if (redoStack.size() == 0)
		throw UndoException("Can't redo! ");

	UndoAction * action = redoStack.back();
	action->executeRedo();

	delete action;
	redoStack.pop_back();
}

void Controller::undoWatchList() {

	if (undoWatchListStack.size() == 0)
		throw UndoException("Can't undo!");

	UndoActionWatchList* action = undoWatchListStack.back();
	redoWatchListStack.push_back(action);
	action->executeUndo();

	undoWatchListStack.pop_back();
}

void Controller::redoWatchList() {

	if (redoWatchListStack.size() == 0)
		throw UndoException("Can't redo! ");

	UndoActionWatchList * action = redoWatchListStack.back();
	action->executeRedo();

	delete action;
	redoWatchListStack.pop_back();
}