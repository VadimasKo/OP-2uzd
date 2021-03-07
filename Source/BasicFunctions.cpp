#include "../Include/BasicFunctions.hpp"
#include "../Include/StudentStruct.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using std::setw;
using std::fixed;
using std::stringstream;
using std::ofstream;



using std::vector;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::string;


double getAverage(vector<double> &grades){
    double sum = 0;

    for(int i = 0; i<grades.size(); i++) sum +=grades[i];

    if(sum==0) return sum;
    else   return sum/grades.size();
}

double getMedian(vector<double> &grades){
    sort(grades.begin(), grades.end());

    if(grades.size()==0) return 0;
    else{

        if(grades.size()%2 == 1) return grades[grades.size()/2];
        else  return grades[grades.size()/2] + grades[(grades.size()/2)- 1];
    }
        
}


void cinClean(){
    cin.clear();
    cin.ignore(10000, '\n'); 
}


bool question(string message){
    cout<<message<<" y/n ";

    while(1){
        char ans;
        cin>>ans;

        if ( ans == 'Y' || ans == 'y'){
            cinClean();
            return 1;
        }
        else if ( ans == 'N' || ans == 'n'){
            cinClean();
            return 0;
        }
        else {
            cout<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }

    }
}

void print(vector<Student> &students, string file, bool title){
   

    stringstream outputStream;
    outputStream<<setw(25); outputStream<<std::left<<"vardas ";
    outputStream<<setw(25); outputStream<<std::right<<"pavarde ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Med) ";
    outputStream<<setw(25); outputStream<<std::right<<"Galutinis(Vid) "<<'\n';
    
    string line(100, '-');
    
    if(title == 1) outputStream<<line<<'\n';
    
    


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
    rez.open(file);
    rez<<line;
    rez.close();

}