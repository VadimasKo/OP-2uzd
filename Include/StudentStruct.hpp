#pragma once

#include <string>
#include <vector>

struct Student{
    std::string fName, lName;
    double finalMed, finalAvrg;

    void setFinalGrade(std::vector<int> &grades, double examRes);
    bool operator < (Student &obj) const;
};