#pragma once
#include "FileWatchList.h"
class UndoActionWatchList {

public:
	virtual ~UndoActionWatchList() {}
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};


class UndoAddWatchList : public UndoActionWatchList
{

private:
	Tutorial addedTutorial;
	FileWatchList& w;

public:
	UndoAddWatchList(Tutorial addedTutorial, FileWatchList &r) : w{ r } { this->addedTutorial = addedTutorial; }
	void executeUndo();
	void executeRedo();
};

class UndoRemoveWatchList : public UndoActionWatchList
{

private:
	Tutorial deletedTutorial;
	WatchList& w;

public:
	UndoRemoveWatchList(Tutorial deletedTutorial, FileWatchList &r) : w{ r } { this->deletedTutorial = deletedTutorial; }
	void executeUndo();
	void executeRedo();
};