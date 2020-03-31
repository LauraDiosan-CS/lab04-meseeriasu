#include <iostream>
#include "Project.h"
#include "Ui.h"

using namespace std;

Ui::Ui() {
}

Ui::Ui(const Service &s) {
	service = s;
}

void Ui::showMenu() {
	cout << "---Menu---" << endl;
	cout << "1. Adauga proiect" << endl;
	cout << "2. Update proiect" << endl;
	cout << "3. Sterge proiect" << endl;
	cout << "4. Afiseaza proiecte" << endl;
	cout << "5. Afiseaza proiecte care au cel putin K branch-uri si L commit-uri" << endl;
	cout << "6. Sterge proiecte care au noOfBranches*totalNoOfCommits = 0" << endl;
	cout << "7. Undo" << endl;
	cout << "0. Exit" << endl;
}

void Ui::addProject() {
	char* gitPath = NULL;
	int noOfBranches, totalNoOfCommits;
	gitPath = new char[20];
	cout << "gitPath: ";	cin >> gitPath;
	cout << "noOfBranches: ";	cin >> noOfBranches;
	cout << "totalNoOfCommits: ";	cin >> totalNoOfCommits;
	service.addProject(gitPath, noOfBranches, totalNoOfCommits);
	if (gitPath != NULL)
	{
		delete[] gitPath;
		gitPath = NULL;
	}
}

void Ui::printProjects() {
	int n = service.getDim();
	for (int i = 0;i < n;i++)
	{
		cout << "gitPath: " << service.getAll()[i].getGitPath() << " | ";
		cout << "noOfBranches: " << service.getAll()[i].getNoOfBranches() << " | ";
		cout << "totalNoOfCommits: " << service.getAll()[i].getTotalNoOfCommits() << endl;
	}
}

void Ui::deleteProject() {
	char* gitPath = NULL;
	int noOfBranches, totalNoOfCommits;
	gitPath = new char[20];
	cout << "gitPath: ";	cin >> gitPath;
	cout << "noOfBranches: ";	cin >> noOfBranches;
	cout << "totalNoOfCommits: ";	cin >> totalNoOfCommits;
	service.delProject(gitPath, noOfBranches, totalNoOfCommits);
	if (gitPath != NULL)
	{
		delete[] gitPath;
		gitPath = NULL;
	}
	cout << "Proiect sters" << endl;
}

void Ui::updateProject() {
	char* gitPathOld = NULL, * gitPathNew = NULL;
	int noOfBranchesOld, noOfBranchesNew, totalNoOfCommitsOld, totalNoOfCommitsNew;
	gitPathOld = new char[20];
	gitPathNew = new char[20];
	cout << "Obiectul care trebuie schimbat: " << endl;
	cout << "gitPath: ";	cin >> gitPathOld;
	cout << "noOfBranches: ";	cin >> noOfBranchesOld;
	cout << "totalNoOfCommits: ";	cin >> totalNoOfCommitsOld;
	cout << "Datele noi ale obiectului: " << endl;
	cout << "gitPath: ";	cin >> gitPathNew;
	cout << "noOfBranches: ";	cin >> noOfBranchesNew;
	cout << "totalNoOfCommits: ";	cin >> totalNoOfCommitsNew;
	service.updateProject(gitPathOld, noOfBranchesOld, totalNoOfCommitsOld, gitPathNew, noOfBranchesNew, totalNoOfCommitsNew);
	if (gitPathOld != NULL)
	{
		delete[] gitPathOld;
		gitPathOld = NULL;
	}
	if (gitPathNew != NULL)
	{
		delete[] gitPathNew;
		gitPathNew = NULL;
	}
}

void Ui::projectsWithAtribute()
{
	int minimumOfBranches, minimumOfCommits, n = 0;
	Project resultList[20];
	cout << "minimumOfBranches: ";	cin >> minimumOfBranches;
	cout << "minimumOfCommits: ";	cin >> minimumOfCommits;
	service.findProjectsWithAtribute(minimumOfBranches, minimumOfCommits, resultList, n);
	for (int i = 0;i < n;i++)
	{
		cout << "gitPath: " << resultList[i].getGitPath() << " | ";
		cout << "noOfBranches: " << resultList[i].getNoOfBranches() << " | ";
		cout << "totalNoOfCommits: " << resultList[i].getTotalNoOfCommits() << endl;
	}
}

void Ui::deleteProjectsWithAtribute()
{
	service.deleteProjectWithATribute();
	cout << "Gata!" << endl;
}

void Ui::run() {
	bool gata = true;
	while (gata)
	{
		int op;
		showMenu();
		cout << "Optiunea aleasa: ";
		cin >> op;
		switch (op)
		{
		case 0: {gata = false; break;}
		case 1: {addProject(); break;}
		case 2: {updateProject(); break;}
		case 3: {deleteProject(); break;}
		case 4: {printProjects(); break;}
		case 5: {projectsWithAtribute(); break;}
		case 6: {deleteProjectsWithAtribute(); break;}
		case 7: {service.undo(); break;}
		}
	}
}

Ui::~Ui() {
}