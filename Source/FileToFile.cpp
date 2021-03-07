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

    vector<Student> students;
    string fileString;

    stringstream fileStream;
    try{
        fstream data;
        data.open("kursiokai.txt");
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

    sort(students.begin(),students.end());


    long int it;
    for(it = 0; it<students.size(); it++) if(students[it].finalAvrg >= 5) break; 

    vector<Student>::const_iterator first = students.begin()+it;
    vector<Student>::const_iterator last = students.end();

    vector<Student> islaike(first,last);
    
    students.resize(it+1);

    print(islaike, "islaike.txt");
    print(students, "skolininkai.txt");
    
    islaike.clear();
    students.clear();
}