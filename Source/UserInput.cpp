#include "../Include/UserInput.hpp"
#include "../Include/StudentStruct.hpp"
#include "../Include/BasicFunctions.hpp"

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::fixed;
using std::string;
using std::stringstream;



void print(Student students[], int studKiek);



void userInputProgram(){


    int studKiek, pazKiek;
    bool makeRandom;

    cout<<"Sveiki, prasome ivesti Studentu kieki!"<<endl;
    while(1){
        cin>>studKiek;
        if(studKiek<=0 || cin.fail()){
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }
        else break;
    }
    
    Student students[studKiek];


    makeRandom = question("Ar norite kad studentai butu atsitiktinai sugeneruoti? ");

    for(int i = 0; i<studKiek; i++){

        vector <double> grades;
        double examRez;

        if(makeRandom == 1) students[i].makeRandom();
    
        else{

            cout<<"Iveskite, varda pavarde "<<endl;
            cin>>students[i].fName>>students[i].lName;
            cinClean();

           cout<<"Iveskite, namu darbu pazymius, norint uzbaigti ivedima (-1)"<<endl;
           while(1){
        
               double grade;
               cin>>grade;

               if(cin.fail() || grade>10){
                    cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
                    cinClean();
                    continue;
               }
               else if( grade<0) break;
                else grades.push_back(grade);
            
           }
            cinClean();


           cout<<"Iveskite egzamino rezultata "<<endl;
           while(1){
               cin>>examRez;
               if(cin.fail() || examRez>10){
                    cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
                    cinClean();
               }
             
                else break;
           }

           students[i].setFinalGrade(grades, examRez);  
        }
    }

    print(students,studKiek);

   
}

void print(Student students[], int studKiek){
   

    stringstream outputStream;
    outputStream<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n";
    outputStream<<setw(25); outputStream<<std::left<<"vardas ";
    outputStream<<setw(25); outputStream<<std::right<<"pavarde ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Med) ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Vid) "<<'\n';
    string line(100, '-');
    outputStream<<line<<'\n';


    for(int i = 0; i<studKiek; i++){
        outputStream<<setw(25); outputStream<<std::left<<students[i].fName;  //https://www.cplusplus.com/reference/ios/left/
        outputStream<<setw(25); outputStream<<std::right<<students[i].lName;
        outputStream.precision(2);
        outputStream<<fixed;
        outputStream<<setw(25); outputStream<<std::right<<students[i].finalMed;
        outputStream<<setw(25); outputStream<<std::right<<students[i].finalAvrg<<'\n';      
    }

    line = outputStream.str();
    outputStream.str("*");
    cout<<line;

}