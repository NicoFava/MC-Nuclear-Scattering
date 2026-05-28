LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.o Esperimento.o
	g++ -o main main.o Esperimento.o ${LIBS}
main.o: main.cpp RandomGen.h Esperimento.h 
	g++ -c -o main.o main.cpp ${INCS} 
Esperimento.o: Esperimento.cpp Esperimento.h RandomGen.h
	g++ -c -o Esperimento.o Esperimento.cpp
clean:
	rm *.o