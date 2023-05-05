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
#include <conio.h>
#include <cstdlib> 
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


// Defining struct to hold a word
struct wordNode {
    std::string word;
    wordNode* next;
};


// Function to compare two strings ignoring case
bool equalsIgnoreCase(std::string str1, std::string str2) {
    // convert both strings to lowercase
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return (str1 == str2);
}
// Defining a class to hold a linked list of words
class WordList {
private:
    wordNode* head;
public:
    // Function to insert a word at the beginning of the linked list
    void insert(std::string word) {
        wordNode* newNode = new wordNode;
        newNode->word = word;
        newNode->next = head;
        head = newNode;
    }
    
    // Function to search for words that start with a given key
    void search(std::string key) {
        wordNode* current = head;
        int count=0;
        while (current != nullptr) {
            if (equalsIgnoreCase(current->word.substr(0, key.length()),key)) {
                if (count < 10){
                    // cout << "Inside Search for " << key;
                    std::cout << current->word << ", ";
                }
                count++;
            }
            current = current->next;
        }
        cout << endl;
        cout <<"Elemnts found - " <<count <<endl; 
    }
};

int main() {
    system("cls");
    //delaring input variable
    string input;
    char c;
    
    //start time varible
    auto t_start = std::chrono::high_resolution_clock::now();
    //end time variable
    auto t_end = std::chrono::high_resolution_clock::now();
    double timegap;
    string line;
    WordList myList;
    int count;
    std::ifstream file("dictionary.txt");

    // adding all words to the linked list from file
    while (std::getline(file,line)){
        myList.insert(line); 
        // count++;
    }

    cout << "Enter a word: ";
    //Reading a char each time and printing suggestions for that without need of pressing enter every time
    do {

        c = _getch();
       if(c == 0x03) {
            break;
        }
        
        input += c;
        
        system("cls"); //clearing old content every time

        cout << "\r" << string(input.size(), ' ') << "\r";
        cout << "Enter a word: " << input;
        
        cout << endl << "Auto Suggestions for : " << input << endl;
        
        //Searching and started timer to find time taken to search
        t_start = std::chrono::high_resolution_clock::now();
        myList.search(input);
        t_end = std::chrono::high_resolution_clock::now();
        timegap = std::chrono::duration<double, std::micro>(t_end - t_start).count();
        
        cout <<"took "<< timegap << " milli to suggest" <<endl;

    } while (c != '\r');
    return 0;
}
