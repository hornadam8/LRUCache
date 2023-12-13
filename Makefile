# Makefile

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17

# Object files
OBJ = DoublyLinkedList.o LruCache.o

# Executable name
EXEC = lru

# Default target
all: $(EXEC)

# Link the final executable
$(EXEC): $(OBJ) SlowFunctions.o main.o
	$(CXX) $(CXXFLAGS) SlowFunctions.o main.o $(OBJ) -o $(EXEC)

# Compile DoublyLinkedList
DoublyLinkedList.o: DoublyLinkedList.cpp
	$(CXX) $(CXXFLAGS) -c DoublyLinkedList.cpp -o DoublyLinkedList.o

# Compile LruCache
LruCache.o: LruCache.cpp
	$(CXX) $(CXXFLAGS) -c LruCache.cpp -o LruCache.o

# Compile SlowFunctions
SlowFunctions.o: SlowFunctions.cpp
	$(CXX) $(CXXFLAGS) -c SlowFunctions.cpp -o SlowFunctions.o

# Compile main
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Clean the build
clean:
	rm -f $(OBJ) SlowFunctions.o main.o $(EXEC)

.PHONY: all clean