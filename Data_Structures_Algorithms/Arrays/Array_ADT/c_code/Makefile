array_adt: arr_adt_main.o array_adt.o
	gcc -g arr_adt_main.o array_adt.o -o array_adt

arr_adt_main.o: arr_adt_main.c
	gcc -g -c arr_adt_main.c

array_adt.o: array_adt.c
	gcc -g -c array_adt.c

clean:
	rm -f *.o array_adt
