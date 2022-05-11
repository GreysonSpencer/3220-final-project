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

// void AES::execute()
// {
//     using namespace CryptoPP;

//     AutoSeededRandomPool prng;
//     HexEncoder encoder (new FileSink(std::cout));

//     SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
//     SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

//     prng.GenerateBlock(key, key.size());
//     prng.GenerateBlock(iv, iv.size());

//     std::string plain = "CBC Mode Test";
//     std::string cipher, recovered;

//     std::cout << "plain text: " << plain << std::endl;

//     
//     

//     try
//     {
//         CBC_Mode< CryptoPP::AES >::Encryption e;
//         e.SetKeyWithIV(key, key.size(), iv);

//         StringSource s(plain, true, 
//             new StreamTransformationFilter(e,
//                 new StringSink(cipher)
//             ) // StreamTransformationFilter
//         ); // StringSource
//     }
//     catch(const Exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//         exit(1);
//     }

//     
//     

//     std::cout << "key: ";
//     encoder.Put(key, key.size());
//     encoder.MessageEnd();
//     std::cout << std::endl;

//     std::cout << "iv: ";
//     encoder.Put(iv, iv.size());
//     encoder.MessageEnd();
//     std::cout << std::endl;

//     std::cout << "cipher text: ";
//     encoder.Put((const byte*)&cipher[0], cipher.size());
//     encoder.MessageEnd();
//     std::cout << std::endl;
    
//     
//     

//     try
//     {
//         CBC_Mode< CryptoPP::AES >::Decryption d;
//         d.SetKeyWithIV(key, key.size(), iv);

//         StringSource s(cipher, true, 
//             new StreamTransformationFilter(d,
//                 new StringSink(recovered)
//             ) // StreamTransformationFilter
//         ); // StringSource

//         std::cout << "recovered text: " << recovered << std::endl;
//     }
//     catch(const Exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//         exit(1);
//     }
//     std::cout << "Encryption success\n";
// }

int AES::getPrivateKey()
{
    return privateKey;
}

void AES::setPrivateKey(int key)
{
    privateKey = key;
}