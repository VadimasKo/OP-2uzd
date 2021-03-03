#include "../Include/UserInput.hpp"
#include "../Include/BasicFunctions.hpp"
#include "../Include/StudentStruct.hpp"


#include <iostream>

int main(){

    Student students(4);
    std::cout<<students.fName<<" "<<students.lName<<" "<<students.finalMed<<" "<<students.finalAvrg;
}