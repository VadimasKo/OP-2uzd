#include "../Include/UserInput.hpp"
#include "../Include/BasicFunctions.hpp"
#include "../Include/RandomToFile.hpp"
#include "../Include/FileToFile.hpp"

#include <iostream>
#include <string>


int main(int argc, char **argv){

  if(argc > 1) fileToFile(argv[1]);
  else{
    if(question("Ar norite daryti rankini ivedima? ")) userInputProgram();  
    else if(question("Ar norite kad studentai butu atsitiktinai sugeneruoti?")) randomToFile();
    else{
        if (question("Ar norite padaryti ivesti is failo??? ")){
          std::cout<<"iveskite failo pavadinima: ";
          std::string file;
          std::cin>>file;
          fileToFile(file);
        }
        else std::cout<<"Okey........"<<std::endl;
    }
  }

 
}
