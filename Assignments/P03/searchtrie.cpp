//  $$$$$$$$    $$$$$    $$$$$$$ 
//  $$     $$  $$   $$  $$     $$
//  $$     $$ $$     $$        $$
//  $$$$$$$$  $$     $$  $$$$$$$ 
//  $$        $$     $$ $$       
//  $$         $$   $$  $$       
//  $$          $$$$$   $$$$$$$$$

//   $$$$$$$    $$$$$      $$    $$$$$$$ 
//  $$     $$  $$   $$   $$$$   $$     $$
//         $$ $$     $$    $$          $$
//   $$$$$$$  $$     $$    $$    $$$$$$$ 
//         $$ $$     $$    $$          $$
//  $$     $$  $$   $$     $$   $$     $$
//   $$$$$$$    $$$$$    $$$$$$  $$$$$$$ 

//  $$     $$    $$$    $$    $$ $$    $$ $$$$$$$$ $$    $$    $$$   
//  $$$   $$$   $$ $$   $$   $$  $$   $$  $$       $$$   $$   $$ $$  
//  $$$$ $$$$  $$   $$  $$  $$   $$  $$   $$       $$$$  $$  $$   $$ 
//  $$ $$$ $$ $$     $$ $$$$$    $$$$$    $$$$$$   $$ $$ $$ $$     $$
//  $$     $$ $$$$$$$$$ $$  $$   $$  $$   $$       $$  $$$$ $$$$$$$$$
//  $$     $$ $$     $$ $$   $$  $$   $$  $$       $$   $$$ $$     $$
//  $$     $$ $$     $$ $$    $$ $$    $$ $$$$$$$$ $$    $$ $$     $$

//importing required libraries 
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <conio.h>


using namespace std;

static int count=0;

// Define the trie node structure
struct TrieNode {
    TrieNode* children[26]; // Array of pointers to child nodes
    bool isEndOfWord; // Flag to indicate if this node marks the end of a word
    TrieNode() {
        // Initialize all child pointers to NULL
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

// Insert a word into the trie
void insertWord(TrieNode* root, string word) {
    TrieNode* current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            // If the current character is not already present, create a new node for it
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}


// Recursively print all words below the given trie node
int printWords(TrieNode* node, string prefix) {
    if (node->isEndOfWord) {
        count++;
        if (count <=10) cout << prefix << ", ";
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            char c = 'a' + i;
            printWords(node->children[i], prefix + c);
        }
    }
    return count;
}

// Search for all words that start with the given prefix
void searchWords(TrieNode* root, string prefix) {
    TrieNode* current = root;
    for (int i = 0; i < prefix.length(); i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            // If the prefix is not found, return without printing any words
            return;
        }
        current = current->children[index];
    }
    // If the prefix is found, recursively print all words below it
    cout << "Suggestions are:";
    int current_count=printWords(current, prefix );
    cout << "...\nFound " << current_count << " Items." << endl;
}


int main() {
    TrieNode* root = new TrieNode();
    std::ifstream file("dictionary.txt");
    string line;
    // adding all words to the linked list from file
    while (std::getline(file,line)){
            insertWord(root, line);
    }
    auto t_start = std::chrono::high_resolution_clock::now();
    //end time variable
    auto t_end = std::chrono::high_resolution_clock::now();
    double timegap;
        
    string prefix;
    string input;
    char c;
    system("cls");
    cout << "Enter a word: ";
        //Reading a char each time and printing suggestions for that without need of pressing enter every time
    do {
        c = _getch();
        if(c == 0x03) {
            break;
            }
        
        prefix += c;
        
        system("cls"); //clearing old content every time

        cout << "\r" << string(prefix.size(), ' ') << "\r";
        cout << "Words starting with \"" << prefix << "\":" << endl;
        t_start = std::chrono::high_resolution_clock::now();
 
        cout << endl << "Auto Suggestions for : " << prefix << endl;
        count=0;
        searchWords(root, prefix);        
        //Searching and started timer to find time taken to search
        

        t_end = std::chrono::high_resolution_clock::now();
        timegap = std::chrono::duration<double, std::micro>(t_end - t_start).count();
        
        cout <<"took "<< timegap << " milli to suggest" <<endl;

    } while (c != '\r');
        
    
    return 0;
}
