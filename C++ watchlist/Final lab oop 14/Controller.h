#pragma once
#include "Repository.h"
#include "RepositoryExceptions.h"
#include "WatchList.h"
#include "Validation.h"
#include "FileWatchList.h"
#include "Undo.h"
#include "undowatchlist.h"
class Controller
{
private:
	Repository repo;
	FileWatchList* watchList;
	TutorialValidator validator;
	std::vector<UndoAction *> undoStack;
	std::vector<UndoAction *> redoStack;
	std::vector<UndoActionWatchList *> undoWatchListStack;
	std::vector<UndoActionWatchList *> redoWatchListStack;

public:
	Controller(const Repository& r, FileWatchList* w) : repo{ r }, watchList(w) {}
	Repository getRepo() { return repo; }
	WatchList* getWatchList() { return watchList; }
	void add(const std::string& title, const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link);
	void remove(const std::string& title);
	void update(const std::string& oldTitle, const std::string& title, const std::string& presenter, const double& minutes, const double& seconds, const int& likes, const std::string& link);
	void addTutorialToWatchList(const Tutorial& tutorial);
	void removeTutorialFromWatchList(bool like);
	void startWatchList();
	void nextTutorialWatchList();
	void save_watchlist(const std::string& filename);
	void open_watchlist() const;
	void undo();
	void redo();
	void undoWatchList();
	void redoWatchList();
};

