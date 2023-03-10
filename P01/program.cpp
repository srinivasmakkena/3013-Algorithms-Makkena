#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;
using json = nlohmann::json;

// Define the person struct
struct Person
{
  int id;
  string first_name;
  string last_name;
  string email;
  string address;
  string city;
  string state;
  double latitude;
  double longitude;
  string car;
  string car_model;
  string car_color;
  string favorite_movie;
  string pet;
  string job_title;
  string phone_number;
  vector<string> stocks;
};

struct LLNode
{
  Person data;
  struct LLNode *next;
};

void insert_in_LinkedList(LLNode **root, Person person)
{
  cout << "1";
  LLNode *new_node = new LLNode();
  new_node->data = person;
  new_node->next = NULL;
  if (*root == NULL)
  {
    *root = new_node;
  }
  else
  {
    LLNode *last_node = *root;
    while (last_node->next != NULL)
    {
      last_node = last_node->next;
    }
    last_node->next = new_node;
  }
}


class BST{
    private:
        string key;
        Person person;
        BST *left;
        BST *right;
    public:
        BST(){
            left=NULL;
            right=NULL;
        }
        // Insert a new person into the tree
        void insert(Person person, string key)
        {
        if (root == NULL)
        {
            root = new BST;
            root->key = key;
            root->person = person;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            if (key < root->key)
            {
            insert(root->left, person, key);
            }
            else
            {
            insert(root->right, person, key);
            }
        }
        }        
        // Search for a person in the tree
        BST *search(string search_key)
        {
        if (root == NULL || root->key.find(search_key) != string::npos)
        {
            return root;
        }
        else if (search_key < root->key)
        {
            return search(root->left, search_key);
        }
        else
        {
            return search(root->right, search_key);
        }
        }
}; 


string get_lower(string str)
{
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

int main()
{
  BST *bst_id = NULL;
  BST *bst_fname = NULL;
  BST *bst_lname = NULL;
  BST *bst_address = NULL;
  BST *bst_email = NULL;
  BST *bst_city = NULL;
  BST *bst_state = NULL;
  BST *bst_car = NULL;
  BST *bst_phone_number = NULL;
  BST *bst_gps = NULL;
  LLNode *linkedlist = NULL;

  std::ifstream file("C:\\Users\\Srinivas Makkena\\Documents\\MSU\\Adv Structures & Algo\\Aassignment-1\\data.json");
  std::string str;

  json j;
  file >> j;

  std::vector<Person> Persons;

  // for (size_t i = 0; i < j.size(); i++)
  for (size_t i = 0; i < 10; i++)
  {

    vector<string> stocks;

    for (const auto &elem : j[i]["stocks"])
    {
      stocks.push_back(elem.get<std::string>());
    }

    Person person = {j[i]["id"], j[i]["first_name"], j[i]["last_name"], j[i]["email"], j[i]["address"], j[i]["city"], j[i]["state"], j[i]["latitude"], j[i]["longitude"], j[i]["car"], j[i]["car_model"], j[i]["car_color"], j[i]["favorite_movie"], j[i]["pet"], j[i]["job_title"], j[i]["phone_number"], stocks};
    Persons.push_back(person);
  }

  // Given some container `container`...
  std::shuffle(Persons.begin(), Persons.end(), std::random_device());
  for (auto person : Persons)
  {
    cout << "Inserting " << person.id << " - " << person.first_name << " - " << person.last_name << endl;
    insert(bst_id, person, get_lower(to_string(person.id)));
    insert(bst_fname, person, get_lower(person.first_name));
    insert(bst_lname, person, get_lower(person.last_name));
    insert(bst_address, person, get_lower(person.address));
    insert(bst_email, person, get_lower(person.email));
    insert(bst_city, person, get_lower(person.city));
    insert(bst_state, person, get_lower(person.state));
    insert(bst_car, person, get_lower(person.car));
    insert(bst_phone_number, person, get_lower(person.phone_number));
    insert(bst_gps, person, get_lower(to_string(person.latitude + person.longitude)));
    insert_in_LinkedList(&linkedlist, person);
  }

  string search_key = "Clevey";
  cout << "Enter string to be searched from Data:";
  cin >> search_key;
  search_key = get_lower(search_key);
  auto t_start = std::chrono::high_resolution_clock::now();
  // Search for a person by composite key
  search(bst_fname, search_key);
  auto t_end = std::chrono::high_resolution_clock::now();
  double elapsed_time_ms = std::chrono::duration<double, std::micro>(t_end - t_start).count();

  cout << "Completed in " << elapsed_time_ms << " micro sec" << endl;

  if (search(bst_fname, search_key) != NULL)
  {
    Person p = search(bst_fname, search_key)->person;

    cout << "Found String " + search_key + " in "
         << p.first_name << endl;

    std::string stocks;

    for (std::vector<std::string>::const_iterator i = p.stocks.begin(); i != p.stocks.end(); ++i)
      stocks += *i + ", ";
    cout << "Details of person are" << endl;
    cout << "id : " << p.id << "\nfirst_name : " << p.first_name << "\nlast_name : " << p.last_name << "\nemail: " << p.email << "\naddress: " << p.address << "\ncity: " << p.city << "\nstate: " << p.state << "\nlatitude: " << p.latitude << "\nlongitude: " << p.longitude << "\ncar: " << p.car << "\ncar_model: " << p.car_model << "\ncar_color: " << p.car_color << "\nfavorite_movie: " << p.favorite_movie << "\npet: " << p.pet << "\njob_title: " << p.job_title << "\nphone_number: " << p.phone_number << "\nstocks: " << stocks << endl;
  }
  else
  {
    cout << "Not found " << search_key;
  }
}
