#include "AES.h"

AES::AES()
{
    using namespace CryptoPP;

    AutoSeededRandomPool prng;
    HexEncoder encoder (new FileSink(std::cout));

    SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    _key = key;
    _IV = iv;
}

AES::AES(std::string keyFile)
{
    FileIO file(keyFile);
    _key = file.readKey();
    _IV = file.readIV();
}

void AES::encrypt(std::string filename)
{
    using namespace CryptoPP;

    FileIO fileInput(filename);

    std::string enc_string = fileInput.readFile();
    std::string ciphertext;

    try
    {
        CBC_Mode< CryptoPP::AES >::Encryption e;
        e.SetKeyWithIV(_key, _key.size(), _IV);

        //Print key
        std::cout << "enc Key: ";
        for (unsigned int i = 0; i < _key.size(); i++)
        {
            std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(_key[i])) << " ";
        }
        std::cout << std::endl;

        // Print IV
        std::cout << "enc IV: ";
        for (unsigned int i = 0; i < _IV.size(); i++)
        {
            std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(_IV[i])) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        //StringSource s(enc_string, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
        StringSource s(enc_string, true, 
            new StreamTransformationFilter(e,
                new StringSink(ciphertext)
            ) // StreamTransformationFilter
        ); // StringSource

        std::cout << "encoded text: " << ciphertext << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    
    std::string keyFilename = filename + ".key";
    FileIO outputKey(keyFilename);

    outputKey.writeKey(_key, _IV);

    std::string cipherFilename = filename + ".cipher";
    FileIO outputCipher(cipherFilename);
    outputCipher.setWriteString(ciphertext);

    outputCipher.writeFile();
}

void AES::decrypt(std::string filename)
{
    using namespace CryptoPP;
    
    FileIO inputfile(filename);

    std::string ciphertext = inputfile.readFile();
    std::string plaintext;

    try
    {
        CBC_Mode< CryptoPP::AES >::Decryption d;
        d.SetKeyWithIV(_key, _key.size(), _IV);

        StringSource s(ciphertext, true, 
            new StreamTransformationFilter(d,
                new StringSink(plaintext)
            ) // StreamTransformationFilter
        ); // StringSource

        std::cout << "recovered text: " << plaintext << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    
    FileIO outputfile("decoded_text.txt");
    outputfile.setWriteString(plaintext);
    outputfile.writeFile();
}

int AES::getPrivateKey()
{
    return privateKey;
}

void AES::setPrivateKey(int key)
{
    privateKey = key;
}