#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H

#include <vector>
#include <string>
#include "StudentStruct.hpp"

double getAverage(std::vector<double> &grades);
double getMedian(std::vector<double> &grades);
bool question(std::string);
void cinClean();
void print(std::vector<Student> &students, std::string file, bool title);
#endif