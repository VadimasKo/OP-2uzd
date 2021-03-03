#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H

#include <string>
#include <vector>

struct Student{
    std::string fName, lName;
    double finalMed, finalAvrg;
    
    Student(int makeRandom);

    void setFinalGrade(std::vector<double> &grades, double examRez);
    bool operator < (Student &obj) const;
};

#endif