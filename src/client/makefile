a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: src/*.h src/*.cpp
	g++ -Isrc/ -c src/*.cpp
run:
	./a.out
