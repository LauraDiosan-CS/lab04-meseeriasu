#pragma once
#include "project.h"

class Repository {
	private:
		Project elem[10];
		int size;
	public:
		Repository();
		void addElem(Project);
		int findElem(Project);
		Project getItemFromPos(int);
		void delElem(Project);
		void updateElem(Project, char*, int, int);
		Project* getAll();
		int getDim();
		~Repository();

};