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

string get_lower(string str)
{
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

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

LLNode *search_in_LL(LLNode *node, string search_key)
{ int comp=0;
  if (node == NULL)
  {
    return node;
  }
  while (node != NULL)
  { comp++;
    if (get_lower(node->data.first_name).find(search_key) != string::npos || get_lower(node->data.last_name).find(search_key) != string::npos || get_lower(node->data.email).find(search_key) != string::npos || get_lower(node->data.address).find(search_key) != string::npos || get_lower(node->data.city).find(search_key) != string::npos || get_lower(node->data.state).find(search_key) != string::npos || get_lower(node->data.car).find(search_key) != string::npos || get_lower(node->data.phone_number).find(search_key) != string::npos)
    { cout << "Compared "<< comp << " Nodes."<<endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared "<< comp << " Nodes."<<endl;
  return node;
}

struct BST
{
  string key;
  Person person;
  BST *left;
  BST *right;
};

// Insert a new person into the tree
void insert(BST *&root, Person person, string key)
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

// Insert a new person into the tree
void insert(BST *&root, Person person, int key)
{
  if (root == NULL)
  {
    root = new BST;
    root->key = to_string(key);
    root->person = person;
    root->left = NULL;
    root->right = NULL;
  }
  else
  {
    if (key < stoi(root->key))
    {
      insert(root->left, person, key);
    }
    else
    {
      insert(root->right, person, key);
    }
  }
}

// Insert a new person into the tree
void insert(BST *&root, Person person, double key)
{
  if (root == NULL)
  {
    root = new BST;
    root->key = to_string(key);
    root->person = person;
    root->left = NULL;
    root->right = NULL;
  }
  else
  {
    if (person.latitude+person.longitude < stod(root->key))
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
BST *search(BST *root, int search_key)
{ static int visits=0;
  visits++;
  if (root == NULL || root->person.id==search_key)
  {
    cout<< "Visited "<< visits<<" nodes in BST."<<endl;
    return root;
    
  }
  else if (search_key < root->person.id)
  {
    return search(root->left, search_key);
  }
  else
  {
    return search(root->right, search_key);
  }
}

// Search for a person in the tree
BST *search(BST *root, string search_key)
{ static int visits=0;
  visits++;
  if (root == NULL || root->key.find(search_key) != string::npos)
  {
    cout<< "Visited "<< visits<<" nodes in BST."<<endl;
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


// Search for a person in the tree
BST *search(BST *root, double latitude, double longitude)
{ static int visits=0;
  visits++;
  if (root == NULL || root->person.latitude + root->person.longitude == (latitude+longitude))
  {
    cout<< "Visited "<< visits<<" nodes in BST."<<endl;
    return root;
    
  }
  else if ((latitude+longitude) < (root->person.latitude + root->person.longitude) )
  {
    return search(root->left, latitude,longitude);
  }
  else
  {
    return search(root->right, latitude, longitude);
  }
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

  for (size_t i = 0; i < j.size(); i++)
  // for (size_t i = 0; i < 10; i++)
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
    insert(bst_id, person, person.id);
    insert(bst_fname, person, get_lower(person.first_name));
    insert(bst_lname, person, get_lower(person.last_name));
    insert(bst_address, person, get_lower(person.address));
    insert(bst_email, person, get_lower(person.email));
    insert(bst_city, person, get_lower(person.city));
    insert(bst_state, person, get_lower(person.state));
    insert(bst_car, person, get_lower(person.car));
    insert(bst_phone_number, person, get_lower(person.phone_number));
    insert(bst_gps, person, (person.latitude + person.longitude));
    insert_in_LinkedList(&linkedlist, person);
    cout << "Inserted " << person.id << " - " << person.first_name << " - " << person.last_name << "\n";
  }
  int choice;
  cout << "Select based in which key you wants to search:\n"
       << "0.Id\n"
       << "1.First Name\n"
       << "2.Last Name\n"
       << "3.Address\n"
       << "4.Email\n"
       << "5.City\n"
       << "6.State\n"
       << "7.Car\n"
       << "8.Phone number\n"
       << "9.GPS\n"
       << "10.Exit\n";
  cout << "Enter Your Choice:";
  cin >> choice;
  string search_key;
  auto t_start = std::chrono::high_resolution_clock::now();
  auto t_end = std::chrono::high_resolution_clock::now();
  auto t_end2 = std::chrono::high_resolution_clock::now();
  double timegap;
  BST *p;
  LLNode *p2;
  double latitude;
  double longitude;
  while (choice != 10)
  {
    if (choice==9){
      cout << "Enter latitude to be searched from Data:";
      cin >> latitude;
      cout << "Enter longitude to be searched from Data:";
      cin >> longitude;
    }
    else{
      cout << "Enter string to be searched from Data:";
      cin >> search_key;
    }
    search_key = get_lower(search_key);
    t_start = std::chrono::high_resolution_clock::now();
    switch (choice)
    {
    case 0:
      p = search(bst_id, search_key);
      break;
    case 1:
      p = search(bst_fname, search_key);
      break;
    case 2:
      p = search(bst_lname, search_key);
      break;
    case 3:
      p = search(bst_address, search_key);
      break;
    case 4:
      p = search(bst_email, search_key);
      break;
    case 5:
      p = search(bst_city, search_key);
      break;
    case 6:
      p = search(bst_state, search_key);
      break;
    case 7:
      p = search(bst_car, search_key);
      break;
    case 8:
      p = search(bst_phone_number, search_key);
      break;
    case 9:
      p = search(bst_gps, latitude,longitude);
      break;
    }
    t_end = std::chrono::high_resolution_clock::now();
    p2 = search_in_LL(linkedlist, search_key);
    t_end2 = std::chrono::high_resolution_clock::now();
    timegap = std::chrono::duration<double, std::micro>(t_end - t_start).count();
    cout << "Completed search in BST in " << timegap << " micro sec" << endl;
    timegap = std::chrono::duration<double, std::micro>(t_end2 - t_end).count();
    cout << "Completed search in Linked List in " << timegap << " micro sec" << endl;
    if (p != NULL)
    {
      cout << "Found String " + search_key + " in "
           << p->person.first_name << endl;
      std::string stocks;
      for (std::vector<std::string>::const_iterator i = p->person.stocks.begin(); i != p->person.stocks.end(); ++i)
        stocks += *i + ", ";
      cout << "Details of person are" << endl;
      cout << "id : " << p->person.id << "\nfirst_name : " << p->person.first_name << "\nlast_name : " << p->person.last_name << "\nemail: " << p->person.email << "\naddress: " << p->person.address << "\ncity: " << p->person.city << "\nstate: " << p->person.state << "\nlatitude: " << p->person.latitude << "\nlongitude: " << p->person.longitude << "\ncar: " << p->person.car << "\ncar_model: " << p->person.car_model << "\ncar_color: " << p->person.car_color << "\nfavorite_movie: " << p->person.favorite_movie << "\npet: " << p->person.pet << "\njob_title: " << p->person.job_title << "\nphone_number: " << p->person.phone_number << "\nstocks: " << stocks << endl;
    }
    else
    {
      cout << "Not Found in BST." << endl;
    }
    if (p2 != NULL)
    {
      cout << "Found in Linked List also" << endl;
    }
    else
    {
      cout << "Not found in LinkedList" << endl;
    }
    cout << "Select based in which key you wants to search:\n"
         << "0.Id\n"
         << "1.First Name\n"
         << "2.Last Name\n"
         << "3.Address\n"
         << "4.Email\n"
         << "5.City\n"
         << "6.State\n"
         << "7.Car\n"
         << "8.Phone number\n"
         << "9.GPS\n"
         << "10.Exit\n";
    cout << "Enter Your Choice:";
    cin >> choice;
    cout << "Choice is " << choice << endl;
  }
}