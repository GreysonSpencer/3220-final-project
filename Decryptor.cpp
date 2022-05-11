#include "Decryptor.h"

Decryptor::Decryptor(EncryptionStrategy *strategy)
{
    _strategy = strategy;
}

Decryptor::~Decryptor()
{
    delete _strategy;
}

void Decryptor::changeStrategy(EncryptionStrategy *strategy)
{
    EncryptionStrategy *oldStrategy = _strategy;
    _strategy = strategy;
    delete oldStrategy;
}

void Decryptor::decrypt(std::string filename, std::string keyFilename)
{

}