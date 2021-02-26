main: main.o UI.o Struct.o
	g++ -o my_program.exe UI.o main.o StudentStruct.o

main.o:
	g++ -c main.cpp

UI.o:
	g++ -c UI.cpp

Struct.o:
	g++ -c StudentStruct.cpp


clean:
	rm main.o my_program.exe UI.o StudentStruct.o results.txt

remove_o:
	rm main.o  UI.o Struct.o