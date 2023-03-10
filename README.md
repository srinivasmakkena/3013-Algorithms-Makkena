# Assignment - P01
###This program reads data from a JSON file and stores it in a vector of Person structs. The data is then shuffled to maintain the structure of a binary search tree (BST) and inserted into both a BST and linked list. The program provides various methods for searching the data based on different keys and data types

- To store the data, the Person struct was defined to contain all fields that the JSON contains.
- The data was converted to Person objects and stored in a vector after being read from JSON
- The data was then shuffled to maintain the structure of the BST and stored back in the Person vector.

- The data from vector was inserted into two data structures, the BST and linked list
- Several binary search trees were created to save data based on different keys to enable searching over them.
- The key was saved in the key attribute and the person data in the person attribute in every node.
- Different methods were created to handle insertion operations with different key types, such as int for ID, double for GPS, and string for the remaining fields.
- Similarly, different methods were created for searching different keys in the BST with different types.
- In the same way, methods were created for linked lists to insert and search based on different key types, such as int for ID, double for GPS, and string for the remaining fields.
- The user was provided with a menu to choose the key on which the search should be performed.
- A switch case was used to select the BST for searching.
- While searching, the strings were converted to lowercase and checked to avoid case mismatches.
- For BST the string key comparision restricts the search to check for the intermediate string directly as it will start comapring from the first index.
- while inserting GPS data, the latitude and longitude data sum is used for comarision.
- But in Linked list the search will work better on strings when comapred to BST as we are searching over all items lineraly.
