#include "../Include/GenerateRecords.hpp"

#include <string>
#include <fstream>
#include <random>

class RandInt{
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;

    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high} {}
        int operator ()() {return dist(mt);}
};

RandInt rnd {0,10};
const std::string names[11] = {"Lėja \t", "Amelija \t", "Emilija \t", "Sofija \t", "Gabija \t", "Benas \t", "Markas \t", "Lukas \t", "Matas \t", "Nojus \t", "Rufijus \t"};
const std::string surnames[11] = {"Broom \t", "Car \t", "Far \t", "Doorman \t", "Shroom \t", "VaatiVidya \t", "Internet \t", "Historian \t", "Kjellberg \t", "Rober \t", "Pastorius \t"};

std::string getRandomLine(){
    std::string line(names[rnd()]);
    line.reserve(60);

    for(int i = 0; i<10; i++){
        line.append("\t");
        line.append(std::to_string(rnd()));
    }
    line += "\n";

    return line;
}

void generateRecords(int studKiek){
    std::string result("Vardas   Pavarde     nd1 nd2... egz \n");
    result.reserve((studKiek+1)*60);

    for(int i=0; i<studKiek; i++) result.append(getRandomLine());

    std::ofstream output;
    output.open("Results/studentai.txt");
    output<<result;
    output.close();

    result.clear();
}

