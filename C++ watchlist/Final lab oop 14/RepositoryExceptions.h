#pragma once
#include <exception>
#include <string>

class UndoException : public std::exception
{
protected:
	std::string message;

public:
	UndoException(const std::string& mesg) : message(mesg) {}
	virtual const char* what();
};

class FileException : public std::exception
{
protected:
	std::string message;

public:
	FileException(const std::string& msg);
	virtual const char* what();
};

class RepositoryException : public std::exception
{
protected:
	std::string message;

public:
	RepositoryException();
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {}
	virtual const char* what();
};

class DuplicateTutorialException : public RepositoryException
{
	const char* what();
};
class InexistentTutorialException : public RepositoryException
{
	const char* what();
};
