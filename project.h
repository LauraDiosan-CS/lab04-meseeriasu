#pragma once

class Project {
	private:
		char* gitPath;
		int noOfBranches, totalNoOfCommits;
	public:
		Project();
		Project(const char*, int, int);
		Project(const Project&);
		Project& operator=(const Project&);
		char* getGitPath();
		int getNoOfBranches();
		int getTotalNoOfCommits();
		void setGitPath(char*);
		void setNoOfBranches(int);
		void setTotalNoOfCommits(int);
		bool operator==(const Project&);
		~Project();
};