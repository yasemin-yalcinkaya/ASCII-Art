CompileAndRun:Program Run

Program: class file main
	g++ ./lib/class.o ./lib/file.o ./lib/main.o -o ./bin/program
	 
file:
	g++ -I "./include" -c ./src/file.cpp -o ./lib/file.o
class:
	g++ -I "./include" -c ./src/class.cpp -o ./lib/class.o
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

Run:
	./bin/program.exe
