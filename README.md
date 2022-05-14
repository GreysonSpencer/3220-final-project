# 3220-final-project

This project was created for ECE 3220.


# Demo
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