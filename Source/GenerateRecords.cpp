#include "../Include/GenerateRecords.hpp"

#include <random>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>


using std::string;


class RandInt{
    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high}{}
        int operator ()() {return dist(mt);} //generuoja int
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;
};

string getRandomLine();

RandInt rnd {0,10};
const string names[11] = {"Lėja \t", "Amelija \t", "Emilija \t", "Sofija \t", "Gabija \t", "Benas \t", "Markas \t", "Lukas \t", "Matas \t", "Nojus \t", "Rufijus \t"};
const string surnames[11] = {"Broom \t", "Car \t", "Far \t", "Doorman \t", "Shroom \t", "VaatiVidya \t", "Internet \t", "Historian \t", "Kjellberg \t", "Rober \t", "Pastorius \t"};


void generateRecords(int studKiek){
    std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_output, end_output;  
    start_input = std::chrono::high_resolution_clock::now(); 

        string result("Vardas   Pavarde     nd1     nd2     nd3     nd4     nd5     nd6     nd7     nd8     nd9     egz \n");
        result.reserve((studKiek+1)*60);
        
        for( int i = 0; i<studKiek; i++) result.append(getRandomLine());

    end_input = std::chrono::high_resolution_clock::now();

    start_output = std::chrono::high_resolution_clock::now(); 

        std::ofstream output;
        output.open("Results/studentai.txt");
        output<<result;
        output.close();

    end_output = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> input_dur = end_input - start_input;
    std::chrono::duration<double> output_dur = end_output - start_output; 

    std::cout<<studKiek<<" duration of creation   "<<input_dur.count()<<"s \n";
    std::cout<<studKiek<<" output duration:       "<<output_dur.count()<<"s \n";

}

string getRandomLine(){
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