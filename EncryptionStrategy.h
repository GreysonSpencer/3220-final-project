#ifndef ENCRYPTIONSTRATEGY_H
#define ENCRYPTIONSTRATEGY_H

#include <string>

class EncryptionStrategy {
    public:
        virtual std::string encrypt(std::string enc_string) = 0;
        virtual std::string decrypt(std::string dec_string) = 0;
        virtual ~EncryptionStrategy(){};
};

#endif