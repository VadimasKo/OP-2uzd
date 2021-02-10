#include <iostream>
#include <string>
#include <random> // ar reikia?
#include <time.h> 
#include <vector>
#include <algorithm>  //sort
#include <iomanip> // setPrecision

using namespace std;

void cinClean();

class Student{
    private:
        string fName, lName;
        double finalGrade;
    public:
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

double getAverage(vector<double> &grades);
double getMedian(vector<double> &grades);
void getRandomGrades(vector<double> &grades, int pazKiek, double *examRez);
void drawTitle(bool showAvrg);



int main(){

    int studKiek, pazKiek;
    bool showAvrg, makeRandom;


    //gauname pradinius parametrus
    cout<<"Sveiki, prasome ivesti studentu kieki!"<<endl;
    while(1){
        cin>>studKiek;
        if(studKiek<=0 || cin.fail()){
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }
        else break;
    }

    Student studList[studKiek];

    cout<<"Ar norite kad rodytu galutini(vid) y/n  (y-vid / n-med)"<<endl;
    while(1){
        char ans;
        cin>>ans;

        if ( ans == 'Y' || ans == 'y'){
            showAvrg = 1;
            cinClean();
            break;
        }
        else if ( ans == 'n' || ans == 'N'){
            showAvrg = 0;
            cinClean();
            break;
        }
        else {
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }
    }


    cout<<"Ar norite kad pazymiai butu atsitiktinai sugeneruoti? y/n"<<endl;
    while(1){
        char ans;
        cin>>ans;

        if ( ans == 'Y' || ans == 'y'){

            makeRandom = 1;
            cinClean();
            
            cout<<"iveskite pazymiu kieki"<<endl;
            while(1) {
                cin>>pazKiek;
                if(cin.fail()|| pazKiek<=0){
                    cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
                    cinClean();
                }
                else break;
            }


            break;
        }
        else if ( ans == 'n' || ans == 'N'){
            makeRandom = 0;
            cinClean();
            break;
        }
        else {
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }
    }

   
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

       if(showAvrg == 1) namuRez = getAverage(grades);
       else namuRez = getMedian(grades);
        
        cout<<"namu rez     "<<namuRez<<"examRez     "<<examRez<<endl;
        studList[i].setFinalGrade(namuRez, examRez);

   }

    drawTitle(showAvrg);
    for(int i = 0; i< studKiek; i++){
        studList[i].print();
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