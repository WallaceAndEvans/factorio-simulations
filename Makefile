# Declaration of variables
CC=g++
CC_FLAGS=-W -Wall -Wextra -Werror -g -std=c++0x

# File names
EXEC=run
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) $(CC_FLAGS) -c $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

