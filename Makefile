main: main.o UserInput.o BasicFunctions.o GenerateRandom.o
	cd ProjectFiles && g++ -o my_program.exe UserInput.o main.o BasicFunctions.o GenerateRandom.o  && mv my_program.exe ../my_program.exe

main.o:
	cd Source && g++ -c main.cpp && mv main.o ../ProjectFiles/main.o

UserInput.o:
	cd Source && g++ -c UserInput.cpp && mv UserInput.o ../ProjectFiles/UserInput.o

GenerateRandom.o:
	cd Source && g++ -c GenerateRandom.cpp && mv GenerateRandom.o ../ProjectFiles/GenerateRandom.o


BasicFunctions.o:
	cd Source && g++ -c BasicFunctions.cpp && mv BasicFunctions.o ../ProjectFiles/BasicFunctions.o

clean:
	cd ProjectFiles &&  rm *.o && cd .. && rm *.o my_program.exe

remove_o:
	cd ProjectFiles && rm *.o

