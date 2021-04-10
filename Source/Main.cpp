#include "../Include/Timer.hpp"
#include "../Include/GenerateRecords.hpp"

#include <iostream>


int main(){
    Timer timer;

    // timer.startClock();
    // timer.calcInput();
    // timer.startClock();
    // timer.calcSort();
    // timer.startClock();
    // timer.calcOutput();

    // timer.printRes(true,"Strategija Nr1");
    // timer.printRes(false,"Strategija Nr2");
    // timer.printRes(false,"Strategija Nr3");
    timer.startClock();
    generateRecords(10000000);
    std::cout<<timer.giveDuration();
}