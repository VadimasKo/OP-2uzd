#include "../Include/StudentStruct.hpp"
#include "../Include/BasicFunctions.hpp"

#include <random>
#include <string>

using std::vector;
using std::string;

const string names[11] = {"Lėja \t", "Amelija \t", "Emilija \t", "Sofija \t", "Gabija \t", "Benas \t", "Markas \t", "Lukas \t", "Matas \t", "Nojus \t", "Rufijus \t"};
const string surnames[11] = {"Broom \t", "Car \t", "Far \t", "Doorman \t", "Shroom \t", "VaatiVidya \t", "Internet \t", "Historian \t", "Kjellberg \t", "Rober \t", "Pastorius \t"};


class RandInt{
    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high}{}
        int operator ()() {return dist(mt);} //generuoja int
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;
};

 RandInt rnd {0,10};

void Student::makeRandom(){
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

string Student::getRandomString(){
    string line(names[rnd()]);
    line.reserve(60);
    line.append(surnames[rnd()]);

    for(int i= 0; i<10; i++) {
        line.append("\t");
        line.append(std::to_string(rnd()));
    }
    line +="\n";

    return line;
}


void Student::setFinalGrade(vector<double> &grades, double examRez){
    examRez *= 0.6;
    finalAvrg = ((getAverage(grades)*0.4) + examRez);
    finalMed = ((getMedian(grades)*0.4) + examRez);
}

bool Student::operator < (Student &obj) const {
    return (finalAvrg < obj.finalAvrg);
}
