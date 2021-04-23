#include "BetaCipher.h"
BetaCipher::BetaCipher(int key)
{
    this->k=key;
}
wstring BetaCipher::CoderBetaCipher(BetaCipher w, wstring& s)
{
    wstring code;
    int h;
    int dl=s.size();
    if (s.size()%w.k!=0) {
        h=s.size()/w.k+1;
    } else {
        h=s.size()/w.k;
    }
    wchar_t a[h][w.k];
    int k=0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w.k; j++) {
            if (k<s.length()) {
                a[i][j]=s[k];
                k++;
            } else a[i][j]=' ';
        }
    }
    for (int i=0; i<w.k; i++) {
        for (int j=0; j<h; j++) {
            code+=a[j][i];
        }
    }
    return code;
}
wstring BetaCipher::DecoderBetaCipher(BetaCipher w, wstring& s)
{
    int h;
    if (s.size()%w.k!=0) {
        h=s.size()/w.k+1;
    } else {
        h=s.size()/w.k;
    }
    wchar_t a[h][w.k];
    int k=0;
    for (int i=0; i<w.k; i++) {
        for (int j=0; j<h; j++) {
            a[j][i]=s[k];
            k++;
        }
    }
    wstring decode;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w.k; j++) {
            decode+=a[i][j];
        }
    }
    return decode;
}
