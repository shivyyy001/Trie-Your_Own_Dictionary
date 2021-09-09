/* File which contains implementation of all functions of Trie dictionary */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// including the Trie.h header file which has declaration of all functions implemented here.
#include "Trie.h"

// Child_Size represents max number of children of a particular node , which is kept 256.
#define Child_Size 256

                        
/* structure TrieNode to make nodes of our Trie. It contains data , children array , isTerminal to check 
if a word ends at that node or not and meaning of a word , to store at end node of the word */
struct TrieNode
{
    char data;
    struct TrieNode *children[Child_Size];
    bool isTerminal;
    char *meaning;
};


// Function to create nodes.
struct TrieNode *returnTrie_Object(char val)
{
    /* Creating a node and allocating memory to it , making its isTerminal false initially , putting val into its
    data and allocating memory to its meaning */
    struct TrieNode *root = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    root->isTerminal = false;
    root->data = val;
    root->meaning = (char *)malloc(1000 * sizeof(char));
    
    // making children array for that node initially filled with NULL.
    for(int i = 0 ; i < Child_Size ; i++)
    {
        root->children[i] = NULL;
    }
    
    // returning the node made.
    return root;
}


// Function to assign meaning to a node.
void assign_meaning(struct TrieNode *root , char *mean)
{
    int len = strlen(mean);
    
    for(int i = 0; i < len ; i++)
    {
        root->meaning[i] = mean[i];
    }
}


// Function to insert a word with its meaning in Trie.
void insert_word(struct TrieNode *root , char *str , int pos , char *mean)
{
    /* if reached at end of string then make that node's isTerminal = true representing that a word ends at this node 
    and assign meaning to that last node.  */
    if(str[pos] == '\0')
    {
        /* if isTerminal of root is already true means that word is already present 
        thus we just need to update its meaning  */
        if(root->isTerminal == true)
        {
            assign_meaning(root , mean);
            printf("Meaning Updated for word '%s'.\n" , str);
        }
        
        // else make its isTerminal = true to add this word and then assign meaning to it.
        else
        {
            root->isTerminal = true;
            assign_meaning(root , mean);
            printf("'%s' inserted in your dictionary along with its meaning. \n" , str);
        }
        
        return;
    }
    
    // store ascii value of current character in index.
    int index = str[pos];
    
    // making a child node.
    struct TrieNode *child;
    
    // if root already has a child at index then put that node in child.
    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    
    /* else create a new node for child by calling returnTrie_Object function
    and put that node in root's children array. */ 
    else
    {
        child = returnTrie_Object(str[pos]);
        root->children[index] = child;
    }
    
    // call insert_word recursively with child as next root , and pos = pos+1 to insert next character of word.
    insert_word(child , str , pos + 1 , mean);
}


// Function to check if a word is present in Trie or not.
bool search_word(struct TrieNode *root , char *str , int pos)
{
    // if reached at end of string.
    if(str[pos] == '\0')
    {
        // if isTerminal for that node is true means that a words ends there ,  hence return true.
        if(root->isTerminal == true)
        {
            return true;
        }
        
        // else return false.
        else
        {
            return false;
        }
    }
    
    // store ascii value of current character in index.
    int index = str[pos];
    
    // if root has no child at index then return false.
    if(root->children[index] == NULL)
    {
        return false;
    }
    
    // else make a child node and store root's child at index in child node
    struct TrieNode *child;
    child = root->children[index];
    
    /* calling search_word recursively , passing that child node as next root and 
    pos=pos+1 to search for next character.  */
    return search_word(child , str , pos + 1);
}


// Function to delete a word from Trie.
void delete_word(struct TrieNode *root , char *str , int pos)
{
    // if reached at end of word make its isTerminal = false and return.
    if(str[pos] == '\0')
    {
        printf("'%s' deleted from your Trie dictionary. \n" , str);
        root->isTerminal = false;
        return;
    }
    
    // making a child node.
    struct TrieNode *child;
    
    // store ascii value of current character in index.
    int index = str[pos];
    
    // if root has a child at that index then put that node in child.
    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    
    // else return representing no such word is there to delete.
    else
    {
        printf("There is no such word present in your Trie dictionary to be deleted. \n");
        return;
    }
    
    // recursively calling delete_word with child as next root and pos=pos+1 to delete next character.
    delete_word(child , str , pos + 1);
    
    // if isTerminal of that child node is false.
    if(child->isTerminal == false)
    {
        for(int i = 0 ; i < Child_Size ; i++)
        {
            /* if that child node has even a single child then just return , means 
            that , that child node cant be deleted . */
            if(child->children[i] != NULL)
            {
                return;
            }
        }
        
        // else free that child node and mark NULL at root's children array for that child node.
        free(child);
        root->children[index] = NULL;
        
        return;
    }
    
}


