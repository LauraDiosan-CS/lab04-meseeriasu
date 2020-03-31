#pragma once
#include "Project.h"

class Repository {
private:
	Project elem[20];
	Project undo[20][20];
	int size, undo_size, undo_sizes[20];
public:
	Repository();
	void addElem(Project);
	int findElem(Project);
	void addUndo();
	void deleteUndo();
	void undoFunction();
	Project getItemFromPos(int);
	void delElem(Project);
	void updateElem(Project, char*, int, int);
	Repository& operator=(const Repository&);
	Project* getAll();
	int getDim();
	~Repository();

};