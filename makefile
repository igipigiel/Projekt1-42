start:a.out
	./a.out
a.out : main.o
	g++ main.o
main.o: main.cpp zbior4.h zbior4metody.cpp testy.h testy.cpp
	g++ -c -Wall -pedantic main.cpp
clean:
	rm -f *.out *.o