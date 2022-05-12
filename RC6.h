#ifndef RC6_H
#define RC6_H

#include "EncryptionStrategy.h"

#include "cryptopp/rc6.h"
#include "cryptopp/osrng.h"

#include <string>
#include <iostream>

class RC6 : public EncryptionStrategy {
    private:
        CryptoPP::SecByteBlock _key;
        CryptoPP::SecByteBlock _iv;
    public:
        RC6();
        RC6(std::string keyFilename);
        void encrypt(std::string filename);
        void decrypt(std::string filename);
};

#endif