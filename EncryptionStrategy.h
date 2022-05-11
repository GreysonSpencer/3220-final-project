#ifndef ENCRYPTIONSTRATEGY_H
#define ENCRYPTIONSTRATEGY_H

#include <string>

class EncryptionStrategy {
    public:
        virtual void encrypt(std::string filename) = 0;
        virtual void decrypt(std::string filename) = 0;
        virtual ~EncryptionStrategy(){};
};

#endif