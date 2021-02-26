#include "UI.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> //std::sort

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::fixed;


void getRandomGrades(vector<double> &grades, int pazKiek, double *examRez);
void drawTitle(bool showAvrg);


struct UIstudent{

    string fName,lName;
    double finalGrade;

    void setFinalGrade(double namuRez, double examRez){
        finalGrade = (namuRez*0.4) + (examRez*0.6);
    }

    void setName(){
        cout<<"Iveskite Varda Pavarde"<<endl;
        cin>>fName>>lName;
        cinClean();
    }

    void print(){
        cout.precision(2);
        cout<<fixed;
        cout<<lName<<"\t"<<fName<<"\t"<<finalGrade<<endl;
    }
    
};

//------------main block------------------------
void userInputProgram(){

    int studKiek, pazKiek;
    bool showAvrg, makeRandom;

    //gauname pradinius parametrus
    cout<<"Sveiki, prasome ivesti Studentu kieki!"<<endl;
    while(1){
        cin>>studKiek;
        if(studKiek<=0 || cin.fail()){
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }
        else break;
    }

    UIstudent studList[studKiek];

    showAvrg = question("Ar norite kad rodytu galutini(vid) (y-vid / n-med)");
    makeRandom = question("Ar norite kad pazymiai butu atsitiktinai sugeneruoti? y/n");
    

   
   for(int i = 0; i<studKiek; i++){
       vector <double> grades;
       double examRez;
       double namuRez; //bendras namu darbu rez vid/med


       if(makeRandom == 1){
            studList[i].setName();
          getRandomGrades(grades,pazKiek, &examRez);

       }
       else{
           studList[i].setName();
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



       }

       if(showAvrg == 1) 
            if(pazKiek == 0) namuRez = 0;
            else namuRez = getAverage(grades);
       else
            if(pazKiek == 0) namuRez = 0;
            else namuRez = getMedian(grades);
        
        studList[i].setFinalGrade(namuRez, examRez);

        grades.clear();
   }

    drawTitle(showAvrg);
    for(int i = 0; i< studKiek; i++){
        studList[i].print();
    }

}
//------------main block------------------------
bool question(string message){
    cout<<message<<endl;

    while(1){
        char ans;
        cin>>ans;

        if ( ans == 'Y' || ans == 'y'){
            cinClean();
            return 1;
        }
        else if ( ans == 'n' || ans == 'N'){
            cinClean();
            return 0;
        }
        else {
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }

    }
}

void cinClean(){
    cin.clear();
    cin.ignore(10000, '\n'); 
}

double getAverage(vector<double> &grades){
    double sum = 0;

    for(int i = 0; i<grades.size(); i++){
        sum += grades[i];
    }

    return sum/grades.size();
}

double getMedian(vector<double> &grades){
    double median;

    sort(grades.begin(), grades.end());

    if(grades.size()%2 == 1) median = grades[grades.size()/2];
    
    else  median = grades[grades.size()/2] + grades[(grades.size()/2)- 1];

    return median;
   
}

void getRandomGrades(vector<double> &grades, int pazKiek, double *examRez){
    srand(time(0));
    grades.reserve(pazKiek);
    for(int i = 0; i<pazKiek; i++){
        grades.push_back(rand()%11);
    } 

    *examRez = rand()%11;
}

void drawTitle(bool showAvrg){
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    
    cout<<"pavarde"<<"\t"<<"vardas"<<"\t";
    if(showAvrg==0) cout<<"galutinis(med.)"<<endl;
    else  cout<<"galutinis(vid.)"<<endl;
    cout<<"-----------------------------"<<endl;
}