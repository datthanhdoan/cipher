#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

// x^e mod n
long long modPow(long long x, long long e, long long n)
{
    long long result = 1;
    while (e > 0)
    {
        if (e % 2 == 1)
        {
            result = (result * x) % n;
        }
        x = (x * x) % n;
        e /= 2;
    }
    return result;
}

string enCode(string plainText, int e, int n)
{
    string result;
    for (char c : plainText)
    {
        int x = c;
        long long encrypted = modPow(x, e, n);
        result += to_string(encrypted) + " ";
    }
    return result;
}

int findE(int O_n)
{
    for (int i = 2; i < O_n; i++)
    {
        if (GCD(i, O_n) == 1)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    string plainText;
    int k[2];
    ifstream input("input.txt");
    fstream output;
    getline(input, plainText);
    input >> k[0];
    input >> k[1];
    input.close();
    int n = k[0] * k[1];
    int O_n = (k[0] - 1) * (k[1] - 1);
    int e = findE(O_n);
    string C = enCode(plainText, e, n);
    output.open("output.txt", ios::out);
    output << C;
    output.close();
    return 0;
}
