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
        AES();
        AES(std::string keyFile);
        std::string encrypt(std::string enc_string);
        std::string decrypt(std::string dec_string);
        int getPrivateKey();
        void setPrivateKey(int key);
    private:
        CryptoPP::SecByteBlock IV;
        CryptoPP::SecByteBlock key;
};

#endif