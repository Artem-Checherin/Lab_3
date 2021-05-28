//Unit Test для программы шифрования 
//алгоритмом Гронсвельда на русском языке.
#include <stdexcept>
#include <UnitTest++/UnitTest++.h>
#include "modAlphaCipher.h"
#include <iostream>
SUITE(KeyTest)
{
	TEST(ValidKey) {
		CHECK_EQUAL("БВББВ",modAlphaCipher("БВБ").encrypt("ААААА"));
	}
	TEST(LongKey) {
		CHECK_EQUAL("БВББВ",modAlphaCipher("БВГДЕЖЗИ").encrypt("ААААА"));
	}
	TEST(LowCaseKey) {
		CHECK_EQUAL("БВББВ",modAlphaCipher("бвб").encrypt("ААААА"));
	}
	TEST(DigitsInKey) {
		CHECK_THROW(modAlphaCipher cp("Б1"), Error);
	}
	TEST(PunctuationInKey) {
		CHECK_THROW(modAlphaCipher cp("Б, В"), Error);
	}
	TEST(WhitespaceInKey) {
		CHECK_THROW(modAlphaCipher cp("Б В Б"), Error);
	}
	TEST(EmptyKey) {
		CHECK_THROW(modAlphaCipher cp(""), Error);
	}
	TEST(WeakKey) {
		CHECK_THROW(modAlphaCipher cp("ААА"), Error);
	}
}
struct KeyB_fixture {
	modAlphaCipher * p;
	KeyB_fixture() {
		p = new modAlphaCipher("Б");
	}
	~KeyB_fixture() {
		delete p;
	}
};
SUITE(EncryptTest)
{
	TEST_FIXTURE(KeyB_fixture, UpCaseString) {
		CHECK_EQUAL("ТЙРМЯТРМЯТ",
		            p->encrypt("СИПЛЮСПЛЮС"));
	}
	TEST_FIXTURE(KeyB_fixture, LowCaseString) {
		CHECK_EQUAL("ТЙРМЯТРМЯТ",
		            p->encrypt("сиплюсплюс"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
		CHECK_EQUAL("ТЙРМЯТРМЯТ",
		            p->encrypt("СИ ПЛЮС ПЛЮС!!!"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
		CHECK_EQUAL("ТОПГЬН2021ДПЕПН", p->encrypt("С НОВЫМ 2021 ГОДОМ"));
	}
	TEST_FIXTURE(KeyB_fixture, EmptyString) {
		CHECK_THROW(p->encrypt(""),Error);
	}
	TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
		CHECK_THROW(p->encrypt("1234+8765=9999"),Error);
	}
	TEST(MaxShiftKey) {
		CHECK_EQUAL("РЗОКЭРОКЭР",
		            modAlphaCipher("Я").encrypt("СИПЛЮСПЛЮС"));
	}
}
SUITE(DecryptText)
{
	TEST_FIXTURE(KeyB_fixture, UpCaseString) {
		CHECK_EQUAL("СИПЛЮСПЛЮС",
		            p->decrypt("ТЙРМЯТРМЯТ"));
	}
	TEST_FIXTURE(KeyB_fixture, LowCaseString) {
		CHECK_THROW(p->decrypt("тйрМЯТРМЯТ"),Error);
	}
	TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
		CHECK_THROW(p->decrypt("ТЙР МЯТР МЯТ"),Error);
	}
	TEST_FIXTURE(KeyB_fixture, DigitsString) {
		CHECK_THROW(p->decrypt("ТОПГЬН2021ДПЕПН"),Error);
	}
	TEST_FIXTURE(KeyB_fixture, PunctString) {
		CHECK_THROW(p->decrypt("ТЙ,РМЯТ,РМЯТ"),Error);
	}
	TEST_FIXTURE(KeyB_fixture, EmptyString) {
		CHECK_THROW(p->decrypt(""),Error);
	}
	TEST(MaxShiftKey) {
		CHECK_EQUAL("СИПЛЮСПЛЮС",
		            modAlphaCipher("Я").decrypt("ТЙРМЯТРМЯТ"));
	}
}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}