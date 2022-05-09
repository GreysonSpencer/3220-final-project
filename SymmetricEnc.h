#ifndef SYMMETRICENC_H
#define SYMMETRICENC_H

#include "EncryptionStrategy.h"

class SymmetricEnc : public EncryptionStrategy {
    public:
        virtual int getPublicKey() = 0;
        virtual void setPublicKey(int key) = 0;
        ~SymmetricEnc(){};
    private:
        int publicKey;
};

#endif