#include "../Include/StudentStruct.hpp"
#include "../Include/BasicFunctions.hpp"

#include <random>

using std::vector;
using std::string;

const string names[11] = {"Lėja", "Amelija", "Emilija", "Sofija", "Gabija", "Benas", "Markas", "Lukas", "Matas", "Nojus", "Rufijus"};
const string surnames[11] = {"Broom", "Car", "Far", "Doorman", "Shroom", "VaatiVidya", "Internet", "Historian", "Kjellberg", "Rober", "Pastorius"};


class RandInt{
    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high}{}
        int operator ()() {return dist(mt);} //generuoja int
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;
};


void Student::makeRandom(){


    RandInt rnd {0,10};

    double sum = 0;
    for (int i= 0; i<10;i++) sum += rnd();
    if(sum!=0) finalAvrg = sum/10;
    else finalAvrg = 0;
    
    sum = 0;
    for (int i= 0; i<10;i++) sum += rnd();
    if(sum!=0) finalMed = sum/10;
    else finalMed = 0;
    

    fName = names[rnd()];
    lName = surnames[rnd()];

}


void Student::setFinalGrade(vector<double> &grades, double examRez){
    examRez *= 0.6;
    finalAvrg = ((getAverage(grades)*0.4) + examRez);
    finalMed = ((getMedian(grades)*0.4) + examRez);
}

bool Student::operator < (Student &obj) const {
    return (finalAvrg < obj.finalAvrg);
}
