# Assignment - P02
### This program reads a list of words from a dictionary.txt file and saves them to a linked list. It has a time complexity of O(n) because the linked list is used to store and search the data.

- The program allows the user to enter a word character by character and displays auto-suggestions for the entered word in real-time, without the need to press enter. 
- This is achieved by using the getch method to add each character to the input and searching the linked list directly.

- The search method uses the equalsIgnoreCase method to ignore case while comparing the key entered by the user with the words in the linked list. 
- Before each search, a timer is started and the time taken to search is computed at the end.
- The program displays the first 10 suggestions and the count of all suggestions. It will end when the user presses enter or Ctrl+C.
