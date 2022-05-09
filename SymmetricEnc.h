#ifndef SYMMETRICENC_H
#define SYMMETRICENC_H

#include "EncryptionStrategy.h"

class SymmetricEnc : public EncryptionStrategy {
    public:
        int publicKey;
        ~SymmetricEnc(){};
};

#endif