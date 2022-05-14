#include <gtest/gtest.h>
#include "AES.h"
#include "AES.cpp"
#include "RC6.h"
#include "RC6.cpp"
#include "Encryptor.h"
#include "Encryptor.cpp"
#include "Decryptor.h"
#include "Decryptor.cpp"
#include "FileIO.h"
#include "FileIO.cpp"
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

    std::getline(outputstream, output);

    EXPECT_EQ(testString, output);
}

TEST(RC6Encryption, EncryptionDecryption)
{
    std::string testString = "This is some input that I want to test.";
    std::ofstream stream("testText2.txt");
    if(!stream.is_open())
    {
        std::cout << "File failed to open.\n";
        exit(EXIT_FAILURE);
    }
    stream << testString;
    stream.close();

    RC6 *rc6 = new RC6();
    Encryptor *enc = new Encryptor(rc6);

    enc->encrypt("testText2.txt");
    delete enc;

    RC6 *rc6D = new RC6("testText2.txt.key");
    Decryptor *dec = new Decryptor(rc6D);

    dec->decrypt("testText2.txt.cipher");
    delete dec;

    std::string output;
    std::ifstream outputstream("decoded_text.txt");

    std::getline(outputstream, output);

    EXPECT_EQ(testString, output);
}

TEST(FileIOTest, HelperFunctions)
{
    FileIO *file = new FileIO("testfile.txt");

    file->setFilename("newtestfile.txt");

    EXPECT_EQ("newtestfile.txt", file->getFilename());

    delete file;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}