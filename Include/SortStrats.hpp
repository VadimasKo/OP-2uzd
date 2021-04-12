#pragma once

#include "../Include/StudentStruct.hpp"

#include <iterator>
#include <algorithm>
#include <list>

template<class T>
void sortStrat1(T &students, T &islaike, T &skolininkai){
    for(typename T::iterator it = students.begin(); it != students.end(); advance(it,1)){
        if(it->finalAvrg <5) skolininkai.push_back(*it);
        else islaike.push_back(*it);
        //I can use transform? twice 
    }
}

template<class T>
void sortStrat2(T &students, T &islaike){

    auto it = students.begin();
    while (it != students.end()){
        if(it->finalAvrg >= 5){
            islaike.push_back(*it);
            it = students.erase(it);
        } else{
            ++it;  // go to next
    }
    }
}

bool havePassed(StudentStruct stud){
    return stud.finalAvrg >= 5;
}

template<class T>
void  sortStrat3(T &students, T &islaike){
    std::sort(students.begin(),students.end());
    typename T::iterator it = find_if(students.begin(), students.end(), havePassed);
    std::copy(it,students.end(), back_inserter(islaike));
    students.resize(students.size()-islaike.size());
}

void sortStrat3(std::list<StudentStruct> &students, std::list<StudentStruct> &islaike){
    students.sort();
    std::list<StudentStruct>::iterator it = students.begin();
    for(const auto& stud : students){
        if(stud.finalAvrg >= 5) break;
        advance(it,1);
    }
    islaike.splice(islaike.begin(), students, it, students.end());
}
 