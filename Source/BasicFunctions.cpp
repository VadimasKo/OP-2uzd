#include "../Include/BasicFunctions.hpp"

#include <algorithm>
#include <iostream>


using std::vector;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::string;


double getAverage(vector<double> &grades){
    double sum = 0;

    for(int i = 0; i<grades.size(); i++) sum +=grades[i];

    return sum;
}

double getMedian(vector<double> &grades){
    sort(grades.begin(), grades.end());

    if(grades.size()%2 == 1) return grades[grades.size()/2];

    else  return grades[grades.size()/2] + grades[(grades.size()/2)- 1];
}


void cinClean(){
    cin.clear();
    cin.ignore(10000, '\n'); 
}


bool question(string message){
    cout<<message<<" y/n "<<endl;

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
            cout<<"\t"<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }

    }
}