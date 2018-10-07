#pragma once
#include "Tutorial.h"
#include <stdio.h>
#include <vector>
#include <string>

class TutorialException
{
private:
	std::vector<std::string> errors;
public:
	TutorialException(std::vector<std::string> _errors);
	std::vector<std::string> get_errors() const;
};

class TutorialValidator
{
public:
	TutorialValidator() {}
	static void validate(const Tutorial& m);
};

