#pragma once
#include "Project.h"
#include "Repository.h"

class Service {
private:
	Repository repo;
public:
	Service();
	Service(const Repository&);
	int getDim();
	void addProject(char*, int, int);
	void delProject(char*, int, int);
	void updateProject(char*, int, int, char*, int, int);
	void deleteProjectWithATribute();
	void findProjectsWithAtribute(int, int, Project[], int&);
	void undo();
	Project* getAll();
	~Service();
};