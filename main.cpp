#include <iostream>

#include "AES.h"
#include "Encryptor.h"

int main()
{
    AES *aes = new AES();

    Encryptor *enc = new Encryptor(aes);

    enc->encrypt();

    delete enc;
}