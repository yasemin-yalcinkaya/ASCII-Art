CompileAndRun:Program Run

Program: class file ImageConverter01 main resize
	g++  ./lib/resize.o ./lib/class.o ./lib/ImageConverter01.o ./lib/file.o ./lib/main.o -o ./bin/program
	 
file:
	g++ -I "./include" -c ./src/file.cpp -o ./lib/file.o
ImageConverter01:
	g++ -I "./include" -c ./src/ImageConverter01.cpp -o ./lib/ImageConverter01.o
class:
	g++ -I "./include" -c ./src/class.cpp -o ./lib/class.o
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
resize:
	g++ -I "./include" -c ./src/resize.cpp -o ./lib/resize.o	

Run:
	./bin/program.exe
