CXX = g++
CXXFLAGS = -ansi -pedantic -Wall -std=c++11
LDFLAGS =
EXEC = lalr_parser
SOURCE = src/
BINARY = bin/
SRC = $(wildcard $(SOURCE)*.cpp)
HDR = $(wildcard $(SOURCE)*.h)
OBJ = $(patsubst $(SOURCE)%.cpp,$(BINARY)%.o, $(SRC))
$(shell   mkdir -p $(BINARY))

all: $(EXEC)

lalr_parser: $(OBJ) # édition des liens
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BINARY)%.o: $(SOURCE)%.cpp $(SOURCE)%.h # compilations classiques
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(BINARY)main.o: $(SOURCE)main.cpp $(SOURCE)lexer.h # compilation
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(BINARY)Automate.o: $(SOURCE)Automate.cpp $(SOURCE)lexer.h # compilation
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(BINARY)Etat.o: $(SOURCE)Etat.cpp $(SOURCE)Automate.h # compilation
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(BINARY)lexer.o: $(SOURCE)lexer.cpp $(SOURCE)symbole.h # compilation
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(BINARY)symbole.o: $(SOURCE)symbole.cpp # compilation
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	rm $(BINARY)*

mrproper:
	rm $(BINARY)* $(EXEC)

# https://gl.developpez.com/tutoriel/outil/makefile/