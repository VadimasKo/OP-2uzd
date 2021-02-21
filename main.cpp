#include <sstream>
#include <fstream>
#include "UI.hpp"

using std::stringstream;

struct Student{
    string fName, lName;
    double finalMed, finalAvrg;


    void setFinalGrade(vector<double> &grades, double examRez){
        examRez *= 0.6;
        finalAvrg = ((getAverage(grades)*0.4) + examRez);
        finalMed = ((getMedian(grades)*0.4) + examRez);
    }

    bool operator < (Student &obj) const {
        return (fName < obj.fName);
    }

};

void print(int , int , vector<Student>&student);

int main(){

    if(question("Ar norite daryti rankini ivedima? y/n")) userInputProgram();
    else{

        vector<Student> students;
        int fNameWidth = 0;
        int lNameWidth = 0;
        
        string fileString;
        fstream data;
        data.open("kursiokai.txt");

        while(!data.eof()){
            string buffString;
            getline(data,buffString);
            buffString.append("\n");
            fileString += buffString;
        }

        data.close();
        
        stringstream fileStream(fileString);
        
        getline(fileStream,fileString); //getting rid of first line, and emptying fileString 

    
        while(!fileStream.eof()){

            string line;
                getline(fileStream,line);
            
            if(fileStream.eof()) break;     //stream.eof() ==1 only after reading past end
            
            stringstream lineStream(line); 

                
            
            vector <double> grades;
            Student buffStud;
            double examRez;

            lineStream>>buffStud.fName>>buffStud.lName;
            // if(buffStud.fName.size() > fNameWidth) fNameWidth =buffStud.fName.size;
            //  if(buffStud.lName.size() > fNameWidth) lNameWidth =buffStud.lName.size;

            while(!lineStream.eof()){

                double buffDouble;
                lineStream>>buffDouble;

                if(lineStream.eof()) examRez = buffDouble;
                else grades.push_back(buffDouble);

            }

            buffStud.setFinalGrade(grades,examRez);
            grades.clear();

            students.push_back(buffStud);

            //  cout<<buffStud.fName<<"  "<<buffStud.lName<<"  "<<buffStud.finalMed<<"  "<<buffStud.finalAvrg<<endl;    
        }

        sort(students.begin(),students.end());
        
        // print(fNameWidth,lNameWidth,students);
        print(25,25,students);
        


    }
}


void print(int fNameWidth, int lNameWidth, vector<Student> &students){
   

    stringstream outputStream;
    outputStream<<setw(fNameWidth+3); outputStream<<std::left<<"vardas ";
    outputStream<<setw(lNameWidth+3); outputStream<<std::right<<"pavarde ";
    outputStream<<setw(15); outputStream<<std::right<<"Galutinis(Med) ";
    outputStream<<setw(15); outputStream<<std::right<<"Galutinis(Vid) "<<'\n';
    string line(36+fNameWidth+lNameWidth, '-');
    outputStream<<line<<'\n';


    for(int i = 0; i<students.size(); i++){
        outputStream<<setw(fNameWidth+3); outputStream<<std::left<<students[i].fName;  //https://www.cplusplus.com/reference/ios/left/
        outputStream<<setw(lNameWidth+3); outputStream<<std::right<<students[i].lName;
        outputStream.precision(2);
        outputStream<<fixed;
        outputStream<<setw(15); outputStream<<std::right<<students[i].finalMed;
        outputStream<<setw(15); outputStream<<std::right<<students[i].finalAvrg<<'\n';

        // cout<<setw(fNameWidth+3); cout<<std::left<<students[i].fName;  //https://www.cplusplus.com/reference/ios/left/
        // cout<<setw(lNameWidth+3); cout<<std::right<<students[i].lName;
        // cout.precision(2);
        // cout<<fixed;
        // cout<<setw(7); cout<<std::right<<students[i].finalMed;
        // cout<<setw(7); cout<<std::right<<students[i].finalAvrg<<'\n';
         
         
        
    }


    line = outputStream.str();

    ofstream rez;
    rez.open("results.txt");
    rez<<line;
    rez.close();

}
