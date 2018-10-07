#include "Validation.h"
using namespace std;

TutorialException::TutorialException(std::vector<std::string> _errors) : errors{ _errors } {}

std::vector<std::string> TutorialException::get_errors() const
{
	return this->errors;
}

void TutorialValidator::validate(const Tutorial& t)
{
	vector<string> errors;
	if (t.getTitle().size() < 3)
		errors.push_back("The tutorial title can't be less than 2 characters! \n");
	if (t.getPresenter().size() < 3)
		errors.push_back("The tutorial presenter can't be less than 2 characters! \n");
	if (!(t.getDuration().getMinutes() < 61 && t.getDuration().getMinutes()>0 && t.getDuration().getSeconds() < 61 && t.getDuration().getSeconds()>0))
		errors.push_back(string("The duration is not valid! \n"));
	if (t.getLikes() < 0)
		errors.push_back("The number of likes can't be negative! \n");
	size_t posWww = t.getLink().find("www");
	size_t posHttp = t.getLink().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("Invalid link: \"www\" or \"http\" is missing!\n");
	if (errors.size() > 0)
		throw TutorialException(errors);
}
