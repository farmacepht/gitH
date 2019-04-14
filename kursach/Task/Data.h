#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Project.h"

using std::vector;

class Data {
private:
	vector<Project> projects_;
public:
	Data();
	vector<Project> getProjects() const;
	void addProject(Project& project);
	void removeProject(Project& project);
	void print(std::ostream& out);
	void fillFromFile(std::ifstream& fin);
	Project& findProject(Project& project);
	void sortByName();
};