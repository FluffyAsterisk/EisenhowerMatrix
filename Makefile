CC=g++

# -ggdb is for bebugging
# -O0 is optimization level
# -pedantic-errors disables compiler extensions
# -DNDEBUG turns off debugging features such as asserts
# -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion insreased warning levels
# -std=c++17 choose language standart

COMPILER_FLAGS_DEBUG=-std=c++17 -static -ggdb -O0 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion
COMPILER_FLAGS_RELEASE=-std=c++17 -static -O2 -DNDEBUG -pedantic-errors 
LINKER_FLAGS=

debug: main.cpp
	$(CC)  $(COMPILER_FLAGS_DEBUG) $(LINKER_FLAGS) main.cpp -o main

release:
	$(CC) $(COMPILER_FLAGS_RELEASE) $(LINKER_FLAGS) main.cpp -o main

clean:
	rm main
