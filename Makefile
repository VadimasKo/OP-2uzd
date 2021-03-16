main: GenerateRecords.o Main.o SortToFile.o StudentStruct.o
	cd ProjectFiles && g++ -o my_program.exe StudentStruct.o GenerateRecords.o Main.o SortToFile.o && mv my_program.exe ../my_program.exe
Main.o:
	cd Source && g++ -c Main.cpp && mv Main.o ../ProjectFiles/Main.o

GenerateRecords.o:
	cd Source && g++ -c GenerateRecords.cpp && mv GenerateRecords.o ../ProjectFiles/GenerateRecords.o

SortToFile.o:
	cd Source && g++ -c SortToFile.cpp && mv SortToFile.o ../ProjectFiles/SortToFile.o

StudentStruct.o:
	cd Source && g++ -c StudentStruct.cpp && mv StudentStruct.o ../ProjectFiles/StudentStruct.o

clear:
	rm my_program.exe && cd ProjectFiles && rm *.o

clear_Result:
	cd Results && rm *.txt