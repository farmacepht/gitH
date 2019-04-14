#include <iostream>
#include <fstream>
#include <sstream>

#include "Admin.h"
#include "User.h"
#include "Data.h"
#include "Project.h"

using namespace std;

int main() {
	ifstream fin;
	string path = "input.txt";

	fin.open(path);
	if (!fin.is_open()) {
		cout << "Error: can't open file\n";
		system("pause");
		return 0;
	}

	cout << "Everything is good, we can continue\n";
	Data data;
	data.fillFromFile(fin);
	Project project("qwe", Employee("qwe", "qwe"), 12, 15);

	Project p1;

	try
	{
		p1 = data.findProject(project);
		cout << "HDHDHDH";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << "\n";
	}

	//data.print(cout);


	system("pause");

	return 0;
}