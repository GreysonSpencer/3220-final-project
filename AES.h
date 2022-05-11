#ifndef AES_H
#define AES_H

#include "SymmetricEnc.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"

#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

#include <iostream>
#include <string>

class AES : public SymmetricEnc {
    public:
        void execute();
        int getPrivateKey();
        void setPrivateKey(int key);
};

#endif