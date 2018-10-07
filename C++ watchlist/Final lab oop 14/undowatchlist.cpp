#include "undowatchlist.h"



void UndoAddWatchList::executeUndo() {
	this->w.remove(this->addedTutorial);
}

void UndoRemoveWatchList::executeUndo() {
	this->w.add(this->deletedTutorial);
}

void UndoAddWatchList::executeRedo() {
	this->w.add(this->addedTutorial);
}

void UndoRemoveWatchList::executeRedo() {
	this->w.remove(this->deletedTutorial);
}

