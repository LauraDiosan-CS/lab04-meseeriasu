#pragma once
#include "service.h";

class Ui {
	private:
		Service service;
	public:
		Ui();
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