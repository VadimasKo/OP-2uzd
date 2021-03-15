#include "../Include/StudentStruct.hpp"
#include <vector>
#include <algorithm>
// ------ private -----

double getAverage(std::vector<int> &grades){
    double sum = 0;

    for(int i = 0; i<grades.size(); i++) sum +=grades[i];

    if(sum==0) return sum;
    else   return sum/grades.size();
}

double getMedian(std::vector<int> &grades){
    std::sort(grades.begin(), grades.end());

    if(grades.size()==0) return 0;
    else{

        if(grades.size()%2 == 1) return grades[grades.size()/2];
        else  return grades[grades.size()/2] + grades[(grades.size()/2)- 1];
    }
}


// ------ public -----
void Student::setFinalGrade(std::vector<int> &grades, double examRes){
    examRes *= 0.6;
    finalAvrg =((getAverage(grades)*0.4)+examRes);
    finalMed = ((getMedian(grades)*0.4) + examRes);
}

bool Student::operator < (Student &obj) const {
    return (finalAvrg < obj.finalAvrg);
}