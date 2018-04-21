.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcalendario.o tvectorcalendario.o tlistacalendario.o tabbcalendario.o tavlcalendario.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad:    src/pcalendario.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/pcalendario.cpp $(OBJ) -o tad

tad2:    src/pvector.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/pvector.cpp $(OBJ) -o tad2

tad3:    src/plistacalendario.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/plistacalendario.cpp $(OBJ) -o tad3

tad4:    src/pabbcalendario.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/pabbcalendario.cpp $(OBJ) -o tad4

tadcalendario:    src/tadcalendario.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tadcalendario.cpp $(OBJ) -o tadcalendario

tadvectorcalen:    src/tadvectorcalen.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tadvectorcalen.cpp $(OBJ) -o tadvectorcalen

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
	rm -f salida
	rm -f tad
	rm -f tad0
	rm -f tad2
	rm -f tad3
	rm -f tad4
	rm -f tadcalendario
	rm -f tavectorcalen