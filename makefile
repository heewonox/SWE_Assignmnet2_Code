# Compiler
CXX = clang++

# Compiler flags
#CXXFLAGS = -Wall -std=c++17 -O2
CXXFLAGS = -g -fcolor-diagnostics -fansi-escape-codes

# Source files
SRCS = jasal.cpp controls.cpp elements.cpp

# Object files (automatically replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = jasal

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Compile each .cpp to .o
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f output.txt

# Optional: phony targets
.PHONY: all clean
