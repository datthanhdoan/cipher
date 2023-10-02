#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string ceasar(string text, int key)
{
    string result;
    string test;
    for (char &c : text)
    {
        if (c >= ' ' && c <= '~')
        {
            result += (c - ' ' + key) % 95 + ' ';
        }
    }
    cout << " Day la ban ma sau khi ma hoa : " << result << endl;
    for (char &c : result)
    {
        if (c >= ' ' && c <= '~')
        {
            test += (c - ' ' - key) % 95 + ' ';
        }
    }
    cout << " Day la ban ro : " << test << endl;
    return result;
}

using namespace std;
int main()
{
    string text;
    int key;
    fstream file;
    // mofile dau vao
    file.open("input.md", ios::in);
    // lay du lieu
    file >> text;
    file >> key;
    file.close();
    // dong file dau vao
    file.open("output.md", ios::out);
    // ghi du lieu file dau ra
    file << ceasar(text, key);
    file.close();
    return 0;
}