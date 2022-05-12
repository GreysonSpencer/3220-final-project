#ifndef RC6_H
#define RC6_H

#include "EncryptionStrategy.h"

#include "cryptopp/rc6.h"

#include <string>
#include <iostream>

class RC6 : public EncryptionStrategy {
    private:
        CryptoPP::SecByteBlock _key;
        CryptoPP::SecByteBlock _iv;
};

#endif