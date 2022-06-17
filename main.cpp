#include <iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    string choice;
    bool encrypt = true;
    string word,key,result = "";
    char CASE;
    while (true)
    {
        cout << "Enter [E] to Encrypt a file, [D] to Decrypt a file, [Q] to Quit: ";
        getline(cin, choice);

        if (choice == "E" || choice == "e")
        {
            cout << "Enter string to Encrypt: ";
            cin >> word;
            cout << "Enter key word: ";
            cin >> key;
            break;
        }

        else if (choice == "D" || choice == "d")
        {
            cout << "Enter string to Decrypt: ";
            encrypt = false;
            cin >> word;
            cout << "Enter key word: ";
            cin >> key;
            break;
        }

        else if (choice == "Q" || choice == "q")
        {
            return 0;
        }

        cout << "Entered incorrect input: " << choice << ", please try again " << "\n";
    }

    string Okey = key;
    if (word.size() > key.size()) {
        int c = (word.size() / key.size()) + 1;
        for (int i = 0; i < c-1; i++) {
            key += Okey;
        }
    }

    if (encrypt) {
        for (int i = 0; i < word.size(); i++) {
            if (65 <= word[i] && word[i] <= 90 && 65 <= key[i] && key[i] <= 90) {
                CASE = char((((word[i] - 65) + (key[i] - 65)) % 26)+65);
            }
            else if (97 <= word[i] && word[i] <= 122 && 65 <= key[i] && key[i] <= 90) {
                CASE = char((((word[i] - 97) + (key[i] - 65)) % 26)+97);
            }
            else if (65 <= word[i] && word[i] <= 90 && 97 <= key[i] && key[i] <= 122) {
                CASE = char((((word[i] - 65) + (key[i] - 97)) % 26) + 65);
            }
            else if (97 <= word[i] && word[i] <= 122 && 97 <= key[i] && key[i] <= 122) {
                CASE = char((((word[i] - 97) + (key[i] - 97)) % 26) + 97);
            }
            
            result.push_back(CASE);
        }
    }
    else {
        for (int i = 0; i < word.size(); i++) {
            if (65 <= word[i] && word[i] <= 90 && 65 <= key[i] && key[i] <= 90) {
                CASE = char((((word[i] - 65) - (key[i] - 65) + 26) % 26) + 65);
            }
            else if (97 <= word[i] && word[i] <= 122 && 65 <= key[i] && key[i] <= 90) {
                CASE = char((((word[i] - 97) - (key[i] - 65) + 26) % 26) + 97);
            }
            else if (65 <= word[i] && word[i] <= 90 && 97 <= key[i] && key[i] <= 122) {
                CASE = char((((word[i] - 65) - (key[i] - 97) + 26) % 26) + 65);
            }
            else if (97 <= word[i] && word[i] <= 122 && 97 <= key[i] && key[i] <= 122) {
                CASE = char((((word[i] - 97) - (key[i] - 97) + 26) % 26) + 97);
            }

            result.push_back(CASE);
        }
    }
    
    cout << result;
}

