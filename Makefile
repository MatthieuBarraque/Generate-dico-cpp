# Makefile
all: generate_dico

generate_dico: generate_dico.cpp
    g++ -o generate_dico generate_dico.cpp

clean:
    rm -f generate_dico