#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include "EncryptionStrategy.h"
#include <string>

class Encryptor {
    private:
        EncryptionStrategy *_strategy;
    public:
        Encryptor(EncryptionStrategy *strategy);
        ~Encryptor();
        void changeStrategy(EncryptionStrategy *strategy);
        void encrypt(std::string filename);
};

#endif