#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdlib.h>

const std::string TAB = "\t\t";
const std::string NEXT_LINE = "\n";

static const int START = 1000;
static const int END = 2001;
static const int LOWER_BOUND = -10;
static const int UPPER_BOUND = 10;

const double array1[] = {1.0, 2.0, 3.0, 4.0, 5.0,2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 1.0, 1.0, 1.0, 3.0,0.0, 0.0, 2.0, 3.0, -2.0, 4.0, 4.0, -4.0, 0.0, 0.0};
const double array2[] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 1.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, -2.0, 2.0, 2.0};


double** add(double** left, double** right, int size);
double** subtract(double** left, double** right, int size);
double** multiply(double** left, double** right, int size);
std::string toString(double** matrix, int size);
void assignArray(double **left, double **right, int size);
void assignArrayWithRandom(double **left, double **right, int size);
double getNextDouble();
long performSpeed(double** (*f)(double**, double**, int), double**, double**, int);
void performDisplay(double** (*f)(double**, double**, int), double**, double**, int);
void deallocateArray(double** matrix, int size);
void simpleDriver();
void advancedDriver();
void userDriver();
double** fillSingleMatrix(int size);
void operationMenu(double** left, double** right, int size);

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
void deallocateArray(double** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void assignArray(double **left, double **right, int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) 
    {
        left[i] = new double[size];
        right[i] = new double[size];
    	for (int j = 0; j < size; ++j) 
    	{
            left[i][j] = array1[counter];
            right[i][j] = array2[counter];
            counter++;
        }
    }
}
void assignArrayWithRandom(double **left, double **right, int size)
{
    for (int i = 0; i < size; ++i) 
    {
        left[i] = new double[size];
        right[i] = new double[size];
    	for (int j = 0; j < size; ++j) 
    	{
            left[i][j] = getNextDouble();
            right[i][j] = getNextDouble();
        }
    }
}
std::string toString(double** matrix, int size)
{
	std::stringstream result;
	result << NEXT_LINE;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			result << matrix[i][j] << TAB;
		}
		result << NEXT_LINE;
	}
	result << NEXT_LINE;
	return result.str();
}

double** add(double** left, double** right, int size)
{
	std::cout << toString(left, size) << std::endl;
	std::cout << toString(right, size) << std::endl;
	double** result = new double*[size];
    for (int i = 0; i < size; ++i) 
    {
    	result[i] = new double[size];
        for (int j = 0; j < size; ++j) 
        {
        	result[i][j] = left[i][j] + right[i][j];
        }
    }
    return result;
}

double** subtract(double** left, double** right, int size)
{
	double** result = new double*[size];
    for (int i = 0; i < size; ++i)
    {
    	result[i] = new double[size];
        for (int j = 0; j < size; ++j) 
        {
        	result[i][j] = left[i][j] - right[i][j];
        }
    }
    return result;
}

double** multiply(double** left, double** right, int size)
{
	double** result = new double*[size];
    for (int i = 0; i < size; ++i) 
    {
    	result[i] = new double[size];
        for (int j = 0; j < size; ++j) 
        {
            double cellResult = 0;
            for (int k = 0; k < size; k++) 
            {
                cellResult += left[i][k] * right[j][k];
            }
            result[i][j] = cellResult;
        }
    }
    return result;
}

long performSpeed(double** (*f)(double** left, double** right, int size), double** left, double** right, int size)
{
	clock_t start = clock();
	double** result = (*f)(left, right, size);	
	long elapsedTime = (clock() - start) / (CLOCKS_PER_SEC/1000000000.0);
	deallocateArray(result, size);
	return elapsedTime;
}

void performDisplay(double** (*f)(double** eft, double** right, int size), double** left, double** right, int size)
{
	double** result = (*f)(left, right, size);
	std::cout << toString(result, size) << std::endl;
	deallocateArray(result, size);
}