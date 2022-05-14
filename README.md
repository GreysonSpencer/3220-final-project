# 3220-final-project

# Report
This project was created for ECE 3220. I decided to develop it by myself. The idea that I had for my project initially was a text file encryption tool that can use different kinds of encryption on text files. I have accomplished this by implementing the Crypto++ library into my project. The two encryption schemes supported are AES and RC6. 

# Modes
The two supported modes are menu mode and command line mode. If the executable created by the Makefile is run without any command line arguments, then it will run in menu mode. Menu mode is intended to be more friendly for first time users.

# Dependencies
Using the docker image, all of the correct versions of the required dependencies are already installed.

# Demo showing how to use
Project demo video: https://youtu.be/qsAOwSEFHEM 

# Compilation
To compile and run the application in menu mode:

```bash
make
./main
```

To compile and run the application with flags:

```bash
make
./main <flags>
```

# Testing
To run tests:

```bash
mkdir build
cd build
cmake ../
make
./runTests
```

To run tests and find coverage:

```bash
mkdir build
cd build
cmake ../
make
./runTests
cp CMakeFiles/runTests.dir/tests.cpp.gcda ../tests.gcda
cp CMakeFiles/runTests.dir/tests.cpp.gcno ../tests.gcno
cd ../
gcov tests.cpp
```

To clear out gcov files:

```bash
rm *.gcov tests.gcda tests.gcno
```

# Docker image
Dockerhub repository: 
https://hub.docker.com/repository/docker/greysonspencer/3220-final-project/general