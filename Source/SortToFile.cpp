#include "../Include/SortToFile.hpp"
#include "../Include/StudentStruct.hpp"

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <chrono>


//--------private functions ------
class StringToIntError{};
class GradeValueError{};

template<class T>
void readData(T &students, std::string fileName){
    std::stringstream fileStream;
    try{
        std::ifstream data;
        fileName.insert(0,"Results/");
        data.open(fileName);
        if(data.fail()) throw std::exception();
        fileStream<<data.rdbuf();

        data.close();
    }
    catch(const std::exception &e){
        std::cout<<"Exception: Unable to open the file \n";
        exit(1);
    }

    std::string line;
    getline(fileStream, line); //geting rid of first line
    while(!fileStream.eof()){

        getline(fileStream, line);
        if(fileStream.eof()) break;  //stream.eof() ==1 only after reading past end

        std::stringstream lineStream(line);
        std::vector<int> grades;
        int examRes;
        Student buffStud;

        lineStream>>buffStud.fName>>buffStud.lName;

        while(!lineStream.eof()){
            try{
                int buffInt;
                lineStream>>buffInt;

                if(lineStream.fail()) throw StringToIntError();
                if(buffInt < 0 || buffInt > 10) throw GradeValueError();

                if(lineStream.eof()) examRes = buffInt;
                else grades.push_back(buffInt);
            }
            catch (StringToIntError& e){
                std::cout<<"Exception: Wrong input type in grades, line:"<<students.size()+2<<std::endl;
                grades.clear();
                continue;
            }
            catch (GradeValueError& e){
                std::cout<<"Exception: Wrong input grade value, line:"<<students.size()+2<<std::endl;
                grades.clear();
                continue;
            }
        }
        
        buffStud.setFinalGrade(grades,examRes*1.0);
        grades.clear();

        students.push_back(buffStud);
    }
}

template<class T>
void print(T &students, std::string file){
   
   using std::setw;


    std::stringstream outputStream;
    outputStream<<setw(25); outputStream<<std::left<<"vardas ";
    outputStream<<setw(25); outputStream<<std::right<<"pavarde ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Med) ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Vid) "<<'\n';
    std::string line(100, '-');
    outputStream<<line<<'\n';
    
    for(const auto& stud : students){
        outputStream<<setw(25); outputStream<<std::left<<stud.fName;  //https://www.cplusplus.com/reference/ios/left/
        outputStream<<setw(25); outputStream<<std::right<<stud.lName;
        outputStream.precision(2);
        outputStream<<std::fixed;
        outputStream<<setw(25); outputStream<<std::right<<stud.finalMed;
        outputStream<<setw(25); outputStream<<std::right<<stud.finalAvrg<<'\n';      
    }

    line = outputStream.str();

    std::ofstream rez;
    file.insert(0,"Results/");
    rez.open(file);
    rez<<line;
    rez.close();
}




//------public functions ----------
void sortToFileVector(std::string fileName){
    std::vector<Student> students;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_sort, end_sort;

    start_input = std::chrono::high_resolution_clock::now(); 
    readData(students,fileName);
    end_input = std::chrono::high_resolution_clock::now(); 

    start_sort =std::chrono::high_resolution_clock::now(); 
    std::sort(students.begin(),students.end());
    long int studKiek = students.size();

    long int it;
    for(it = 0; it<students.size(); it++) if(students[it].finalAvrg >= 5) break;
    it--;

    std::vector<Student>::const_iterator first = students.begin()+it+1;
    std::vector<Student>::const_iterator last = students.end();
    std::vector<Student> islaike(first,last);
    students.resize(it);
    end_sort = std::chrono::high_resolution_clock::now();

    print(islaike,"islaike.txt");
    print(students,"skolininkai.txt");

    islaike.clear();
    students.clear();

    std::chrono::duration<double> input_dur = end_input - start_input;
    std::chrono::duration<double> sort_dur = end_sort - start_sort; 
    std::cout<<"duration of input:   "<<input_dur.count()<<"s"<<std::endl;
    std::cout<<"duration of sorting: "<<sort_dur.count()<<"s"<<std::endl;
}

void sortToFileDeque(std::string fileName){
    std::deque<Student> students;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_sort, end_sort;

    start_input = std::chrono::high_resolution_clock::now();  
    readData(students,fileName);
    end_input = std::chrono::high_resolution_clock::now(); 

    start_sort =std::chrono::high_resolution_clock::now();
    std::sort(students.begin(),students.end());
    long int studKiek = students.size();

    long int it;
    for(it = 0; it<students.size(); it++) if(students[it].finalAvrg >= 5) break;
    it--;

    std::deque<Student>::const_iterator first = students.begin()+it+1;
    std::deque<Student>::const_iterator last = students.end();
    std::deque<Student> islaike(first,last);
    students.resize(it);
    end_sort = std::chrono::high_resolution_clock::now();

    print(islaike,"islaike.txt");
    print(students,"skolininkai.txt");

    islaike.clear();
    students.clear();

    std::chrono::duration<double> input_dur = end_input - start_input;
    std::chrono::duration<double> sort_dur = end_sort - start_sort; 
    std::cout<<"duration of input:   "<<input_dur.count()<<"s"<<std::endl;
    std::cout<<"duration of sorting: "<<sort_dur.count()<<"s"<<std::endl;
}

void sortToFileList(std::string fileName){
    std::list<Student> students;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_sort, end_sort;

    start_input = std::chrono::high_resolution_clock::now();  
    readData(students,fileName);
    end_input = std::chrono::high_resolution_clock::now(); 

    start_sort =std::chrono::high_resolution_clock::now();
    students.sort();

    std::list<Student>::iterator it;
    it=students.begin();
    for(const auto& stud : students){
        if(stud.finalAvrg >= 5) break;
        advance(it,1);
    }
    std::list<Student> islaike;
    islaike.splice(islaike.begin(), students, it, students.end());
    end_sort = std::chrono::high_resolution_clock::now();

    print(islaike,"islaike.txt");
    print(students,"skolininkai.txt");

    islaike.clear();
    students.clear();

    std::chrono::duration<double> input_dur = end_input - start_input;
    std::chrono::duration<double> sort_dur = end_sort - start_sort; 
    std::cout<<"duration of input:   "<<input_dur.count()<<"s"<<std::endl;
    std::cout<<"duration of sorting: "<<sort_dur.count()<<"s"<<std::endl;
}