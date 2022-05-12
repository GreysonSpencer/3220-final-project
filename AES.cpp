#include "AES.h"

AES::AES()
{
    using namespace CryptoPP;

    // Create key and initial vector for encryption
    // Key initialized with default key length
    // IV initialized with default block size
    SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

    // Randomly generate the key and initial vector
    AutoSeededRandomPool prng;
    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    _key = key;
    _IV = iv;
}

AES::AES(std::string keyFile)
{
    FileIO file(keyFile);
    _key = file.readKey();
    // Initialize the IV to the default block size
    _IV = CryptoPP::SecByteBlock(CryptoPP::AES::BLOCKSIZE);
}

void AES::encrypt(std::string filename)
{
    using namespace CryptoPP;

    FileIO fileInput(filename);

    std::string enc_string = fileInput.readFile();
    std::string ciphertext;

    try
    {
        CBC_Mode<CryptoPP::AES>::Encryption cbcEnc;

        // Set the key and initial vector
        cbcEnc.SetKeyWithIV(_key, _key.size(), _IV);

        // Take everything in the input, 
        // transform it through the encryption scheme, 
        // and then put it in the ciphertext string
        StringSource s(enc_string, true, new StreamTransformationFilter(cbcEnc, new StringSink(ciphertext)));

        // Encryption is done
    }
    catch(const Exception& e)
    {
        std::cerr << "Encryption with AES failed, error: \n" << e.what() << std::endl;
        exit(1);
    }
    
    // Create key file
    std::string keyFilename = filename + ".key";
    FileIO outputKey(keyFilename);

    outputKey.writeKey(_key);


    // Create ciphertext file
    std::string cipherFilename = filename + ".cipher";
    FileIO outputCipher(cipherFilename);

    //Convert IV to string and prepend it to the ciphertext
    std::string iv = std::string((char*)_IV.data(), _IV.size());
    std::string ivCiphertext = iv + ciphertext;
    outputCipher.setWriteString(ivCiphertext);

    outputCipher.writeFile();
}

void AES::decrypt(std::string filename)
{
    using namespace CryptoPP;
    
    //Read in the full string from the file
    FileIO inputfile(filename);
    std::string ivciphertext = inputfile.readFile();
    
    // Create a sink for the IV
    CryptoPP::ArraySink ivSink(_IV, _IV.size());
    
    // Create the source from the imported string
    StringSource s(ivciphertext, false);

    // Attach a redirector to the sink
    s.Attach(new Redirector(ivSink));

    // Pump one block from the source, putting the IV into the ivSink
    s.Pump(CryptoPP::AES::BLOCKSIZE);

    // Create a new string sink and replace the ivSink on the source
    std::string ciphertext;
    s.Detach(new StringSink(ciphertext));

    // Pump the rest of the string into the string sink
    s.PumpAll();


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

        // std::cout << "recovered text: " << plaintext << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << "Failed to decrypt with AES, error message: \n" << e.what() << std::endl;
        exit(1);
    }
    
    // Write the output
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