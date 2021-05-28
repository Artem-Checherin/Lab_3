// заголовочный файл модуля main.cpp

#pragma once
#include <vector>
#include <string>
#include <codecvt>
#include <locale>
#include <map>
using namespace std;
class modAlphaCipher
{
private:
wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
map <wchar_t,int> alphaNum;//ассоциативный массив "номер по символу"
vector <int> key;//ключ
vector<int> convert(const wstring& ws);//преобразование строка-вектор
string convert(const vector<int>& v);//преобразование вектор-строка
wstring towstr(const string& s);
string fromwstr(const wstring& ws);
public:
modAlphaCipher()=delete;//запретим конструктор без параметров
modAlphaCipher(const string& skey);//конструктор для установки ключа
string encrypt(const string& open_text);//зашифрование
string decrypt(const string& cipher_text);//расшифрование
};