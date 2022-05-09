FROM ubuntu:18.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y g++
RUN apt-get install -y make
RUN git clone "https://github.com/GreysonSpencer/3220-final-project.git" \
    && cd "3220-final-project" \
    && make