user: user.o main.o
	g++ -o user user.o main.o
    
user.o: user.cpp
	g++ -c user.cpp
    
main.o: main.cpp
	g++ -c main.cpp
    
clean:
	rm *.o user
