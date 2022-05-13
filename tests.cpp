#include <gtest/gtest.h>
#include "AES.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include <fstream>

TEST(AESEncryption, EncryptionDecryption)
{
    std::string testString = "This is some input that I want to test.";
    std::ofstream stream("testText.txt");
    if(!stream.is_open())
    {
        std::cout << "File failed to open.\n";
        exit(EXIT_FAILURE);
    }
    stream << testString;
    stream.close();

    AES *aes = new AES();
    Encryptor *enc = new Encryptor(aes);

    enc->encrypt("testText.txt");
    delete enc;

    AES *aesD = new AES("testText.txt.key");
    Decryptor *dec = new Decryptor(aesD);

    dec->decrypt("testText.txt.cipher");
    delete dec;

    std::string output;
    std::ifstream outputstream("decoded_text.txt");

    outputstream >> output;

    EXPECT_EQ(testString, output);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}