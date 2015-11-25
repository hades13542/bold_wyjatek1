#Makefile i3hujdus
#
#Definicje
FILES = *.cpp *.h #zbieranie plikow
CXXFLAGS = -g -Wall -o #flagi kompilatora
CXX = g++ #kompilator
OUTPUT = output #nazwa pliku

all:
	clear
	$(CXX)$(CXXFLAGS) $(OUTPUT)$(FILES) # tworze plik wykonywalny
clean:
	rm -f $(OUTPUT) # czyszcze plik wykonywalny
oclean:
	rm -f *.o #czyszczenie plikow .o
run:
	./$(OUTPUT) #uruchomienie
	
