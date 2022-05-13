#ifndef AES_H
#define AES_H

#include "EncryptionStrategy.h"
#include "FileIO.h"

#include "cryptopp/rijndael.h"
#include "cryptopp/osrng.h"
#include "cryptopp/modes.h"

#include <iostream>
#include <string>

class AES : public EncryptionStrategy {
    public:
        // Use this constructor when you need to encrypt
        AES();
        // Use this constructor when you need to decrypt
        AES(std::string keyFile);

        void encrypt(std::string filename);
        void decrypt(std::string filename);
    private:
        CryptoPP::SecByteBlock _IV;
        CryptoPP::SecByteBlock _key;
};

#endif