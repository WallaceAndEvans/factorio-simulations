# Declaration of variables
CC=g++
#CC_FLAGS=-W -Wall -Wextra -Werror -g -std=c++0x
CC_FLAGS=-W -Wall -Wextra -Werror -g -std=c++17

# File names
EXEC=factorio-sim
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:src/%.cpp=build/%.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
build/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

