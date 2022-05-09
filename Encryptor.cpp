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

void Encryptor::encrypt()
{
    _strategy->execute();
}