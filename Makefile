main: main.o UserInput.o BasicFunctions.o StudentStruct.o
	cd ProjectFiles && g++ -o my_program.exe UserInput.o main.o BasicFunctions.o StudentStruct.o  && mv my_program.exe ../my_program.exe

main.o:
	cd Source && g++ -c main.cpp && mv main.o ../ProjectFiles/main.o

UserInput.o:
	cd Source && g++ -c UserInput.cpp && mv UserInput.o ../ProjectFiles/UserInput.o

StudentStruct.o:
	cd Source && g++ -c StudentStruct.cpp && mv StudentStruct.o ../ProjectFiles/StudentStruct.o


BasicFunctions.o:
	cd Source && g++ -c BasicFunctions.cpp && mv BasicFunctions.o ../ProjectFiles/BasicFunctions.o

clean:
	cd ProjectFiles &&  rm *.o && cd .. && rm  my_program.exe

remove_o:
	cd ProjectFiles && rm *.o

