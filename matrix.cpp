
#include "matrix.h"


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
