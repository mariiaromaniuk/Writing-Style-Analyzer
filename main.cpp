//
//  main.cpp
//  Tree Project
//
//  Created by Mariia Romaniuk
//

#include <fstream>
#include "BSTreeReader.hpp"

int main(){
    ifstream file;
    ofstream out;
    string name;
    string str;
    
    cout << "Enter file name: ";
    cin >> name;
    
    try {
        file.open(name, ios::in);
        out.open("report.txt", ios::out);
        if (file.fail() || out.fail())
            throw string("Error opening input file.");
    }
    catch(string msg){
        cout << msg << endl;
    }
    
    BSTreeReader report;
    
    // Insert words into Binary Search Tree Reader
    while (file >> str){
        report.insert(str);
    }
    file.close();
    report.analyzeDummy();
    
    out << "File name: " << name << endl;
    out << "\n\n---------- STATISTICAL SUMMARY -----------" << endl;
    out << "Total words: " << report.getTotalWords() << endl;
    out << "Total unique words: " << report.getTotalUniqueWords() << endl;
    out << "Total unique words of more than three letters: " << report.getTotalUniqueWordsThree() << endl;
    out << "Average word length: " << report.getAvgWordLength() << endl;
    out << "Average sentence length: " << report.getAvgSentenceLength() << endl;
    
    out << "\n\n------------- STYLE WARNINGS -------------" << endl;
    out << "Words used too often" << endl;
    vector<string> often = report.getUsedOften();
    int i = 1;
    for (vector<string>::iterator it = often.begin(); it != often.end(); ++it) {
        out << i << ") " << *it;
    }

    int avg = report.getAvgSentenceLength();
    if (avg > 10)
        out << "Average sentence length too long: " << avg << endl;
    
    avg = report.getAvgWordLength();
    if (avg > 5)
        out << "Average word length too long: " << avg << endl;
    
    out << "\n\n--------- INDEX OF UNIQUE WORDS ----------" << endl;
    report.printIndexesFileDummy(out);
    out.close();
    
    return 0;
}
