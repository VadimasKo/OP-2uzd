#include <iostream>
#include <string>
#include <random> // ar reikia?
#include <time.h> 
#include <algorithm>  //sort
#include <iomanip>  //setPrecision

using namespace std;

void cinClean();

struct Student{ // make struct   all - public

    string fName, lName;
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

double getAverage(double [], int);  
double getMedian(double [], int);
void getRandomGrades(double[], int , double *);
void drawTitle(bool showAvrg);



int main(){

    int studKiek;
    int pazKiek = 0;
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
       double *grades = new double[1];
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
                
                double *temp = new double[pazKiek+1];
                //copy
                for(int i = 0; i<pazKiek; i++){
                    temp[i] = grades[i];
                }
                //delete old
                delete [] grades;
                //add new value
                temp[pazKiek] = grade;
                grades = temp;
                

            
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

       if(showAvrg == 1) namuRez = getAverage(grades, pazKiek);
       else namuRez = getMedian(grades, pazKiek);
    
        studList[i].setFinalGrade(namuRez, examRez);

        delete [] grades;

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

double getAverage(double grades[], int pazKiek){
    double sum = 0;
    pazKiek++; //kad rodytu skaiciu o ne masyvo vieta

    for(int i = 0; i<pazKiek; i++){
        sum += grades[i];
    }

    return sum/pazKiek;
}

double getMedian(double grades[], int pazKiek){
    double median;
    pazKiek++; // kad rodytu skaiciu o ne masyvo vieta

    sort(grades, grades+pazKiek);

    if(pazKiek%2 == 1) median = grades[pazKiek/2];
    
    else  median = grades[pazKiek/2] + grades[(pazKiek/2)- 1];

    return median;
   
}

void getRandomGrades(double grades[], int pazKiek, double *examRez){
    srand(time(0));
    for(int i = 0; i<pazKiek; i++){
        grades[i] = rand()%11;
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