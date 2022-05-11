#ifndef AES_H
#define AES_H

#include "SymmetricEnc.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"

#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

#include "FileIO.h"

#include <iostream>
#include <string>

class AES : public SymmetricEnc {
    public:
        //void execute();
        // Use this constructor when you need to encrypt
        AES();
        // Use this constructor when you need to decrypt
        AES(std::string keyFile);
        void encrypt(std::string filename);
        std::string decrypt(std::string dec_string);
        int getPrivateKey();
        void setPrivateKey(int key);
    private:
        CryptoPP::SecByteBlock _IV;
        CryptoPP::SecByteBlock _key;
};

#endif