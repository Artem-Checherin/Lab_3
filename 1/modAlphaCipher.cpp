// Модуль "шифрования" modAlphaCipher.cpp без проверки входной строки на ошибки

// Заголовок модуля
#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const std::string& skey)
{
for (unsigned i=0; i<numAlpha.size(); i++) {
alphaNum[numAlpha[i]]=i;
}
std::wstring wskey = towstr(skey);
key = convert(wskey);
for (auto wc: ws)
		if (!((wc>= 1040) && (wc <= 1071)) || (wc == 1025)) { //14
			throw Error(string ("Запрещенные символы в ключе: ") + skey);
		}
}

// Метод encrypt() -зашифрование
std::string modAlphaCipher::encrypt(const std::string& open_text)
{
std::wstring open_wtext = towstr (open_text);
std::vector<int> work = convert(open_wtext);
for(unsigned i=0; i < work.size(); i++) {
work[i] = (work[i] + key[i % key.size()]) %alphaNum.size();
}
return convert(work);
}

// Метод decrypt() - расшифрование
std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{

std::wstring cipher_wtext = towstr (cipher_text);
std::vector<int> work = convert(cipher_wtext);
for(unsigned i=0; i < work.size(); i++) {
work[i] = (work[i] + alphaNum.size() - key[i %key.size()])
% alphaNum.size();
}
return convert(work);
}

// Метод преобразует строку в целочисленный вектор
inline std::vector<int> modAlphaCipher::convert(const std::wstring&
ws)
{
std::vector<int> result;
for(auto wc:ws) {
result.push_back(alphaNum[wc]);
}
return result;
}

// Метод преобразует целочисленный вектор в строку
inline std::string modAlphaCipher::convert(const std::vector<int>&
v)
{
std::wstring wresult;
for(auto i:v) {
wresult.push_back(numAlpha[i]);
}
std::string result = fromwstr(wresult);
return result;
}

// Метод получения кода строки
std::wstring modAlphaCipher::towstr(const std::string& s)
{
std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>
codec;
std::wstring ws = codec.from_bytes(s);
return ws;
}

// Метод получения строки из кода
std::string modAlphaCipher::fromwstr(const std::wstring& ws)
{
std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>
codec;
std::string s = codec.to_bytes(ws);
return s;
}