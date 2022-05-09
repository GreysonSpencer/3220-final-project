#ifndef AES_H
#define AES_H

#include "SymmetricEnc.h"

class AES : public SymmetricEnc {
    public:
        void execute();
        int getPrivateKey();
        void setPrivateKey(int key);
};

#endif