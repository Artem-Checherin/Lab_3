#include "PermutationCipher.h"

PermutationCipher::PermutationCipher(int k)
{
    this->key=k;
}

wstring PermutationCipher::EncodePermutationCipher(PermutationCipher key, wstring& data)
{
    wstring Result;
    const int stroki = ((data.size()-1)/key.key)+1; // kolvo strok
    int index = 0; // dlya stroki
    wchar_t matr[stroki][key.key];
    for (auto i = 0; i <stroki; i++) {
        for (auto j = 0; j < key.key; j++ ) {
            if (index < data.size()) {
                matr[i][j] = data[index]; // zapolnenie matrici
                index++;
            } else {
                matr[i][j] =' ';
            }
        }
    }
    Result.resize(stroki*key.key); // ustanavlivaetsya razmer stroki
    for (auto i = 0; i < key.key; i++) {
        for (auto j = 0; j < stroki; j++ ) {
            Result.push_back(matr[j][i]);
        }
    }
    return Result;
}

wstring PermutationCipher::DecodePermutationCipher(PermutationCipher key, wstring &data)
{
    wstring Result;
    int index = 0; // для строки
    const int stroki = ((data.size()-1)/key.key)+1; // количество строк по формуле
    wchar_t matr[stroki][key.key];

    for (auto i = 0; i < key.key; i++) {
        for (auto j = 0; j < stroki; j++ ) {
            if (index < data.size()) {
                matr[j][i] = data[index];
                index++;
            } else {
                matr[j][i] = ' ';
                index++;
            }
        }
    }
    Result.resize(stroki*key.key); // устанавливаем размер строки, чтобы не было ошибок с памятью
    for(auto i = 0; i < stroki; i++) {
        for (auto j = 0; j< key.key; j++) {
            Result.push_back(matr[i][j]);
        }
    }
    return Result;
}