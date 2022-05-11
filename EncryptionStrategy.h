#ifndef ENCRYPTIONSTRATEGY_H
#define ENCRYPTIONSTRATEGY_H

#include <string>

class EncryptionStrategy {
    public:
        virtual void encrypt(std::string filename) = 0;
        virtual std::string decrypt(std::string dec_string) = 0;
        virtual ~EncryptionStrategy(){};
};

#endif