#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include "EncryptionStrategy.h"

class Encryptor {
    private:
        EncryptionStrategy *_strategy;
    public:
        Encryptor(EncryptionStrategy *_strategy);
        ~Encryptor();
        void changeStrategy(EncryptionStrategy *_strategy);
        void encrypt();
};

#endif