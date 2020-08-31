user: user.o teacher.o main.o
	g++ -o user user.o teacher.o main.o
    
user.o: user.cpp
	g++ -c user.cpp

teacher.o: teacher.cpp
	g++ -c teacher.cpp	
    
main.o: main.cpp
	g++ -c main.cpp
    
clean:
	rm *.o user
