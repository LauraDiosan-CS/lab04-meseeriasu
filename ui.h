#pragma once
#include "Service.h";

class Ui {
private:
	Service service;
public:
	Ui();
	Ui(const Service&);
	void showMenu();
	void run();
	void addProject();
	void printProjects();
	void deleteProject();
	void updateProject();
	void deleteProjectsWithAtribute();
	void projectsWithAtribute();
	~Ui();
};