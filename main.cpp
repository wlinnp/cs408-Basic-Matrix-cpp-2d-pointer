
#include "matrix.h"

int main()
{
	srand (time(NULL));
	std::cout << "wanna see the basic and performance test? 0 for No, others for Yes" << std::endl;
	int input = 0;
	std::cin >> input;
	if (input != 0)
	{
		simpleDriver();
		advancedDriver();
	}
	userDriver();
}