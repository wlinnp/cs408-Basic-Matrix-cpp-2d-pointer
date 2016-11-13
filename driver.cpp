#include "matrix.h"

double getNextDouble()
{
	double f = (double)rand() / RAND_MAX;
	return LOWER_BOUND + f * (UPPER_BOUND - LOWER_BOUND);
}
void simpleDriver()
{
	int size = 5;
	double** left = new double*[size];
	double** right = new double*[size];
	assignArray(left, right, size);

	double** addition = add(left, right, size);
	double** subtraction = subtract(left, right, size);
	double** product = multiply(left, right, size);

	std::cout << "Basic Test" << std::endl;
	std::cout << "Left" << toString(left, size) << std::endl;
	std::cout << "Right" << toString(right, size) << std::endl;
	std::cout << "Addition" << toString(addition, size) << std::endl;
	std::cout << "Subtraction" << toString(subtraction, size) << std::endl;
	std::cout << "Product" << toString(product, size) << std::endl;

	deallocateArray(left, size);
	deallocateArray(right, size);
	deallocateArray(addition, size);
	deallocateArray(subtraction, size);
	deallocateArray(product, size);
}
void advancedDriver()
{
	std::cout << "Advanced Test" << std::endl;
	for (int i = START; i < END; i += 100)
	{
		std::cout << "for size: " << i << std::endl;
		double** left = new double*[i];
		double** right = new double*[i];
		assignArrayWithRandom(left, right, i);

		std::cout << "Addition: " << performSpeed(add, left,right, i) << std::endl;
		std::cout << "Subtraction: " << performSpeed(subtract, left,right, i) << std::endl;
		std::cout << "Product: " << performSpeed(multiply, left,right, i) << std::endl;

		deallocateArray(left, i);
		deallocateArray(right, i);
	}
}
void userDriver()
{
	bool repeat = true;
	while (repeat)
	{
		double** left = NULL;
		double** right = NULL;
		int size = -1;
		std::cout << "Welcome to basic Matrix Operations" << std::endl;
		std::cout << "Enter 0 to quit or other integer as matrix size" << std::endl;
		std::cin >> size;
		switch (size)
		{
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "For first matrix" << std::endl;
			left = fillSingleMatrix(size);
			std::cout << "For second matrix" << std::endl;
			right = fillSingleMatrix(size);
			operationMenu(left, right, size);
			deallocateArray(left, size);
			deallocateArray(right, size);
			break;
		}
	}
}
double** fillSingleMatrix(int size)
{
	int matrixSize = size * size;
	double** matrix = new double* [size];
	while (matrixSize > 0)
	{
		for (int i = 0; i < size; ++i)
		{
			matrix[i] = new double[size];
			for (int j = 0; j < size; ++j)
			{
				std::cout << "Enter value for cell [" << i << "][" << j << "]: ";
				double input = -1;
				std::cin >> input;
				matrix[i][j] = input;
				matrixSize--;
			}
		}
	}
	return matrix;
}
void operationMenu(double** left, double** right, int size)
{
	bool repeat = true;
	while (repeat)
	{
		std::cout << "Enter 1 to add those 2 matrices" << std::endl;
		std::cout << "Enter 2 to subtract those 2 matrices" << std::endl;
		std::cout << "Enter 3 to multiply those 2 matrices" << std::endl;
		std::cout << "Enter 0 to go back to main menu" << std::endl;
		int input = -1;
		std::cin >> input;
		switch (input)
		{
		case 0:
			repeat = false;
			break;
		case 1:
			performDisplay(add, left, right, size);
			break;
		case 2:
			performDisplay(subtract, left, right, size);
			break;
		case 3:
			performDisplay(multiply, left, right, size);
			break;
		default:
			std::cout << "invalid choice" << std::endl;
			break;
		}
	}
}