#include "Encryptor.h"

Encryptor::Encryptor(EncryptionStrategy *strategy)
{
    _strategy = strategy;
}

Encryptor::~Encryptor()
{
    delete _strategy;
}

void Encryptor::changeStrategy(EncryptionStrategy *strategy)
{
    _strategy = strategy;
}

std::string Encryptor::encrypt(std::string enc_string)
{
    return _strategy->encrypt(enc_string);
}