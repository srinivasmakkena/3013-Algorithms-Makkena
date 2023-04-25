# Assignment - P02
## A trie is a tree-like data structure used for efficient string searching. In this program, a trie is built using the words in a dictionary.txt file. The time complexity of building the trie is O(n * k), where n is the number of words in the dictionary and k is the length of the longest word.

- Once the trie is built, the program allows the user to enter a word character by character and displays auto-suggestions for the entered word in real-time, without the need to press enter.

- Each character entered by the user is used to traverse the trie and find all words with the same prefix. The search time is O(k), where k is the length of the entered word.

- Before each search, a timer is started and the time taken to search is computed at the end.

- The program displays the first 10 suggestions and the count of all suggestions. It will end when the user presses enter or Ctrl+C.
