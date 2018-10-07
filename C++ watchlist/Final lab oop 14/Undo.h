#pragma once
#include <stdio.h>
#include "Tutorial.h"
#include "Repository.h"

class UndoAction {

public:
	virtual ~UndoAction() {}
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};


class UndoAdd : public UndoAction
{

private:
	Tutorial addedTutorial;
	Repository& repo;

public:
	UndoAdd(Tutorial addedTutorial, Repository &r) : repo{ r } { this->addedTutorial = addedTutorial; }
	void executeUndo();
	void executeRedo();
};

class UndoRemove : public UndoAction {

private:
	Tutorial deletedTutorial;
	Repository& repo;

public:
	UndoRemove(Tutorial deletedTutorial, Repository &r) : repo{ r } { this->deletedTutorial = deletedTutorial; }
	void executeUndo();
	void executeRedo();

};

class UndoUpdate : public UndoAction {

private:
	Tutorial updatedTutorial;
	Tutorial lastTutorial;
	Repository & repo;

public:
	UndoUpdate(Tutorial updatedTutorial, Tutorial lastTutorial, Repository &r) : repo{ r } { this->updatedTutorial = updatedTutorial; this->lastTutorial = lastTutorial; }
	void executeUndo();
	void executeRedo();

};