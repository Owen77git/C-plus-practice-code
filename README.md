# C-plus-practice-code
This journal is the record of my study in the field of C++ programming.   It holds practice code, experiments, small programs and notes as I gradually learn the basics of C++ and advanced concepts of C++.

## how to run it on linux/macos
# Compile with C++17
g++ -std=c++17 -o file_manager file_manager.cpp

# Or with clang
clang++ -std=c++17 -o file_manager file_manager.cpp

# Run
./file_manager

## how to run it on windows
# Using MinGW/g++
g++ -std=c++17 -o file_manager.exe file_manager.cpp

# Using Visual Studio Developer Command Prompt
cl /EHsc /std:c++17 file_manager.cpp

# Run
file_manager.exe


# command examples
> ls -l                    # Detailed listing
> mkdir projects          # Create directory
> touch notes.txt         # Create file
> cat notes.txt           # View file
> cp notes.txt backup.txt # Copy file
> find .cpp               # Search for C++ files
> size Downloads          # Show directory size
> tree                    # Show directory tree