// Function to search a prefix word.
struct TrieNode *search_the_prefix_word(struct TrieNode *root , char *word , int pos)
{
    // if reached at end of word then return root which is node of last character for that word.
    if(word[pos] == '\0')
    {
        printf("Suggestions to auto-complete '%s' are : \n" , word);
        return root;
    }
    
    // store ascii value of current character in index.
    int index = word[pos];
    
    // if root has no child at that index then return NULL.
    if(root->children[index] == NULL)
    {
        printf("No word in your Trie dictionary can auto-complete '%s' \n" , word);
        return NULL;
    }
    
    // make a child node and assign root's child at that index to it.
    struct TrieNode *child = root->children[index];
    
    /* calling search_the_prefix_word function recursively with child node as next root and
    pos=pos+1 to search for next character. */
    struct TrieNode *rec = search_the_prefix_word(child , word , pos + 1);
    
    // returning the node of last character of the prefix which is matched.
    return rec;
}


// Function to print the auto completed words.
void print_for_autocomplete(struct TrieNode *root , char *word , char *ans , int fill)
{
    // if root's isTerminal is true means that a word ends there.
    if(root->isTerminal == true)
    {
        // put NULL character at end of completed word.
        ans[fill] = '\0';
        
        // print the prefix and the completed part of word.
        printf("%s%s \n" , word , ans);
    }
    
    // iterate over all the children of root.
    for(int i = 0 ; i < Child_Size ; i++)
    {
        // if root has a child at a particular index.
        if(root->children[i] != NULL)
        {
            // fill that child's data in ans string to auto complete it.
            ans[fill] = root->children[i]->data;
            
            /* recursively call print_for_autocomplete function with child node at that particular
            index as root , updated ans string and fill=fill+1 to fill next character. */
            print_for_autocomplete(root->children[i] , word , ans , fill + 1);
            
            /* put NULL character at fill position as while backtracking the ans string will 
            show the updated part as strings in C are passed by reference , hence to make it original 
            again put NULL character at that fill index . */
            ans[fill] = '\0';
        }
    }
}


// Function to auto_complete a prefix word.
void auto_complete(struct TrieNode *root , char *word)
{
    /* calling search_the_prefix_word function to search for the prefix word. It returns
    node of last character of the prefix if it is present and NULL if it is not present */
    struct TrieNode *temp = search_the_prefix_word(root , word , 0);
    
    // making an empty string.
    char str[Child_Size];
    
    // if temp is no NULL then pass temp as root in print_for_autocomplete function to auto_complete the word.
    if(temp != NULL)
    {
        print_for_autocomplete(temp , word , str , 0);
    }
    
}


// Function to print meaning of a word.
void print_meaning(struct TrieNode *root , char *str , int pos)
{
    // if reached at end of word then print its meaning.
    if(str[pos] == '\0')
    {
        printf("The meaning of '%s' : %s \n" , str , root->meaning);
        return;
    }
    
    // store ascii value of current character in index.
    int index = str[pos];
    
    // if root has no child at that index then just return.
    if(root->children[index] == NULL)
    {
        printf("There is no such word present in your Trie dictionary \n");
        return;
    }
    
    // make a child node and assign root's child at that index to it.
    struct TrieNode *child = root->children[index];
    
    /* recursively call print_meaning function with child node as root and pos=pos+1 to check
    if next character of word whose meaning is to print is present in Trie or not. */
    print_meaning(child , str , pos + 1);
}


