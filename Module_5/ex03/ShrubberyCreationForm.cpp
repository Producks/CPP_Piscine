#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
    : Form(rhs), target_(rhs.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	std::cout << "???🤡" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
	std::ofstream	output;

	canBeExecuted(executor);
	output.open(target_ + "_shrubbery", std::ofstream::out);
	if (!output.is_open())
		throw FileError();
	output << "               ,@@@@@@@," << std::endl;
	output << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	output << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	output << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	output << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	output << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	output << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	output << "       |o|        | |         | |" << std::endl;
	output << "       |.|        | |         | |" << std::endl;
	output << "🌲  \\/ ._\\///_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	output.close();
	std::cout << executor.getName() << " executed " << " shrubbery🌳" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const { return target_; }