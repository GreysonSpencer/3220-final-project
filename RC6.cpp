#include "RC6.h"

RC6::RC6()
{
    // Create the new key and iv and assign them to a random value
    using namespace CryptoPP;

    SecByteBlock keyBlock(CryptoPP::RC6::DEFAULT_KEYLENGTH);
    SecByteBlock ivBlock(CryptoPP::RC6::BLOCKSIZE);

    AutoSeededRandomPool rng;
    rng.GenerateBlock(keyBlock, CryptoPP::RC6::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(ivBlock, CryptoPP::RC6::BLOCKSIZE);

    _key = keyBlock;
    _iv = ivBlock;
}

RC6::RC6(std::string keyFilename)
{
    // Read in key and initialize iv with the right size
    using namespace CryptoPP;

    FileIO keyFile(keyFilename);
    _key = keyFile.readKey();
    _iv = SecByteBlock(CryptoPP::RC6::BLOCKSIZE);
}

void RC6::encrypt(std::string filename)
{
    using namespace CryptoPP;

    FileIO textFile(filename);

    std::string plaintext = textFile.readFile();

    std::string ciphertext;
    try
    {
        CBC_Mode<CryptoPP::RC6>::Encryption filter;

        // Set key and initial vector for filter
        filter.SetKeyWithIV(_key, CryptoPP::RC6::DEFAULT_KEYLENGTH, _iv);

        // Take all the plaintext,
        // encrypt it with the filter,
        // then put it in the ciphertext string
        StringSource(plaintext, true, new StreamTransformationFilter(filter, new StringSink(ciphertext)));
    }
    catch(const Exception& e)
    {
        std::cerr << "RC6 encryption failed, error: \n" <<  e.what() << '\n';
        exit(1);
    }

    // Write key to key file
    std::string keyFilename;
    keyFilename = filename + ".key";

    FileIO keyFile(keyFilename);

    keyFile.writeKey(_key);


    // Convert IV to string and prepend to ciphertext
    std::string iv = std::string((char*)_iv.data(), CryptoPP::RC6::BLOCKSIZE);
    std::string ivCiphertext = iv + ciphertext;

    // Write output to file
    std::string outputFilename = filename + ".cipher";
    FileIO outputFile(outputFilename);

    outputFile.setWriteString(ivCiphertext);
    outputFile.writeFile();
}

void RC6::decrypt(std::string filename)
{
    using namespace CryptoPP;

    //Read in the full string from the file
    FileIO ciphertextFile(filename);
    std::string ivCiphertext = ciphertextFile.readFile();

    // Create a sink for the IV
    CryptoPP::ArraySink ivSink(_iv, CryptoPP::RC6::BLOCKSIZE);
    
    // Create the source from the imported string
    // Don't pump all of the contents
    StringSource source(ivCiphertext, false);

    // Attach a redirector to the sink
    source.Attach(new Redirector(ivSink));

    // Pump one block from the source, putting the IV into the ivSink
    source.Pump(CryptoPP::AES::BLOCKSIZE);

    // Create a new string sink and replace the ivSink on the source
    std::string ciphertext;
    source.Detach(new StringSink(ciphertext));

    // Pump the rest of the string into the string sink
    source.PumpAll();

    std::string plaintext;
    try
    {
        // Create filter
        CBC_Mode<CryptoPP::RC6>::Decryption filter;

        // Set key and initial vector
        filter.SetKeyWithIV(_key, CryptoPP::RC6::DEFAULT_KEYLENGTH, _iv);

        // Source from the ciphertext
        // Filter with RC6
        // Sink into plaintext
        StringSource s(ciphertext, true, new StreamTransformationFilter(filter, new StringSink(plaintext)));
    }
    catch(const Exception& e)
    {
        std::cerr << "Failed to decrypt with RC6, error message: \n" << e.what() << std::endl;
        exit(1);
    }
    
    // Write the output
    FileIO outputfile("decoded_text.txt");
    outputfile.setWriteString(plaintext);
    outputfile.writeFile();
}