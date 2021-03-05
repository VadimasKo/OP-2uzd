#include "../Include/StudentStruct.hpp"
#include "../Include/RandomToFile.hpp"
#include "../Include/BasicFunctions.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;



void randomToFile(){
    int studKiek;

    cout<<"Iveskite studentu kieki : ";
    while(1){
        cin>>studKiek;
        if(studKiek<=0 || cin.fail()){
            cout<<"Ivestis netinkama, prasome prasome pakartoti ivesti"<<endl;
            cinClean();
        }
        else break;
    }

    vector<Student> skolininkai;
    skolininkai.reserve(studKiek/2);

    vector<Student> islaike;
    islaike.reserve(studKiek/2 + studKiek%2);

    for(int i = 0; i<studKiek; i++){
        Student buffStud;
        buffStud.makeRandom();
        if(buffStud.finalAvrg < 5) skolininkai.push_back(buffStud);
        else islaike.push_back(buffStud);
    }

    print(skolininkai, "skolininkai.txt");
    skolininkai.clear();
    print(islaike, "islaike.txt");
    islaike.clear();

}