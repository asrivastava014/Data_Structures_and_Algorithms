math: maths_stuffs.o maths_utils.o
	g++ maths_stuffs.o maths_utils.o -o math
    
maths_stuffs.o: maths_stuffs.cpp
	g++ -c maths_stuffs.cpp
    
maths_utils.o: maths_utils.cpp
	g++ -c maths_utils.cpp
    
clean:
	rm *.o math
