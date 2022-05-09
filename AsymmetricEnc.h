#ifndef ASYMMETRICENC_H
#define ASYMMETRICENC_H

#include "EncryptionStrategy.h"

class AsymmetricEnc : public EncryptionStrategy {
    public:
        int publicKey;
        ~AsymmetricEnc(){};
    private:
        int privateKey;
};

#endif