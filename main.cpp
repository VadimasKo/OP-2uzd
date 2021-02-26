#include <sstream>
#include <fstream>
#include "UI.hpp"
#include <exception>

using std::stringstream;
using std::exception;

class StringToDoubleError{};
class GradeValueError{};

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
        
        try{
            fstream data;
            data.open("kursiokai.txt");
            if( data.fail()) throw exception();

            while(!data.eof()){
                string buffString;
                getline(data,buffString);
                buffString.append("\n");
                fileString += buffString;
            }

            data.close();
        }
        catch(const exception& e){
            cout<<"Exception: Unable to open the file"<<endl;
            exit(1);
        }
    
       
        
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

            try{   

                while(!lineStream.eof()){

                double buffDouble;
                lineStream>>buffDouble;

                if(lineStream.fail()) throw StringToDoubleError();
                if(buffDouble<0 || buffDouble>10) throw GradeValueError();


                if(lineStream.eof()) examRez = buffDouble;
                else grades.push_back(buffDouble);

                }
            }
            catch (StringToDoubleError& e){
                cout<<"Exception: Wrong input type in grades, line:"<<students.size()+2<<endl;
                grades.clear();
                continue;
            }
            catch (GradeValueError& e){
                cout<<"Exception: Wrong input grade value, line:"<<students.size()+2<<endl;
                grades.clear();
                continue;
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
    }


    line = outputStream.str();

    ofstream rez;
    rez.open("results.txt");
    rez<<line;
    rez.close();

}
