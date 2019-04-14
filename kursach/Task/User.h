#pragma once
#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <string> 

class User {
private:
	std::string name_;
	std::string password_;
public:
	std::string getName() const;
	std::string getPassword() const;
	void setName(std::string name);
	void setPassword(std::string password);
};	


#endif // ADMIN_H_INCLUDED