// Function to print all words with their meaning.
void print_all_words_with_meaning(struct TrieNode *root , char *str , int pos)
{
    // if isTerminal of root is true means a word ends at this node.
    if(root->isTerminal == true)
    {
        // put NULL character at end of current string.
        str[pos] = '\0';
        
        // print that string and its meaning.
        printf("Word : %s , Meaning : %s\n" , str , root->meaning);
    }
    
    // iterate over all the children of root.
    for(int i = 0 ; i < Child_Size ; i++)
    {
        // if root has a child at that particular index.
        if(root->children[i] != NULL)
        {
            // store that child's data in str string.
            str[pos] = root->children[i]->data;
            
            /* recursively call print_all_words_with_meaning function with child node at that particular
            index as root , updated str string and pos=pos+1 to fill next character. */
            print_all_words_with_meaning(root->children[i] , str , pos + 1);
            
            /* put NULL character at pos position as while backtracking the str string will 
            show the updated part as strings in C are passed by reference , hence to make it original 
            again put NULL character at that pos index . */
            str[pos] = '\0';
        }
    }
}


/* Helper Function to print all words and their meaning in Trie 
by calling print_all_words_with_meaning function. */
void get_trie(struct TrieNode *root)
{
    // create an empty string.
    char str[Child_Size];
    
    // to check if Trie dictionary is empty or not , check if root has atleast one child or not.
    bool isEmpty = true;
    for(int i = 0 ; i < Child_Size ; i++)
    {
        if(root->children[i] != NULL)
        {
            isEmpty = false;
            break;
        }
    }
    
    // if Trie dictionary is not empty.
    if(!isEmpty)
    {
        printf("All words with their meaning present in your Trie Dictionary are : \n");
        // call print_all_words_with_meaning function.
        print_all_words_with_meaning(root, str , 0);
    }
    
    // else if its empty.
    else
    {
        printf("Your Trie dictionary is currently empty \n");
    }
    
    return;
}


// Function to print the correct word , which is similar to wrong word entered.
void corrected_spell(struct TrieNode *root , char *ans , int fill)
{
    // if isTerminal of root is true means a word ends there.
    if(root->isTerminal == true)
    {
        ans[fill]='\0';
        printf("%s ?\n" , ans);
        return;
    }
    
    // iterate over all the children of root.
    for(int i = 0 ; i < Child_Size ; i++)
    {
        // if root has a child at that index.
        if(root->children[i] != NULL)
        {
            // fill data of that child in ans string.
            ans[fill] = root->children[i]->data;
            
            /* recursively call corrected_spell function with child node at that particular
            index as root , updated ans string and fill=fill+1 to fill next character. */
            corrected_spell(root->children[i] , ans , fill + 1);
            return;
        }
    }
    
    return;
}


// Function to check if there is actually a word similar to what user entered.
struct TrieNode *spell_check(struct TrieNode *root , char *word , int pos)
{
    // if reached at end of word.
    if(word[pos] == '\0')
    {
        // print only that prefix of word which is found yet.
        printf("Did you mean ");
        for(int i = 0 ; i < pos ; i++)
        {
            printf("%c" , word[i]);
        }
        
        return root;
    }
    
    // store ascii value of current character in index.
    int index = word[pos];
    
    // if root has no child at that index.
    if(root->children[index] == NULL)
    {
        // if root is not the root node of Trie.
        if(root->data != '\0')
        {
            // print only that prefix of word which is found yet.
            printf("Did you mean ");
            for(int i = 0 ; i < pos ; i++)
            {
                printf("%c" , word[i]);
            }
        }
        
        return root;
    }
    
    // make a child node and assign root's child at that index to it.
    struct TrieNode *child = root->children[index];
    
    /* calling spell_check function recursively with child node as next root and
    pos=pos+1 to check for next character. */
    struct TrieNode *rec = spell_check(child , word , pos + 1);
    
    return rec;
}


// Function to refine an incorrect word , if entered.
void refine_incorrect(struct TrieNode *root , char *word , int pos)
{
    /* calling spell_check function to check upto which character a word is correct.
    It returns node of last character of that prefix word else if no word matches it returns 
    root node of Trie. */
    struct TrieNode *temp = spell_check(root , word , pos);
    
    // if temp is not the root node of trie.
    if(temp->data != '\0')
    {
        // creating an empty string.
        char ans[Child_Size];
        
        // calling corrected_spell function to suggest a word that corrects the original word.
        corrected_spell(temp , ans , 0);
    }
    
    // else no similar word is present yet.
    else
    {
        printf("No word either same or similar to '%s' found in your Trie dictionary \n" , word);
    }
}



