#include <iostream>
#include "ui.h"
#include "tests.h"

using namespace std;

int main()
{
	testProject();
	testRepository();
	testService();
	Ui userInterface;
	userInterface.run();
}
