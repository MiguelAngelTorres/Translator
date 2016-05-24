INCLUDE= include
SRC = src
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -g -c


all: $(BIN)/pruebatraductor
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxygen
	
# ************ Compilación de módulos ************
$(BIN)/pruebatraductor: $(LIB)/libtraductor.a $(OBJ)/pruebatraductor.o
	$(CXX) -o $(BIN)/pruebatraductor $(OBJ)/pruebatraductor.o -I$(INCLUDE) -L$(LIB) -ltraductor	

$(LIB)/libtraductor.a: $(OBJ)/palabra.o $(OBJ)/traductor.o
	ar rvs $(LIB)/libtraductor.a $(OBJ)/palabra.o $(OBJ)/traductor.o

$(OBJ)/pruebatraductor.o: $(SRC)/pruebatraductor.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebatraductor.o $(SRC)/pruebatraductor.cpp -I$(INCLUDE)

$(OBJ)/traductor.o: $(SRC)/traductor.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/traductor.o $(SRC)/traductor.cpp -I$(INCLUDE)

$(OBJ)/palabra.o: $(SRC)/palabra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/palabra.o $(SRC)/palabra.cpp -I$(INCLUDE)
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INCLUDE)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* doc/latex/* $(LIB)/*
