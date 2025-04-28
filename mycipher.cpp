#include <iostream>
#include <string>
#include <cctype>  
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " shift_amount" << endl;
        return 1;
    }

    int shift = stoi(argv[1]) % 26;
    string input;
    string cleaned = "";

    
    while (getline(cin, input)) {
        for (char c : input) {
            if (isalpha(c)) {
                c = toupper(c);
                c = ((c - 'A' + shift) % 26) + 'A'; 
                cleaned += c;
            }
        }
    }

    
    int count = 0;
    for (char c : cleaned) {
        cout << c;
        count++;
        if (count % 5 == 0) cout << " ";
        if (count % 50 == 0) cout << endl;
    }
    if (count % 50 != 0) cout << endl;

    return 0;
}
