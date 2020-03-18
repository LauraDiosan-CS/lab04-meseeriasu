#include "project.h"
#include <string.h>

Project::Project() {
	gitPath = NULL;
	noOfBranches = 0;
	totalNoOfCommits = 0;
}

Project::Project(const char* gitPath, int noOfBranches, int totalNoOfCommits) {
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	this->noOfBranches = noOfBranches;
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::Project(const Project& p) {
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
}

char* Project::getGitPath() {
	return gitPath;
}

int Project::getNoOfBranches() {
	return noOfBranches;
}

int Project::getTotalNoOfCommits() {
	return totalNoOfCommits;
}

void Project::setGitPath(char* gitPath) {
	if (this->gitPath != NULL)
		delete[] this->gitPath;
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
}

void Project::setNoOfBranches(int noOfBranches) {
	this->noOfBranches = noOfBranches;
}

void Project::setTotalNoOfCommits(int totalNoOfCommits) {
	this->totalNoOfCommits = totalNoOfCommits;
}

Project::~Project() {
	if (gitPath != NULL)
		delete[] gitPath;
	gitPath = NULL;
	noOfBranches = -1;
	totalNoOfCommits = -1;
}

Project& Project::operator=(const Project& p) {
	if (this == &p)
		return *this;
	if (gitPath != NULL)
		delete[] gitPath;
	gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(gitPath, strlen(p.gitPath) + 1, p.gitPath);
	noOfBranches = p.noOfBranches;
	totalNoOfCommits = p.totalNoOfCommits;
	return *this;
}

bool Project::operator==(const Project& p) {
	return ((strcmp(gitPath, p.gitPath) == 0) and (noOfBranches == p.noOfBranches)) and (totalNoOfCommits == p.totalNoOfCommits);
}