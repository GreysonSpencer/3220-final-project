#ifndef AES_H
#define AES_H

#include "SymmetricEnc.h"
/*#include "cryptlib.h"
#include "rijndael.h"
#include "modes.h"

#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"
*/
#include "libcryptopp.a"

#include <iostream>
#include <string>

class AES : public SymmetricEnc {
    public:
        void execute();
        int getPrivateKey();
        void setPrivateKey(int key);
};

#endif