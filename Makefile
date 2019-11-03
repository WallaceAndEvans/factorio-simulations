# Declaration of variables
CC=g++
#CC_FLAGS=-W -Wall -Wextra -Werror -g -std=c++0x
CC_FLAGS=-W -Wall -Wextra -Werror -g -std=c++17

# File names
EXEC=factorio-sim
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) $(CC_FLAGS) -c $< -o $@

# Recompile on changes to headers as well
%.cpp: %.h
	touch *.cpp

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

