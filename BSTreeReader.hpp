//
//  BSTreeReader.hpp
//  Tree Project
//
//  Created by Mariia Romaniuk
//

#ifndef BSTreeReader_hpp
#define BSTreeReader_hpp

#include "BSTree.cpp"
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;


class BSTreeReader : public BSTree<string>{
    
private:
    int totalWords;
    int totalUnique;
    int totalUniqueThree;
    int totalSentences;
    int avgWordLength;
    int avgSentenceLength;
    vector<string> usedOften;
    void inOrder(Node<string>*);
    bool equals(string, string);
    string toLowerString(string);
    void analyze(Node<string>*);
    void printIndexes(Node<string>*);
    void printIndexesFile(Node<string>*, ofstream& out);
    char change; // helps with printing indexes
    
public:
    BSTreeReader();
    int getTotalWords();
    int getTotalUniqueWords();
    int getTotalUniqueWordsThree();
    int getTotalSentences();
    int getAvgWordLength();
    int getAvgSentenceLength();
    vector<string> getUsedOften();
    void insert(string);
    void displayTree();
    void analyzeDummy();
    void printIndexesDummy();
    void printIndexesFileDummy(ofstream& out);
};

#endif /* BSTreeReader_hpp */
