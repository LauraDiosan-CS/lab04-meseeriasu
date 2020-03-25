#include "tests.h"
#include "project.h"
#include "repository.h"
#include "service.h"
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

void testProject() {
	char* gitPath1 = new char[20];
	strcpy_s(gitPath1, sizeof "D/oop", "D/oop");
	Project laborator29(gitPath1, 3, 5);
	Project laborator1;
	assert(strcmp(laborator29.getGitPath(), gitPath1) == 0);
	assert(laborator29.getNoOfBranches() == 3);
	assert(laborator29.getTotalNoOfCommits() == 5);
	assert(laborator1.getGitPath() == NULL);
	laborator1 = laborator29;
	assert(laborator1 == laborator29);
	cout << "Project tests done!" << endl;
}

void testRepository() {
	Repository listOfProjects;
	Project lab1("D/oop/lab1", 3, 5), lab2("D/oop/lab2", 7, 10), lab3("D/oop/lab3", 6, 12);
	Project* test_list;
	listOfProjects.addElem(lab1);
	listOfProjects.addElem(lab2);
	listOfProjects.addElem(lab3);
	assert(listOfProjects.getDim() == 3);
	assert(listOfProjects.getItemFromPos(0) == lab1);
	assert(listOfProjects.findElem(lab2) == 1);
	listOfProjects.delElem(lab2);
	assert(listOfProjects.getDim() == 2);
	test_list = listOfProjects.getAll();
	assert(test_list[0] == lab1 and test_list[1] == lab3);
	cout << "Repository tests done!" << endl;
}

void testService() {
	Service service;
	Project lab1("D/oop/lab1", 3, 5), lab2("D/oop/lab2", 7, 10), lab3("D/oop/lab3", 6, 12);
	char* lab1Path, *lab2Path, *lab3Path;
	lab1Path = new char[15];
	strcpy_s(lab1Path, 11, "D/oop/lab1");
	lab2Path = new char[15];
	strcpy_s(lab2Path, 11, "D/oop/lab2");
	lab3Path = new char[15];
	strcpy_s(lab3Path, 11, "D/oop/lab3");
	service.updateProject(lab1Path, 3, 5, lab2Path, 2, 3);
	Project lab4(lab2Path, 2, 3);
	assert(service.getAll()[0] == lab4);
	delete[] lab1Path;
	lab1Path = NULL;
	delete[] lab2Path;
	lab2Path = NULL;
	assert(service.getAll()[0] == lab4 and service.getAll()[1] == lab2 and service.getAll()[2] == lab3);
	service.delProject(lab3Path, 6, 12);
	delete[] lab3Path;
	lab3Path = NULL;
	assert(service.getAll()[0] == lab4 and service.getAll()[1] == lab2);
	Project testList[10];
	int resultN = 0;
	service.findProjectsWithAtribute(5, 4, testList, resultN);
	assert(resultN == 1);
	assert(testList[0] == lab2);
	cout << "Service tests done!" << endl;
}