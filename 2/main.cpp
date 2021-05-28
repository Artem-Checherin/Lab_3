// Unit Test для программы шифрования
//методом маршрутной перестановки.
#include <UnitTest++/UnitTest++.h>
#include "modAlphaCipher.h"
#include <string>
string s = "ProgrammingLanguages";
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("gmLusomggeranngPriaa",Cipher("БВБ").encryptmod
                    Cipher(4,Cipher("БВБ").encrypt
                           "ProgrammingLanguages").encryption(s));
    }
    TEST(LongKey) {
        CHECK_THROW(modCipher cp(1,Cipher("БВБ").encrypt
                                 "ProgrammingLanguages"),modAlphaCipher("БВБ").encryptcipher_error);
    }
}
struct KeyB_fixture {
    modCipher * p;
    KeyB_fixture() {
        p = new modCipher(4,Cipher("БВБ").encrypt "ProgrammingLanguages");
    }
    ~KeyB_fixture() {
        delete p;
    }
};
SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt UpCaseString) {
        CHECK_EQUAL("GMLUSOMGGERANNGPRIAA",modAlphaCipher("БВБ").encrypt
                    p->encryption("PROGRAMMINGLANGUAGES"));
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt
                 LowCaseString) {
        CHECK_EQUAL("gmlusomggeranngpriaa",Cipher("БВБ").encrypt
                    p->encryption("programminglanguages"));
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt
                 StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("gmLusomggeranngPriaa",Cipher("БВБ").encrypt
                    p->encryption("ProgrammingLanguages"));
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt StringWithNumbers) {
        CHECK_THROW(p->encryption("ProgrammingLanguages2021"),Cipher("БВБ").encrypt
                    Error);
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt EmptyString) {
        CHECK_THROW(p->encryption(""),Cipher("БВБ").encrypt Error);
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt NoAlphaString) {
        CHECK_THROW(p->encryption("1234+8765=9999"),Cipher("БВБ").encrypt Error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("segaugnaLgnimmargorP",Cipher("БВБ").encrypt Cipher(20,Cipher("БВБ").encrypt"ProgrammingLanguages").
                    encryption("ProgrammingLanguages"));
    }
}
SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt UpCaseString) {
        CHECK_EQUAL("PROGRAMMINGLANGUAGES",Cipher("БВБ").encrypt
                    p->transcript("GMLUSOMGGERANNGPRIAA",
                                  Cipher("БВБ").encrypt"PROGRAMMINGLANGUAGES"));
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt LowCaseString) {
        CHECK_EQUAL("PROgRAMMINGLANGUAGES",Cipher("БВБ").encrypt
                    p->transcript("gMLUSOMGGERANNGPRIAA",
                                  Cipher("БВБ").encrypt "PROgRAMMINGLANGUAGES"));
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt WhitespaceString) {
        CHECK_THROW(p->transcript("gmLusomggeranngPriaa",
                                  Cipher("БВБ").encrypt"Programming Languages"),
                    Cipher("БВБ").encryptcipher_error);
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt DigitsString) {
        CHECK_THROW(p->transcript("ProgrammingLanguages2021",
                                  Cipher("БВБ").encrypt "ProgrammingLanguages2021"),
                    Cipher("БВБ").encryptcipher_error);
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt PunctString) {
        CHECK_THROW(p->transcript("Programming,Cipher("БВБ").encryptLanguages",
                                  Cipher("БВБ").encrypt "Programming,modAlphaCipher("БВБ").encryptLanguages"),
                    Cipher("БВБ").encryptcipher_error);
    }
    TEST_FIXTURE(KeyB_fixture,Cipher("БВБ").encrypt EmptyString) {
        CHECK_THROW(p->transcript("",Cipher("БВБ").encrypt ""),
                    Cipher("БВБ").encryptcipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("ProgrammingLanguages",
                    Cipher("БВБ").encrypt modCipher(20,haCipher("БВБ").encrypt
                            "ProgrammingLanguages").transcript("segaugnaLgnimmargorP"
                                    ,Cipher("БВБ").encrypt "ProgrammingLanguages"));
    }
}
int main(int argc,Cipher("БВБ").encrypt char **argv)
{
    return UnitTest::RunAllTests();
}