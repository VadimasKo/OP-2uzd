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
        finalAvrg = ((getMedian(grades)*0.4) + examRez);
    }

    bool operator < (Student &obj) const {
        return (fName < obj.fName);
    }

};

void print(int , int , vector<Student>&student);

int main(){

    if(question("Ar norite daryti rankini ivedima")) userInputProgram();
    else{
        string line;
        fstream data;
        int fNameWidth = 0;
        int lNameWidth = 0;

        data.open("kursiokai.txt");
        while(!data.eof()) getline(data,line);
        data.close();

        stringstream stream(line);
        vector<Student> students;

        getline(stream, line); //get rid of first line
        
        while(!stream.eof()){
            Student buffStud;
            vector<double> grades;
            double examRez;

            getline(stream, line);
            stringstream streamLine (line);

            streamLine>>buffStud.fName>>buffStud.lName;

            if(buffStud.fName.size()>fNameWidth) fNameWidth = buffStud.fName.size();
            else if(buffStud.lName.size()>lNameWidth) lNameWidth = buffStud.lName.size();
        
            while(!streamLine.eof()){
                double buffDouble;

                streamLine>>buffDouble;
                if(streamLine.eof()) examRez = buffDouble;
                else grades.push_back(buffDouble);
            }

            buffStud.setFinalGrade(grades, examRez);

            students.push_back(buffStud);
            grades.clear();
        }

        sort(students.begin(),students.end());
        print(fNameWidth,lNameWidth,students);
    }
}


void print(int fNameWidth, int lNameWidth, vector<Student> &students){
   

    stringstream outputStream;
    outputStream<<setw(fNameWidth+3); outputStream<<std::left<<"vardas";
    outputStream<<setw(lNameWidth+3); outputStream<<std::right<<"pavarde";
    outputStream<<setw(5); outputStream<<std::right<<"Galutinis(Med)";
    outputStream<<setw(5); outputStream<<std::right<<"Galutinis(Vid)"<<'\n';
    string line(16+fNameWidth+lNameWidth, '-');
    outputStream<<line;

    cout<<students.size();

    for(int i = 0; i<students.size(); i++){
        // outputStream<<setw(fNameWidth+3); outputStream<<std::left<<students[i].fName;  //https://www.cplusplus.com/reference/ios/left/
        // outputStream<<setw(lNameWidth+3); outputStream<<std::right<<students[i].lName;
        // outputStream.precision(2);
        // outputStream<<fixed;
        // outputStream<<setw(5); outputStream<<std::right<<students[i].finalMed;
        // outputStream<<setw(5); outputStream<<std::right<<students[i].finalAvrg<<'\n';

        cout<<setw(fNameWidth+3); cout<<std::left<<students[i].fName;  //https://www.cplusplus.com/reference/ios/left/
        cout<<setw(lNameWidth+3); cout<<std::right<<students[i].lName;
        cout.precision(2);
        cout<<fixed;
        cout<<setw(5); cout<<std::right<<students[i].finalMed;
        cout<<setw(5); cout<<std::right<<students[i].finalAvrg<<'\n';
         
         
        
    }

    line = outputStream.str();

    ofstream rez;
    rez.open("results.txt");
    rez<<line;
    rez.close();

}
