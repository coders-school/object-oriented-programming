PROGRAM = SHM

all: $(PROGRAM)

CC = g++

CFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Wconversion -Werror -O2

OBJECTS = Ship.o Cargo.o Map.o SHM.o

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

run:  $(PROGRAM)
	@echo Running program ...
	./$(PROGRAM)

clean:
	rm -f $(OBJECTS) $(PROGRAM)

.PHONY: all clean
