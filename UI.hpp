#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> //std::sort
// #include <cstdio> //printf

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::fixed;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::setw;


bool question(string);
void cinClean();
double getAverage(vector<double> &grades);
double getMedian(vector<double> &grades);
void userInputProgram();


#endif