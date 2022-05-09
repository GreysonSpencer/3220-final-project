#ifndef ENCRYPTIONSTRATEGY_H
#define ENCRYPTIONSTRATEGY_H

class EncryptionStrategy {
    public:
        virtual void execute() = 0;
        virtual ~EncryptionStrategy(){};
};

#endif