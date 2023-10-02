#include <iostream>
#include <string>
using namespace std;

string substitution(string plaintext, string encodeAlphaBet, string normalAlphaBet)
{
    string encryp = plaintext;
    int keyLength = encodeAlphaBet.length();
    string result;
    for (int i = 0; i < plaintext.length(); i++)
    {
        char plainChar = plaintext[i];
        char keyChar = encodeAlphaBet[i];

        int index = 0;
        for (char x : normalAlphaBet)
        {
            if (x == plaintext[i])
            {
                break;
            }
            index++;
        }
        result += encodeAlphaBet[index];
    }

    return result;
}

string hoanvi(string skey, int key)
{
    string result;
    int length = skey.size();
    for (int i = 0; i < skey.size(); i++)
    {
        result += skey[(i + key) % skey.size()];
    }
    return result;
}

int main()
{

    string plaintext;
    string key;
    getline(cin, plaintext);
    char normalAlphabet[] = " .0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string encodeAlphabet = hoanvi(normalAlphabet, 2); // random 1 key bat ki rand()%100%10
    string encryp = substitution(plaintext, encodeAlphabet, normalAlphabet);
    cout << "You encodeAlphabet is : " << encodeAlphabet << endl;
    cout << "Encrypted text: " << encryp << endl;

    return 0;
}
