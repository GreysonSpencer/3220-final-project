#ifndef DECRYPTOR_H
#define DECRYPTOR_H

#include "EncryptionStrategy.h"
#include <string>

class Decryptor {
    private:
        EncryptionStrategy *_strategy;
    public:
        Decryptor(EncryptionStrategy *strategy);
        ~Decryptor();
        void changeStrategy(EncryptionStrategy *strategy);
        void decrypt(std::string filename, std::string keyFilename);
};

#endif