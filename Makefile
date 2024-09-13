# Target executable
exec = simplic.out

# Source files
sources = $(wildcard src/*.c)

# Object files
objects = $(sources:src/%.c=src/%.o)

# Compiler flags
flags = -g

# Rule to build the target executable
$(exec): $(objects)
	gcc $(flags) $(objects) -o $(exec)

# Rule to build object files
src/%.o: src/%.c include/%.h
	gcc -c $(flags) $< -o $@

# install and access the language globally 
install:
	make
	cp ./simplic.out /usr/local/bin/simplic

# Clean up build artifacts
clean:
	-rm -f $(exec) src/*.o
