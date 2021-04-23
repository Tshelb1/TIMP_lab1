
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class BetaCipher
{
private:
    int key;
public:
    BetaCipher() = delete;
    BetaCipher(int k);
    wstring EncodeBetaCipher(BetaCipher key, wstring &data);
    wstring DecodeBetaCipher(BetaCipher key, wstring &data);
};
