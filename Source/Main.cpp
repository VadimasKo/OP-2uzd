#include "../Include/Timer.hpp"
#include "../Include/GenerateRecords.hpp"
#include "../Include/StudentStruct.hpp"
#include "../Include/InputOutput.hpp"
#include "../Include/SortStrats.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <vector>
#include <string>

std::string fileName = "Results/studentai.txt";

void cinClean(){
    std::cin.clear();
    std::cin.ignore(10000, '\n'); 
}

template <class T>
void callingStrat1(T &students, T &islaike, T &skolininkai){
   Timer timer;
   timer.startClock();
            readData(students,fileName);
            timer.calcInput();

            timer.startClock();
            sortStrat1(students,islaike,skolininkai);
            timer.calcSort();

            timer.startClock();
            print(islaike,"islaike.txt");
            print(skolininkai,"skolininkai.txt");
            timer.calcOutput();

            students.clear();
            islaike.clear();
            skolininkai.clear();
            timer.printRes(1,"strat1");
}

template <class T>
void callingStrat2(T &students, T &islaike){
    Timer timer;
    timer.startClock();
            readData(students,fileName);
            timer.calcInput();

            timer.startClock();
            sortStrat2(students,islaike);
            timer.calcSort();

            timer.startClock();
            print(islaike,"islaike.txt");
            print(students,"skolininkai.txt");
            timer.calcOutput();

            students.clear();
            islaike.clear();
            timer.printRes(0,"strat2");
}

template <class T>
void callingStrat3(T &students, T &islaike){
    Timer timer;
    timer.startClock();
            readData(students,fileName);
            timer.calcInput();

            timer.startClock();
            sortStrat3(students,islaike);
            timer.calcSort();

            timer.startClock();
            print(islaike,"islaike.txt");
            print(students,"skolininkai.txt");
            timer.calcOutput();

            students.clear();
            islaike.clear();
            timer.printRes(0,"strat3");
}

template <class T>
void executingStrats(T &students, T &islaike, T &skolininkai){
    callingStrat1(students,islaike,skolininkai);
    callingStrat2(students,islaike);
    callingStrat3(students,islaike);
}




int main(){
    using std::cout;
    using std::cin;
    int selection;
    int studKiek = 0;

    cout<<"\n";
    cout<<"1. Generate and sort new records"<<"\n";
    cout<<"2. Sort existing records"<<"\n";
    cout<<"Select: ->";
    cin>>selection;

    cinClean();

    if(selection == 1){
        cout<<"\n";
        cout<<"Choose how many Students to create"<<"\n";  
        cout<<"1. 10 000"<<"\n";
        cout<<"2. 100 000"<<"\n";
        cout<<"3. 1 000 000"<<"\n";
        cout<<"4. 10 000 000"<<"\n";
        cout<<"5. custom amount"<<"\n";
        cout<<"Select: ->";
        cin>>selection;

        
        if(selection == 1) studKiek = 10000;
        if(selection == 2) studKiek = 100000;
        if(selection == 3) studKiek = 1000000;
        if(selection == 4) studKiek = 10000000;
        if(selection == 5){ 
                cout<<"\n";
            while(1){
                cout<<"Enter amount of Students: ";
                cin>>studKiek;
                if(studKiek<= 0 || cin.fail()){
                    cout<<"Input is incorect"<<"\n";
                    cinClean();
                }
                else break;
            }     
        }
        cout<<"generating "<<studKiek<<" students..."<<"\n";
        generateRecords(studKiek);
    }
    else if( selection == 2){
        cout<<"\n";
        cout<<"Enter the name of file (relative): ";
        cin>>fileName; 
    }
    
    {
        cout<<"\n";
        cout<<"sorting using vectors..."<<"\n";
        std::vector<StudentStruct> students,islaike,skolininkai;
        executingStrats(students,islaike,skolininkai);
    }
    {
        cout<<"\n";
        cout<<"sorting using deque..."<<"\n";
        std::deque<StudentStruct> students,islaike,skolininkai;
        executingStrats(students,islaike,skolininkai);
    }  
    {
        cout<<"\n";
        cout<<"sorting using list..."<<"\n";
        std::list<StudentStruct> students,islaike,skolininkai;
        executingStrats(students,islaike,skolininkai);
    }
        
}

