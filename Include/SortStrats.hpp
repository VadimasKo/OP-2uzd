#pragma once

#include "../Include/StudentStruct.hpp"

#include <iterator>

template<class T>
void sortStrat1(T &students, T &islaike, T &skolininkai){
    for(typename T::iterator it = students.begin(); it != students.end(); advance(it,1)){
        if(it->finalAvrg <5) skolininkai.push_back(*it);
        else islaike.push_back(*it);
    }
}

template<class T>
void sortStrat2(T &students, T &islaike){
    for(typename T::iterator it = students.begin(); it != students.end(); advance(it,1)){
        if(it->finalAvrg >= 5) {
            islaike.push_back(*it);
            students.erase(it);
        }
    }
}

// template<class T>
// void sortStrat3();