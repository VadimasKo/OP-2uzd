#include "../Include/Timer.hpp"

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>

void Timer::startClock() { start = highResClock::now();}
void Timer::calcInput(){ input = highResClock::now() - start; }
void Timer::calcSort(){ sort = highResClock::now() - start; }
void Timer::calcOutput(){ output = highResClock::now() - start;}

void Timer::printRes(bool showTitle, std::string name){
    using std::setw;

    if(showTitle) std::cout<<std::left<<setw(20)<<" "<<setw(20)<<"Input dur."<<setw(20)<<"Sort dur."<<setw(20)<<"Output dur."<<"\n";

    std::cout.precision(2);
    std::cout<<std::fixed;
    std::cout<<setw(20)<<std::left<<name<<setw(20)<<input.count()<<setw(20)<<sort.count()<<setw(20)<<output.count()<<"\n";
}
double Timer::giveDuration(){ 
    durationDouble duration = highResClock::now() - start;
    return duration.count();
}

