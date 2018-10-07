#include "Undo.h"



void UndoAdd::executeUndo() {
	this->repo.removeTutorial(this->addedTutorial);
}

void UndoRemove::executeUndo() {
	this->repo.addTutorial(this->deletedTutorial);
}

void UndoUpdate::executeUndo()
{
	this->repo.updateTutorial(this->updatedTutorial, this->updatedTutorial);
}

void UndoAdd::executeRedo() {
	this->repo.addTutorial(this->addedTutorial);
}

void UndoRemove::executeRedo() {
	this->repo.removeTutorial(this->deletedTutorial);
}

void UndoUpdate::executeRedo() {
	this->repo.updateTutorial(this->updatedTutorial, this->lastTutorial);
}
