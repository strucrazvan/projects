#pragma once
#include <exception>
#include <string>

class RepositoryException: public std::exception
{
private:
	std::string message;
public:
	RepositoryException(const std::string & message) : message{ message } {}
	const char* what() const override { return this->message.c_str(); }
};

