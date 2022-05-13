#ifndef RC6_H
#define RC6_H

#include "EncryptionStrategy.h"
#include "FileIO.h"

#include "cryptopp/rc6.h"
#include "cryptopp/osrng.h"
#include "cryptopp/modes.h"

#include <string>
#include <iostream>

class RC6 : public EncryptionStrategy {
    private:
        CryptoPP::SecByteBlock _key;
        CryptoPP::SecByteBlock _iv;
    public:
        // Use this constructor for encryption
        RC6();
        // Use this constructor for decryption
        RC6(std::string keyFilename);
        void encrypt(std::string filename);
        void decrypt(std::string filename);
};

#endif