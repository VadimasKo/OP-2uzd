#include "StudentStruct.hpp"
#include "UI.hpp"

using std::vector;
using std::string;


void Student::setFinalGrade(vector<double> &grades, double examRez){
    examRez *= 0.6;
    finalAvrg = ((getAverage(grades)*0.4) + examRez);
    finalMed = ((getMedian(grades)*0.4) + examRez);
}

bool Student::operator < (Student &obj) const {
    return (fName < obj.fName);
}

