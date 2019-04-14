#include "Project.h"

Project::Project()
{
	name_ = "";
	employee_;
	hours_ = -1;
	costOfHour_ = -1;
}

Project::Project(std::string name, Employee employee, int hours, int costOfHour)
{
	name_ = name;
	employee_ = employee;
	hours_ = hours;
	costOfHour_ = costOfHour;
}

std::string Project::getName() const
{
	return name_;
}

std::string Project::getEmployeeName() const
{
	return employee_.name_;
}

std::string Project::getEmployeeSurname() const
{
	return employee_.surname_;
}

int Project::getHours() const
{
	return hours_;
}

int Project::getCostOfHour() const
{
	return costOfHour_;
}

void Project::setName(std::string name)
{
	name_ = name;
}

void Project::setEmployeeName(std::string name)
{
	employee_.name_ = name;
}

void Project::setEmployeeSurname(std::string surname)
{
	employee_.surname_ = surname;
}

void Project::setHours(int hours)
{
	hours_ = hours;
}

void Project::setCostOfHour(int cost)
{
	costOfHour_ = cost;
}

bool Project::operator==(const Project & project)
{
	if (project.getName() == name_ &&
		project.getEmployeeName() == employee_.name_ &&
		project.getEmployeeSurname() == employee_.surname_ &&
		project.getHours() == hours_ &&
		project.getCostOfHour() == costOfHour_) {
		return true;
	}
	else {
		return false;
	}
}

bool Project::operator<(const Project & project)
{
	if (name_ < project.name_) {
		return true;
	}
	else if (name_ == project.name_) {
		if (hours_ < project.hours_) {
			return true;
		}
		return false;
	}
	return false;
}

std::ostream& operator<<(std::ostream & out, const Project & project)
{
	out << project.name_ << "\t";
	out << project.employee_.name_ << "\t";
	out << project.employee_.surname_ << "\t";
	out << project.hours_ << "\t";
	out << project.costOfHour_;
	return out;
}

std::istream & operator>>(std::istream & in, Project & project)
{
	in >> project.name_;
	in >> project.employee_.name_;
	in >> project.employee_.surname_;
	in >> project.hours_;
	in >> project.costOfHour_;
	return in;
}
