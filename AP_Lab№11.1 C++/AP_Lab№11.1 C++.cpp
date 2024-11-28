#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція для виведення вмісту файлу
void DisplayFileContent(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();
}

// Функція підрахунку входжень послідовності "while"
int CountWhileOccurrences(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return 0;
    }

    int whileCount = 0;
    string line;
    while (getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find("while", pos)) != string::npos) {
            whileCount++;
            pos += 5;  // довжина "while"
        }
    }
    inputFile.close();
    return whileCount;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    // Виведення вмісту файлу
    cout << "\nFile contents:\n";
    DisplayFileContent(filename);

    // Підрахунок входжень "while"
    int occurrences = CountWhileOccurrences(filename);
    cout << "\nNumber of 'while' occurrences: " << occurrences << endl;

    return 0;
}