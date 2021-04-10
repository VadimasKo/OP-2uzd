#pragma once

#include <string>
#include <vector>

struct StudentStruct
{
    std::string fName, lName;
    double finalMed, finalAvrg;

    void setFinalGrades(std::vector<int> &grades, double examRes);
    bool operator < (StudentStruct &obj) const;
    /* data */
};
