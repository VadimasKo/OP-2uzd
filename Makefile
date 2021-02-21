main: main.o UI.o
	g++ -o my_program.exe UI.o main.o

main.o:
	g++ -c main.cpp

UI.o:
	g++ -c UI.cpp

clean:
	rm main.o my_program.exe UI.o