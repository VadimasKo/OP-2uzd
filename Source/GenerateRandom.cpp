#include "../Include/GenerateRandom.hpp"

#include <random>

// #include "../Include/StudentStruct.hpp" //perkelti i headeri

class RandInt{
    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high}{}
        int operator ()() {return dist(mt);} //generuoja int
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;
};

int getRandom(){

    RandInt rnd {0,10};
    int test = rnd();
    return test;
}