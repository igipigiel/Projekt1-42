start: ./a.out
main.o: main.cpp zbior4.h testy.h
	g++ main.cpp -std=c++11 -c -o main.o
testy.o: testy.h testy.cpp
	g++ testy.cpp -std=c++11 -c -o testy.o
metody.o: zbior4.h zbior4metody.cpp
	g++ zbior4metody.cpp -std=c++11 -c -o metody.o
a.out : main.o testy.o metody.o
	g++ main.o testy.o metody.o -std=c++11 -o a.out
	./a.out
clean:
	rm -f *.out *.o
