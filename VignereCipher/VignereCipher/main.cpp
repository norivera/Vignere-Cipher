#include <iostream>
#include <string>
using namespace std;


//this method makes sure the key is the same size as the inputed string
string KeyGen(string str, string key)
{
    int x = str.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

// Creates the encrpyted text using the generated key
string cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {
        // converts between 0-25
        char x = (str[i] + key[i]) % 26;

        // to create the standars alphabet
        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}


// decyption - returns encrpted string back into the user string
string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        char x = (cipher_text[i] - key[i] + 26) % 26;
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

int main()
{
    cout << "Please Enter the Key: ";
    string user_key; 
    getline(cin, user_key);

    cout << "\nPlease Enter the String: ";
    string user_str;
    getline(cin, user_str);
    string key = KeyGen(user_str, user_key);
    string cipher_text = cipherText(user_str, key);

    cout << "\nCiphertext: " << cipher_text << "\n";

    cout << "\nOriginal/Decrypted Text: " << originalText(cipher_text, key) << endl;
    return 0;
}