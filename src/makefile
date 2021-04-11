fint: main.o fint.o
	g++ main.o fint.o -std=c++11 -o fint

main.o: main.cpp
	g++ -c main.cpp -std=c++11

fint.o: fint.cpp
	g++ -c fint.cpp -std=c++11

clean:
	rm *.o fint