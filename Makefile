main: main.o UserInput.o BasicFunctions.o StudentStruct.o RandomToFile.o
	cd ProjectFiles && g++ -o my_program.exe UserInput.o main.o BasicFunctions.o StudentStruct.o RandomToFile.o && mv my_program.exe ../my_program.exe

main.o:
	cd Source && g++ -c main.cpp && mv main.o ../ProjectFiles/main.o

UserInput.o:
	cd Source && g++ -c UserInput.cpp && mv UserInput.o ../ProjectFiles/UserInput.o

StudentStruct.o:
	cd Source && g++ -c StudentStruct.cpp && mv StudentStruct.o ../ProjectFiles/StudentStruct.o


BasicFunctions.o:
	cd Source && g++ -c BasicFunctions.cpp && mv BasicFunctions.o ../ProjectFiles/BasicFunctions.o

RandomToFile.o:
	cd Source && g++ -c RandomToFile.cpp && mv RandomToFile.o ../ProjectFiles/RandomToFile.o






clean:
	cd ProjectFiles &&  rm *.o && cd .. && rm  my_program.exe skolinkai.txt islaike.txt

remove_o:
	cd ProjectFiles && rm *.o

unpack:
	mkdir ProjectFiles
