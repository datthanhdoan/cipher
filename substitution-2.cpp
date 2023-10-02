#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encode(string text, string keyText)
{
    string result;
    int keyLength = keyText.length();
    for (char c : text)
    {
        int index;
        if ((c - 97) <= keyLength)
        {
            result += keyText[(c - 97) % keyLength];
        }
        else
        {
            result += ((c - 97) % keyLength) + 'a';
        }
    }
    cout << "Encode : " << result << endl;
    return result;
}

string decode(string c, string keyText)
{
    string result;
    int keyLength = keyText.length();
    for (char encodedChar : c)
    {
        int index = keyText.find(encodedChar);
        if (index < keyLength)
        {
            result += (index + 97);
        }
        else
        {
            result += (encodedChar - 'a' + 97);
        }
    }
    cout << "Decode : " << result << endl;
    return result;
}

int main()
{
    string text;
    string keyText;
    cout << "Nhap Text:" << endl;
    cin >> text;
    cout << "Nhap keyText:";
    cin >> keyText;
    string C = encode(text, keyText);
    decode(C, keyText);
    return 0;
}
