a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: include/*.h src/*.cpp
	g++ -Isrc/ -c src/*.cpp -g
run:
	./a.out
