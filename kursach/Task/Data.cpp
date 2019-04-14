#include "Data.h"

Data::Data()
{
}

vector<Project> Data::getProjects() const
{
	return projects_;
}

void Data::addProject(Project& project) {
	projects_.emplace_back(project);
}

void Data::removeProject(Project & project)
{
	int index = -1;
	for (int i = 0; i < projects_.size(); ++i) {
		if (projects_[i] == project) {
			index = i;
			break;
		}
	}
	// project was founded
	if (index != -1) {
		projects_.erase(projects_.begin() + index);
	}
}

void Data::print(std::ostream& out)
{
	for (int i = 0; i < projects_.size(); ++i) {
		out << projects_[i] << "\n";
	}
}

void Data::fillFromFile(std::ifstream & fin)
{
	std::string currLine;
	std::string name;
	std::string eName;
	std::string eSurname;
	int hours;
	int cost;
	Project currProject;

	while (getline(fin, currLine)) {
		std::stringstream ss(currLine);
		ss >> name;
		ss >> eName;
		ss >> eSurname;
		ss >> hours;
		ss >> cost;
		currProject.setName(name);
		currProject.setEmployeeName(eName);
		currProject.setEmployeeSurname(eSurname);
		currProject.setHours(hours);
		currProject.setCostOfHour(cost);
		addProject(currProject);
	}
}

Project & Data::findProject(Project & project)
{
	int index = -1;
	for (int i = 0; i < projects_.size(); ++i) {
		if (projects_[i] == project) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		throw std::exception("Requested project wasn't found");
	}
	return projects_[index];
}

void Data::sortByName()
{
	std::sort(projects_.begin(), projects_.end(), [](Project& p1, Project& p2) {
		return p1.getName() < p2.getName();
	});
}
