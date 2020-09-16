array_adt: arr_adt_main.o array_adt.o
	g++ -g -std=c++11 arr_adt_main.o array_adt.o -o array_adt

arr_adt_main.o: arr_adt_main.cpp
	g++ -g -std=c++11 -c arr_adt_main.cpp

array_adt.o: array_adt.cpp
	g++ -g -std=c++11 -c array_adt.cpp

clean:
	rm -f *.o array_adt
