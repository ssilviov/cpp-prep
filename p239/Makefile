# Compiler settings
CXX      := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wunreachable-code
DEBUG_FLAGS := -fsanitize=address,undefined -g

# Target executable name
TARGET   := solution
# Source file
SRC      := solution.cpp

# Default rule: Build with sanitizers for safety
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET)

# Optimized build: No sanitizers, maximum speed (for local benchmarking)
opt: $(SRC)
	$(CXX) $(CXXFLAGS) -march=native -DNDEBUG $(SRC) -o $(TARGET)

# Clean up binaries
clean:
	rm -f $(TARGET)

# Run the solution
run: all
	./$(TARGET)

.PHONY: all opt clean run
