#include "../Include/StudentStruct.hpp"
#include "../Include/RandomToFile.hpp"
#include "../Include/BasicFunctions.hpp"

#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;



void randomToFile(int studKiek){

std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
std::chrono::time_point<std::chrono::high_resolution_clock> start_output, end_output;  
start_input = std::chrono::high_resolution_clock::now(); 

    Student studentas;
    string output("Vardas   Pavarde   nd1.. egz \n");
    output.reserve(studKiek*60);

    for(int i = 0; i<studKiek; i++) output.append(studentas.getRandomString());

end_input = std::chrono::high_resolution_clock::now();

start_output = std::chrono::high_resolution_clock::now(); 

    std::ofstream result;
    result.open("studentai.txt");
    result<<output;
    result.close();

end_output = std::chrono::high_resolution_clock::now();



std::chrono::duration<double> input_dur = end_input - start_input;
std::chrono::duration<double> output_dur = end_output - start_output; 

cout<<studKiek<<" irasu sukurimo trukme: "<<input_dur.count()<<"s"<<endl;
cout<<studKiek<<" irasu isvedimo trukme: "<<output_dur.count()<<"s"<<endl;

}