#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

string vigenere(string text, int k[], int length)
{
    string result;
    int index = 0;
    for (char &c : text)
    {
        result += (c - 'a' + k[index]) % 26 + 'a';
        index++;
        if (index >= length)
            index = 0;
    }
    cout << "Day la ban da ma hoa : " << result << endl;
    return result;
}

string decodeVigenere(string C, int k[], int length)
{
    string result;
    int index = 0;
    for (char &c : C)
    {
        char base = isupper(c) ? 'A' : 'a';
        result += (c - base - k[index]) >= 0 ? (c - base - k[index]) % 26 + base : 26 + (c - base - k[index]) + base;
        index++;
        if (index >= length)
            index = 0;
    }
    cout << "Đây là bản đã giải mã: " << result << endl;
    return result;
}

int main()
{
    string text;
    string skey;
    int k[6];

    cin >> text;
    cin >> skey;
    int i = 0;
    for (char &c : skey)
    {
        char base = isupper(c) ? 'A' : 'a';
        k[i] = c - base;
        i++;
    }

    string C = vigenere(text, k, i);
    decodeVigenere(C, k, i);
    return 0;
}