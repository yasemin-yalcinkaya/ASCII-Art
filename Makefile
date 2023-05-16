CompileAndRun:Program Run

Program: class file main raw2array
	g++  ./lib/raw2array.o ./lib/class.o ./lib/file.o ./lib/main.o -o ./bin/program
	 
file:
	g++ -I "./include" -c ./src/file.cpp -o ./lib/file.o
class:
	g++ -I "./include" -c ./src/class.cpp -o ./lib/class.o
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
raw2array:
	g++ -I "./include" -c ./src/raw2array.cpp -o ./lib/raw2array.o	

Run:
	./bin/program.exe
