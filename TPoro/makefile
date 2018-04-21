.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tporo.o tvectorporo.o tlistaporo.o tabbporo.o tavlporo.o

OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tporo:    src/pporo.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/pporo.cpp $(OBJ) -o tporo
	
tvector:    src/pvector.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/pvector.cpp $(OBJ) -o tvector

tlista:    src/plista.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/plista.cpp $(OBJ) -o tlista

tabb:    src/pabb.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/pabb.cpp $(OBJ) -o tabb

tad01:	src/tad01.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad01.cpp $(OBJ) -o tad0

tad02:	src/tad02.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad02.cpp $(OBJ) -o tad0

tad03:	src/tad03.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad03.cpp $(OBJ) -o tad0
	
tad04:	src/tad04.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad04.cpp $(OBJ) -o tad0
	
tad05:	src/tad05.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad05.cpp $(OBJ) -o tad0
	
tad06:	src/tad06.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad06.cpp $(OBJ) -o tad0
	
tad07:	src/tad07.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad07.cpp $(OBJ) -o tad0
	
tad08:	src/tad08.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad09.cpp $(OBJ) -o tad0
	
tad09:	src/tad09.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad09.cpp $(OBJ) -o tad0
	
tad10:	src/tad10.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad10.cpp $(OBJ) -o tad0



$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

clean:
	rm -f $(OBJ)
	rm -f tporo
	rm -f tvector
	rm -f tad0
	rm -f salida
	rm -f tlista
	rm -f tlistarai
	rm -f tabb
