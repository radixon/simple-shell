# simple-shell
This is a simple shell program created as an introduction to operating system programming.  The simple shell provides basic command-line interface for executing simple commands.

## Features
*   **Command Execution:** Supports executing basic commands with arguments.
*   **Built-in Commands:**
    *   'cd':  Change the current working directory.
    *   'exit':  Terminate the shell.
*   **Logging:**  All commands are logged to a file for debugging purposes.

## Getting Started

### Prerequisites

*   C compiler
*   Make

### Building the Project

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/radixon/simple-shell.git
    cd  simple-shell
    ```

2.  **Initialize the directory structure:**
    Run if clone project structure does not have directories
    ```bash
    make setup
    ```

3.  **Build Project:**
    ```bash
    make
    ```

### Usage

To run the shell, execute the following command:
```bash
make run
```

To view the log file in real-time, open a new terminal:
```bash
make logs
```

To clean up build files:
```bash
make clean
```

## Project Structure
```
simple-shell/
├── .gitignore
├── CMakeLists.text
├── README.md
├── src/
|   ├── main.c
|   └── shell.c
├── include/
|   └── shell.h
├── log/
|   └── shell.log
```

*   src/:   Source code files.
*   include/:   Header files.
*   log/:   Log files.
*   .gitignore: Files to be ignored by Git.
*   CMakeLists.txt: Build instructions for CMake.
*   README.md:  Project documentation.

## Build Artifacts

build/
*.o <br/>
*.out <br/>

## Log Files

log/*.log