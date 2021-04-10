#pragma once
#include <chrono>
#include <string>

class Timer{
    using highResClock = std::chrono::high_resolution_clock;
    using timePoint = std::chrono::time_point<highResClock>;
    using durationDouble =  std::chrono::duration<double>;

    private:
        timePoint start;
        durationDouble input, sort, output;

    public:
        void startClock();
        void calcInput();
        void calcSort();
        void calcOutput();
        double giveDuration();
        void printRes(bool showTitle, std::string name);
};