#include "RepositoryExceptions.h"


FileException::FileException(const std::string & msg) : message(msg)
{
}
const char * UndoException::what()
{
	return message.c_str();
}
const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateTutorialException::what()
{
	return "There is another tutorial with the same title!\n";
}
const char * InexistentTutorialException::what()
{
	return "There is no tutorial with that title\n";
}