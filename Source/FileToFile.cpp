#include "../Include/BasicFunctions.hpp"
#include "../Include/StudentStruct.hpp"



#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <exception>
#include <chrono>


using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::vector;
using std::sort;
using std::string;
using std::stringstream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::exception;
using std::fixed;

class StringToDoubleError{};
class GradeValueError{};


void fileToFile(string input){

    std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_sort, end_sort;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_output, end_output;  

    vector<Student> students;
    string fileString;

start_input = std::chrono::high_resolution_clock::now();  

    stringstream fileStream;
    try{
        fstream data;
        data.open(input);
        if( data.fail()) throw exception();
        fileStream << data.rdbuf();
        
        data.close();
    }
    catch(const exception& e){
        cout<<"Exception: Unable to open the file"<<endl;
        exit(1);
    }

    

    
    string line;
    getline(fileStream,line); //getting rid of first line

    while(!fileStream.eof()){
        getline(fileStream,line);
        
        if(fileStream.eof()) break;     //stream.eof() ==1 only after reading past end
        
        stringstream lineStream(line); 

        vector <double> grades;
        Student buffStud;
        double examRez;

        lineStream>>buffStud.fName>>buffStud.lName;

        try{   

            while(!lineStream.eof()){

            double buffDouble;
            lineStream>>buffDouble;

            if(lineStream.fail()) throw StringToDoubleError();
            if(buffDouble<0 || buffDouble>10) throw GradeValueError();


            if(lineStream.eof()) examRez = buffDouble;
            else grades.push_back(buffDouble);

            }
        }
        catch (StringToDoubleError& e){
            cout<<"Exception: Wrong input type in grades, line:"<<students.size()+2<<endl;
            grades.clear();
            continue;
        }
        catch (GradeValueError& e){
            cout<<"Exception: Wrong input grade value, line:"<<students.size()+2<<endl;
            grades.clear();
            continue;
        }

        buffStud.setFinalGrade(grades,examRez);
        grades.clear();

        students.push_back(buffStud);

    }

    end_input = std::chrono::high_resolution_clock::now(); 

start_sort =std::chrono::high_resolution_clock::now(); 

    sort(students.begin(),students.end());

    long int studKiek = students.size();

    long int it;
    for(it = 0; it<students.size(); it++) if(students[it].finalAvrg >= 5) break; 

    vector<Student>::const_iterator first = students.begin()+it;
    vector<Student>::const_iterator last = students.end();

    vector<Student> islaike(first,last);
    
    students.resize(it+1);

end_sort = std::chrono::high_resolution_clock::now(); 

start_output = std::chrono::high_resolution_clock::now(); 

    print(islaike, "islaike.txt");
    print(students, "skolininkai.txt");

end_output = std::chrono::high_resolution_clock::now(); 

    islaike.clear();
    students.clear();

 std::chrono::duration<double> input_dur = end_input - start_input;
 std::chrono::duration<double> sort_dur = end_sort - start_sort; 
 std::chrono::duration<double> output_dur = end_output - start_output; 
 
cout<<studKiek<<" input duration:        "<<input_dur.count()<<"s"<<endl;
cout<<studKiek<<" sort duration:         "<<sort_dur.count()<<"s"<<endl;
cout<<studKiek<<" output duration:       "<<output_dur.count()<<"s"<<endl;
}