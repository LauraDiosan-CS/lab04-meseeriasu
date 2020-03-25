#include "repository.h"

Repository::Repository() {
	size = 0;
}

void Repository::addElem(Project p) {
	elem[size++] = p;
}

int Repository::findElem(Project p) {
	for (int i = 0;i < size;i++)
		if (elem[i] == p)
			return i;
	return -1;
}

Project Repository::getItemFromPos(int poz) {
	return elem[poz];
}

void Repository::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
		elem[i] = elem[size - 1];
	size--;
}

void Repository::updateElem(Project p,char* gitPath, int noOfBranches, int totalNoOfCommits) {
	int i = findElem(p);
	elem[i].setGitPath(gitPath);
	elem[i].setNoOfBranches(noOfBranches);
	elem[i].setTotalNoOfCommits(totalNoOfCommits);
}

Project* Repository::getAll() {
	return elem;
}

int Repository::getDim() {
	return size;
}

Repository::~Repository() {
}