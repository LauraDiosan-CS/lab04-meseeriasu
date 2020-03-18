#include "tests.h"
#include "project.h"
#include "repository.h"
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

void testProject() {
	char* gitPath1=new char[20];
	strcpy_s(gitPath1, sizeof "D/oop", "D/oop");
	Project laborator29(gitPath1, 3, 5);
	Project laborator1;
	assert(strcmp(laborator29.getGitPath(), gitPath1)==0);
	assert(laborator29.getNoOfBranches() == 3);
	assert(laborator29.getTotalNoOfCommits() == 5);
	assert(laborator1.getGitPath() == NULL);
	laborator1 = laborator29;
	assert(laborator1 == laborator29);
	cout << "Project tests done!"<<endl;
}

void testRepository() {
	Repository listOfProjects;
	Project lab1("D/oop/lab1", 3, 5), lab2("D/oop/lab2", 7, 10), lab3("D/oop/lab3", 6, 12);
	Project *test_list;
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