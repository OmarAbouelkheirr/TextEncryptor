#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Encryption(const string& text, short shift)
{
    string encrypted = text;
    for (char& ch : encrypted)
        ch = ch + shift;  

    return encrypted;
}

string Decryption(const string& text, short shift)
{
    string decrypted = text;

    for (char& ch : decrypted)
        ch = ch - shift;  

    return decrypted;
}

void SaveToFile(const string& filename, const string& data)
{
    ofstream file(filename);

    if (file.is_open())
    {
        file << data;
        file.close();
        cout << "Data saved successfully!\n";
    }
    else
        cout << "Failed to open file for writing!\n";
}

string ReadFromFile(const string& filename)
{
    ifstream file(filename);

    if (file.is_open()) 
    {
        string data;
        getline(file, data);
        file.close();
        return data;
    }
    else
    {
        cout << "Failed to open file for reading!\n";
        return "";
    }
}

int main()
{
    short shift = 2;
    const string filename = "encrypted.txt";  

    string inputText;
    cout << "Enter text to encrypt: ";
    getline(cin, inputText);

    string encryptedText = Encryption(inputText, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    SaveToFile(filename, encryptedText);

    string loadedText = ReadFromFile(filename);
    cout << "Encrypted text from file: " << loadedText << endl;

    string decryptedText = Decryption(loadedText, shift);
    cout << "Decrypted text: " << decryptedText << endl;
}