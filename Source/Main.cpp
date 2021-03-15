#include <iostream>

#include "../Include/GenerateRecords.hpp"
#include "../Include/SortToFile.hpp"

using std::cin;
using std::cout;
using std::endl;



int main(){
    // int selection;
    // cout<<"\n";
    // cout<<"1. Generate and sort new records"<<endl;
    // cout<<"2. Sort existing records"<<endl;
    // cout<<"3. Enter grades manualy"<<endl;
    // cout<<"Select: ->";
    // cin>>selection;

    generateRecords(150);
    // sortToFileVector("studentai.txt");
    // sortToFileDeque("studentai.txt");
    sortToFileList("studentai.txt");

    // if(selection == 1) generateSortSelection();
    // else if(selection == 2) sortRecordsSelection();
    // else userInputProgram();
}


// void generateSortSelection(){
//     int selection;
//     cout<<"\n";
//     cout<<"Choose how many Students to create"<<endl;  
//     cout<<"1. 10 000"<<endl;
//     cout<<"2. 100 000"<<endl;
//     cout<<"3. 1 000 000"<<endl;
//     cout<<"4. 10 000 000"<<endl;
//     cout<<"5. custom amount"<<endl;
//     cout<<"Select: ->";
//     cin>>selection;

//     int studKiek = 0;

//     if(selection == 1) studKiek = 10000;
//     if(selection == 2) studKiek = 100000;
//     if(selection == 3) studKiek = 1000000;
//     if(selection == 4) studKiek = 10000000;
//     if(selection == 5){ 
//         cout<<"\n";
//     while(1){
//         cout<<"Enter amount of Students: ";
//         cin>>studKiek;
//         if(studKiek<= 0 || cin.fail()){
//             cout<<"Input is incorect"<<endl;
//             cinClean();
//         }
//         else break;
//     }
//     }

//     cout<<"\n"<<"\n";

//     randomToFile(studKiek);
//     fileToFile("studentai.txt");
 
// }


// void sortRecordsSelection(){
//     int selection;
//     string fileName;

//     cout<<"\n";
//     cout<<"Choose which file to open:"<<endl;  
//     cout<<"1. studentai10 000.txt"<<endl;
//     cout<<"2. studentai100 000.txt"<<endl;
//     cout<<"3. kursiokai.txt"<<endl;
//     cout<<"4. other file"<<endl;
//     cout<<"Select: ->";
//     cin>>selection;


//     if(selection == 1) fileName = "studentai10000.txt";
//     if(selection == 2) fileName = "studentai100000.txt";
//     if(selection == 3) fileName = "kursiokai.txt";
//     if(selection == 4){ 
//         cout<<"\n";
//         cout<<"Enter the name of file: ";
//         cin>>fileName; 
//     }

//     cout<<"\n"<<"\n";

//     fileToFile(fileName);
// }