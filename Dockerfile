FROM ubuntu:18.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y g++
RUN apt-get install -y make

# RUN apt-get install libcrypto++6 libcrypto++6-dbg libcrypto++-dev
# crypto++ installation

# build library
RUN git clone "https://github.com/weidai11/cryptopp.git"
WORKDIR cryptopp
RUN make -f ./GNUmakefile
RUN cp libcryptopp.a ../

# install library
RUN make -f ./GNUmakefile install

WORKDIR ../

# Clone repo and compile it
RUN git clone "https://github.com/GreysonSpencer/3220-final-project.git" \
    && mv libcryptopp.a "3220-final-project" \
    && cd "3220-final-project" \
    && make

WORKDIR 3220-final-project

RUN ./main