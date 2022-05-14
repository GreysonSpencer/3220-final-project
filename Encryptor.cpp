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
    EncryptionStrategy *oldStrategy = _strategy;
    _strategy = strategy;
    delete oldStrategy;
    oldStrategy = nullptr;
}

void Encryptor::encrypt(std::string filename)
{
    _strategy->encrypt(filename);
}