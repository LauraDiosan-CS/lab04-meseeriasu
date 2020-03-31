#include <iostream>
#include "Ui.h"
#include "Repository.h"
#include "Service.h"
#include "Tests.h"

using namespace std;

int main()
{
	testProject();
	testRepository();
	testService();
	Repository repo;
	Service service(repo);
	Ui userInterface(service);
	userInterface.run();
}
