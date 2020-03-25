#include "service.h"

Service::Service() {
	Project lab1("D/oop/lab1", 3, 5), lab2("D/oop/lab2", 7, 10), lab3("D/oop/lab3", 6, 12);
	repo.addElem(lab1);
	repo.addElem(lab2);
	repo.addElem(lab3);
}

int Service::getDim() {
	return repo.getDim();
}
void Service::addProject(char* gitPath, int noOfBranches, int totalNoOfCommits) {
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	repo.addElem(p);
}

void Service::delProject(char* gitPath, int noOfBranches, int totalNoOfCommits) {
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	repo.delElem(p);
}

void Service::findProjectsWithAtribute(int minimumNoOfBranches, int minimumNoOfCommits,Project resultList[], int &resultN) {
	resultN = 0;
	int dim = getDim();
	for (int i = 0;i < dim;i++)
		if (getAll()[i].getNoOfBranches() >= minimumNoOfBranches and getAll()[i].getTotalNoOfCommits() >= minimumNoOfCommits)
			resultList[resultN++] = getAll()[i];
}

Project* Service::getAll() {
	return repo.getAll();
}

void Service::updateProject(char* gitPathOld, int noOfBranchesOld, int totalNoOfCommitsOld, char* gitPathNew, int noOfBranchesNew, int totalNoOfCommitsNew) {
	Project p(gitPathOld, noOfBranchesOld, totalNoOfCommitsOld);
	repo.updateElem(p, gitPathNew, noOfBranchesNew, totalNoOfCommitsNew);
}

void Service::deleteProjectWithATribute() {
	int n = getDim();
	for (int i = 1;i < n;i++)
	{
		if (getAll()[i].getNoOfBranches() * getAll()[i].getTotalNoOfCommits() == 0)
			repo.delElem(getAll()[i]);
	}
}

Service::~Service() {
}