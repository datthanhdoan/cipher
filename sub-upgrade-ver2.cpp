#include <iostream>
#include <string>
using namespace std;

string encodeSubstitution(string plaintext, string encodeAlphaBet, string normalAlphaBet)
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

string decodeSubstitution(string C, string encodeAlphaBet, string normalAlphaBet)
{
    string result;
    for (int i = 0; i < C.length(); i++)
    {
        char encodedChar = C[i];
        int index = encodeAlphaBet.find(encodedChar);
        char decodedChar = normalAlphaBet[index];
        result += decodedChar;
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

int main(int argc, char *argv[])
{
    int x;
    char normalAlphabet[] = ".0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string encodeAlphabet = hoanvi(normalAlphabet, rand() % 1000); // random 1 key bat ki rand()%100%10
    cout << "Substitution Cipher Program " << endl;
    cout << "Your Alphabet is :" << normalAlphabet << endl;
    cout << "Your ramdom encodeAlphabet is : " << encodeAlphabet << endl;
    string plaintext;
    string key;
    string C, P;
    do
    {

        cout << "Encode : 1       Decode : 2          Exit : 3" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Type your plain text : ";
            cin >> plaintext;
            C = encodeSubstitution(plaintext, encodeAlphabet, normalAlphabet);
            cout << "Encrypted text: " << C << endl;
            break;
        case 2:
            cout << "Type your encrypted text : ";
            cin >> C;
            P = decodeSubstitution(C, encodeAlphabet, normalAlphabet);
            cout << "Decrypted text: " << P << endl;
            break;
        case 3:
            cout << " -- Exit --";
            break;
        }
        cout << " -- -- -- -- -- -- -- -- -- -- -- " << endl;
    } while (x != 3);

    return 0;
}
