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

# Phony targets are not actual files
.PHONY: all run logs setup clean distclean

# Default target
all: $(TARGET)

# Target to run the shell
run: all
	./$(TARGET)

# Target to view the logs
logs:
	@mkdir -p $(LOG_DIR) 		# Create log directory if it does not exist
	@touch $(LOG_DIR)/shell.log	# Create log file if it does not exist
	@echo "Tailing log file. Press Ctrl+C to exit."
	@tail -f $(LOG_DIR)/shell.log

# Link the object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "Simple Shell executable created as '$(TARGET)'"

# Rule to compile .c source files into .0 object files
# $< is the .c files
# $@ is the .o files
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Project structure setup
setup:
	@echo "---Building Project Structure---"
	@mkdir -p $(SRCS_DIR) $(INCLUDE_DIR) $(LOG_DIR)
	@touch $(SRCS_DIR)/main.c
	@touch $(SRCS_DIR)/shell.c
	@touch $(INCLUDE_DIR)/shell.h
	@touch $(LOG_DIR)/shell.log
	@echo "---Project Structure Created---"

# Removes build artifacts (executable and .o files)
clean:
	@echo "---Cleaning Build Artifacts---"
	@rm -f $(TARGET) $(OBJS)
	@echo "---Build Artifacts Cleaned---"

# Distribution Clean
distclean: clean
	@echo "---Cleaning Up Project Architecture---"
	@rm -rf $(SRCS_DIR) $(INCLUDE_DIR) $(LOG_DIR)
	@echo "---Project Architecture Cleaned---"
