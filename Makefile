all: dsa172a2

DEFS = -DUSE_SOME_DEF

dsa172a2: dbLib.o requestLib.o main.o processData.o
	g++ main.o dbLib.o requestLib.o processData.o -std=c++11 -o dsa172a2 $(DEFS)
main.o: main.cpp dsaLib.h dbLib.h
	g++ -c main.cpp -std=c++11 $(DEFS)
requestLib.o: requestLib.cpp requestLib.h dsaLib.h
	g++ -c requestLib.cpp -std=c++11 $(DEFS)
dbLib.o: dbLib.cpp dbLib.h dsaLib.h requestLib.h
	g++ -c dbLib.cpp -std=c++11 $(DEFS)
processData.o: processData.cpp dsaLib.h requestLib.h dbLib.h
	g++ -c processData.cpp -std=c++11 $(DEFS)

clean:
	rm *.o dsa172a2
