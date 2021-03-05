#include "../Include/UserInput.hpp"
#include "../Include/BasicFunctions.hpp"
#include "../Include/RandomToFile.hpp"
#include "../Include/FileToFile.hpp"

#include <iostream>



int main(){

  if(question("Ar norite daryti rankini ivedima? ")) userInputProgram();  
  else fileToFile("kursiokai.txt");
}
