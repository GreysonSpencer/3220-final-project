#ifndef SYMMETRICENC_H
#define SYMMETRICENC_H

#include "EncryptionStrategy.h"

class SymmetricEnc : public EncryptionStrategy {
    public:
        virtual int getPrivateKey() = 0;
        virtual void setPrivateKey(int key) = 0;
        ~SymmetricEnc(){};
    protected:
        int privateKey;
};

#endif