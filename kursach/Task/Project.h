#pragma once
#include <string>
#include <fstream>

struct Employee {
	std::string name_;
	std::string surname_;
	Employee() : name_(""), surname_("") {}
	Employee(std::string name, std::string surname) : name_(name), surname_(surname) {}
};

class Project {
private:
	std::string name_;
	Employee employee_;
	int hours_;
	int costOfHour_;
public:
	Project();
	Project(std::string name, Employee employee, int hours, int costOfHour);
	std::string getName() const;
	std::string getEmployeeName() const;
	std::string getEmployeeSurname() const;
	int getHours() const;
	int getCostOfHour() const;
	void setName(std::string name);
	void setEmployeeName(std::string name);
	void setEmployeeSurname(std::string surname);
	void setHours(int hours);
	void setCostOfHour(int cost);
	bool operator==(const Project& project);
	bool operator<(const Project& project);
	friend std::ostream& operator<<(std::ostream& out, const Project& project);
	friend std::istream& operator>>(std::istream& in, Project& project);
};