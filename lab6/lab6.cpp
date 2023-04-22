#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool comp(string a, string b) {
    return a > b;
}

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int main()
{
    string st;
    getline(cin, st);
    vector<string> strr = SplitIntoWords(st);

    sort(strr.begin(),strr.end(), comp);

    for (string word : strr) {
        cout << word << ' ';
    }
}

