#pragma once

#include "StudentStruct.hpp"
#include "Timer.hpp"

#include <string>

template<class T>
void sortToFile(std::string fileName, void (*sortFunction)(T &students, Timer &timer), Timer &timer);

template<class T>
void sortStrat1(T &students, Timer &timer);

template<class T>
void sortStrat2(T &students, Timer &timer);

template<class T>
void sortStrat3(T &students, Timer &timer);