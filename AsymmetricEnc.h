#ifndef ASYMMETRICENC_H
#define ASYMMETRICENC_H

#include "EncryptionStrategy.h"

class AsymmetricEnc : public EncryptionStrategy {
    public:
        virtual int getPublicKey() = 0;
        virtual void setPublicKey(int key) = 0;
        virtual int getPrivateKey() = 0;
        virtual void setPrivateKey(int key) = 0;
        ~AsymmetricEnc(){};
    private:
        int publicKey;
        int privateKey;
};

#endif