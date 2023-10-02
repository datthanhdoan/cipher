#include <iostream>
using namespace std;

string encodeAffine(string text, int k[])
{
    string result;
    for (char c : text)
    {
        int index = c - 65;
        result += (k[0] * index + k[1]) % 26 + 'A';
    }
    cout << result << endl;
    return result;
}

int main()
{
    string text;
    int k[2];
    cout << "Type your text : ";
    cin >> text;
    k[0] = 5, k[1] = 8;
    string C = encodeAffine(text, k);
    return 0;
}