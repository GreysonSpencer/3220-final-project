FROM ubuntu:18.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y g++
RUN apt-get install -y make
# crypto++ installation
RUN apt-get install libcrypto++6 libcrypto++6-dbg libcrypto++-dev -y

# Clone repo and compile it
RUN git clone "https://github.com/GreysonSpencer/3220-final-project.git"
WORKDIR 3220-final-project
RUN make