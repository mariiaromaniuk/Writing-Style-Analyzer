//
//  BSTreeReader.cpp
//  Tree Project
//
//  Created by Mariia Romaniuk
//

#include "BSTreeReader.hpp"

BSTreeReader::BSTreeReader(){
    totalWords = 0;
    totalUnique = 0;
    totalUniqueThree = 0;
    totalSentences = 0;
    avgWordLength = 0;
    avgSentenceLength = 0;
    change = '1';
}


// Function that analyzes information of a nodes
void BSTreeReader::analyze(Node<string>* p){
    if (p != nullptr){
        if (p->left != nullptr)
            analyze(p->left);
        totalUnique++;
        avgWordLength += p->info.length() + (p->info.length() * p->count);
        if (p->info.length() > 3){
            totalUniqueThree++;
            if (p->count > (.05 * totalWords))
                usedOften.push_back(p->info);
        }
        if (p->right != nullptr)
            analyze(p->right);
    }
}


// Getter function for usedOften
vector<string> BSTreeReader::getUsedOften(){
    return usedOften;
}

// Getter function for totalUnique
int BSTreeReader::getTotalUniqueWords(){
    return totalUnique;
}

// Getter function for totalUniqueThree
int BSTreeReader::getTotalUniqueWordsThree(){
    return totalUniqueThree;
}

// Getter function for totalWords
int BSTreeReader::getTotalWords(){
    return totalWords;
}

// Getter function for TotalSentences
int BSTreeReader::getTotalSentences(){
    return totalSentences;
}

// Getter function for avgSentenceLength
int BSTreeReader::getAvgSentenceLength(){
    return avgSentenceLength;
}

// Function that calculates average word length
int BSTreeReader::getAvgWordLength(){
    if (totalWords == 0)
        totalWords = 1;
    return avgWordLength/totalWords;
}


// Function that prints out each node's data in order
void BSTreeReader::inOrder(Node<string>* p){
    if (p != nullptr) {
        if(p->left!=nullptr)
            inOrder(p->left);
        cout << p->info << endl;
        if (p->right != nullptr)
            inOrder(p->right);
    }
}


// Dummy function to pass the root into displayTree()
void BSTreeReader::displayTree(){
    inOrder(root);
}

// Dummy function to pass the root into analyze()
void BSTreeReader::analyzeDummy(){
    analyze(root);
}

// Dummy function to pass the root into printIndexes()
void BSTreeReader::printIndexesDummy(){
    printIndexes(root);
}

// Dummy function to pass the root into printIndexesFile()
void BSTreeReader::printIndexesFileDummy(ofstream& out){
    printIndexesFile(root, out);
}


// Insertion into a Binary Search Tree Reader
// No punctuation is allowed, words are inserted as lowercase
void BSTreeReader::insert(string str){
    totalWords++;
    Node<string>* temp = new Node<string>;
    str = toLowerString(str);
    char ch = str[str.length() - 1];
    
    if (ch == '.' || ch == ',' || ch == ':' || ch == ';' ||
        ch == '/' || ch == '"' || ch == '!' || ch == '?'){
        temp->info = str.substr(0, str.length() - 1);
        if (ch == '.' || ch == '!' || ch == '?'){
            totalSentences++;
            if (totalSentences == 0)
                totalSentences = 1;
            avgSentenceLength = totalWords/totalSentences;
        }
    }
    else
        temp->info = str;
    temp->left = temp->right = nullptr;
    
    if (root == nullptr)
        root = temp;
    else {
        Node<string>* p = root;
        Node<string>* r = nullptr;
        
        while (p != nullptr) {
            r = p;
            if (equals(p->info, str)) {
                p->count += 1;
                return;
            }
            else if (p->info > str)
                p = p->left;
            else
                p = p->right;
        }
        
        if (r->info < str)
            r->right = temp;
        else
            r->left = temp;
    }
}


// Function that checks if two strings are equivalent
bool BSTreeReader::equals(string treeNode, string str) {
    char ch = str[str.length() - 1];
    
    if (treeNode == str || (treeNode == str.substr(0, str.length() - 1)
                            && (ch == '.' ||  ch == ',' || ch == ':' || ch == ';' ||
                                ch == '/' || ch == '"' || ch == '!' || ch == '?')))
        return true;
    else
        return false;
}


// Function that converts string to lowercase
string BSTreeReader::toLowerString(string str) {
    
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
    return str;
}


// Function that prints all unique words of a tree prefaced by first letter of character
void BSTreeReader::printIndexes(Node<string>* p) {
    
    if (p != nullptr){
        if (p->left != nullptr) printIndexes(p->left);
        if (change != p->info[0]){
            char x = toupper(p->info[0]);
            cout << x << endl;
            change = p->info[0];
        }
        cout << p->info << endl;
        if (p->right != nullptr) printIndexes(p->right);
    }
}


// Function that prints to a file 
void BSTreeReader::printIndexesFile(Node<string>* p, ofstream& out){
    if (p != nullptr){
        if (p->left != nullptr) printIndexesFile(p->left, out);
        if (change != p->info[0]) {
            char x = toupper(p->info[0]);
            out << endl << x << endl;
            change = p->info[0];
        }
        out << p->info << endl;
        if (p->right != nullptr) printIndexesFile(p->right, out);
    }
}
