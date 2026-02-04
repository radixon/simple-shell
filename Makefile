# Makefile
########################

# Compiler and Compiler Flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

# Project Directories and Files
SRCS_DIR = src
INCLUDE_DIR = include
LOG_DIR = log
TARGET = simple_shell

# Find .c files in the source directory
SRCS = $(wildcard $(SRCS_DIR)/*.c)

# Replace the .c extensions with .oto get object file names
OBJS = $(SRCS:.c=.o)

# Project structure setup
setup:
	@echo "---Building Project Structure---"
	@mkdir -p src include log
	@touch src/main.c
	@touch include/shell.h
	@touch log/shell.log
	@echo "---Project Structure Created--"
	
# Default target
all: $(TARGET)

# Link the object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "Simple Shell executable created as '$(TARGET)'"

# Rule to compile .c source files into .0 object files
%.o: %.c
# $< is the .c files
# $@ is the .o files
	$(CC) $(CFLAGS) -c $< -o $@

# Target to run the shell
run: all
	./$(TARGET)

# Target to view the logs
logs:
	@mkdir -p $(LOG_DIR) 		# Create log directory if it does not exist
	@touch $(LOG_DIR)/shell.log	# Create log file if it does not exist
	@echo "Tailing log file. Press Ctrl+C to exit."
	@tail -f $(LOG_DIR)/shell.log

# Target to clean up the project directory
clean:
	rm -f $(TARGET) $(SRCS_DIR)/*.o
	@echo "Cleaned build artifacts."

# Phony targets are not actual files
.PHONY: all run logs clean