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



int main(){
    std::vector<StudentStruct> students;
    std::vector<StudentStruct> islaike;
    std::vector<StudentStruct> skolininkai;
    // generateRecords(100);
    readData(students,"Results/studentai.txt");
    sortStrat1(students,islaike, skolininkai);
    
    print(students,"output.txt");
    print(skolininkai,"skolininkai.txt");
    print(islaike,"islaike.txt");
}