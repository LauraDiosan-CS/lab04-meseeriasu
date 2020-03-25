#pragma once
#include "project.h"
#include "repository.h"

class Service {
	private:
		Repository repo;
	public:
		Service();
		int getDim();
		void addProject(char*, int, int);
		void delProject(char*, int, int);
		void updateProject(char*, int, int, char*, int, int);
		void deleteProjectWithATribute();
		void findProjectsWithAtribute(int, int, Project[], int&);
		Project* getAll();
		~Service();
};