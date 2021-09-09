/* Header file which contains Declaration of all functions implemented in Trie.c file. */


// including stdbool.h to include bool , to be used as return type.
#include <stdbool.h>

// Function to return an object of Trie , which is basically one Node of Trie. ( Time Complexity -> O(Child size) )
struct TrieNode *returnTrie_Object(char);

// Function to assign meaning to a word entered in Trie dictionary. ( Time Complexity -> O(Meaning size) )
void assign_meaning(struct TrieNode *, char *);

// Function to insert a word with its meaning in Trie dictionary. ( Time Complexity -> O(Word size) )
void insert_word(struct TrieNode * , char * , int , char *);

// Function to search a word in Trie dictionary. ( Time Complexity -> O(Word size) )
bool search_word(struct TrieNode * , char * , int);

// Function to delete a word from Trie dictionary. ( Time Complexity -> O(Word size) )
void delete_word(struct TrieNode * , char * , int);

// Helper Function to provide suggestions to auto-complete a prefix word from words in Trie dictionary. (Time Complexity -> near about O(Trie size x Words size) )
void auto_complete(struct TrieNode * , char *);

// Function to search the prefix word from Trie dictionary for auto-completing it. ( Time Complexity -> O(Word size) )
struct TrieNode *search_the_prefix_word(struct TrieNode * , char * , int);

// Function to print all the suggestions for auto-completing a prefix word from words in Trie dictionary.  (Time Complexity -> near about O(Trie size x Words size) ) 
void print_for_autocomplete(struct TrieNode * , char * , char * , int);

// Function to print meaning of a word present in Trie dictionary. ( Time Complexity -> O(Word size) )
void print_meaning(struct TrieNode * , char * , int);

// Helper Function to get all words with their meaning present in Trie dictionary. (Time Complexity -> near about O(Trie size x Words size) )
void get_trie(struct TrieNode *);

// Function to print all words with their meaning present in Trie dictionary. (Time Complexity -> near about O(Trie size x Words size) )
void print_all_words_with_meaning(struct TrieNode * , char * , int);

// Helper Function to refine an incorrect word from words present in Trie dictionary. ( Time Complexity -> O(Word size) )
void refine_incorrect(struct TrieNode * , char * , int);

// Function to check if a word is spelled correct or not. ( Time Complexity -> O(Word size) )
struct TrieNode *spell_check(struct TrieNode * , char * , int);

// Function to print the corrected word from Trie dictionary , for any incorrect word entered. ( Time Complexity -> O(Word size) ) 
void corrected_spell(struct TrieNode * , char * , int);


