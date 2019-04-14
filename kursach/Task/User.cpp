#include "User.h"

std::string User::getName() const
{
	return name_;
}

std::string User::getPassword() const
{
	return password_;
}

void User::setName(std::string name)
{
	name_ = name;
}

void User::setPassword(std::string password)
{
	password_ = password;
}
