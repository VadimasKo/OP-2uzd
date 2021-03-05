#include "../Include/UserInput.hpp"
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

void print(vector<Student> &students);

class StringToDoubleError{};
class GradeValueError{};


int main(){

   if(question("Ar norite daryti rankini ivedima? ")) userInputProgram();
   else{

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

            //  cout<<buffStud.fName<<"  "<<buffStud.lName<<"  "<<buffStud.finalMed<<"  "<<buffStud.finalAvrg<<endl;    
        }

        sort(students.begin(),students.end());
        
        // print(fNameWidth,lNameWidth,students);
        print(students);
        


    }
}


void print(vector<Student> &students){
   

    stringstream outputStream;
    outputStream<<setw(25); outputStream<<std::left<<"vardas ";
    outputStream<<setw(25); outputStream<<std::right<<"pavarde ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Med) ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Vid) "<<'\n';
    string line(100, '-');
    outputStream<<line<<'\n';


    for(int i = 0; i<students.size(); i++){
        outputStream<<setw(25); outputStream<<std::left<<students[i].fName;  //https://www.cplusplus.com/reference/ios/left/
        outputStream<<setw(25); outputStream<<std::right<<students[i].lName;
        outputStream.precision(2);
        outputStream<<fixed;
        outputStream<<setw(25); outputStream<<std::right<<students[i].finalMed;
        outputStream<<setw(25); outputStream<<std::right<<students[i].finalAvrg<<'\n';      
    }


    line = outputStream.str();

    ofstream rez;
    rez.open("results.txt");
    rez<<line;
    rez.close();

}