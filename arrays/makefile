# Compiler
CC = clang
CFLAGS = -Wall -Wextra -std=c11 -g  # Enable warnings and debugging

# Target Executable
TARGET = main

# Source and Object Files
SRC = main.c vector.c
OBJ = $(SRC:.c=.o)  # Converts .c files to .o files automatically

# Default Rule: Compile Everything
all: $(TARGET)

# Linking Step: Create Executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compilation Step: Convert .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

# Clean Up Object Files and Executable
clean:
	rm -f $(OBJ) $(TARGET)

# Debugging with LLDB (Clang's Debugger)
debug: all
	lldb ./$(TARGET)