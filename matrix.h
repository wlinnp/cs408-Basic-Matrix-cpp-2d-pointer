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