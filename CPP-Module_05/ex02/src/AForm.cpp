/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:30 by ravazque          #+#    #+#             */
/*   Updated: 2026/01/07 22:42:43 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Default constructor - [ AForm ]" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Parametric constructor - [ AForm ]" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	std::cout << "Copy constructor - [ AForm ]" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor - [ AForm ]" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "Assignment operator - [ AForm ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return (*this);
}

const std::string &AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw GradeTooLowException();
	this->executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form: " << form.getName()
		<< ", Signed: " << (form.getSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExec();
	return (out);
}
