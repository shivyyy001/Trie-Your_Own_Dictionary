/*
 * Project -> Implementing Tries as dictionary , including auto-complete and auto-correct.
 *
 * Compilation : gcc Main_Function.c Trie.c Trie.h
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 09/09/2021
 * Trie - The Magic Tree.
 *
 * Resources - Wikipedia to understand about Tries and its applications.
 *
 */



/*  File which contains the main function.  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// including Trie.h header file made.
#include "Trie.h"


// Function to take meaning as input from user , which can have multiple words.
void take_meaning_input(char *str)  
{
    int len = 0;
    char ch;
    ch = getchar();
	
    while(ch = getchar()) 
    {
        if(ch == '\n') 
	{
	    str[len] = '\0';
	    break;
	}
	else
	{
	    str[len++] = ch; 
	}
    }
}


// Function to take word as input from user.
void take_word_input(char *str)  
{
    scanf("%s" , str);
}


// Main function.
int main()
{
    // Creating Root Node for Trie.
    struct TrieNode *root = returnTrie_Object('\0');
    
    // General Instructions.
    printf("\nWelcome to Trie Dictionary , hope you have a Good time :) \n\n");
    printf("Enter 1. to insert a word. \nEnter 2. to search a word. \nEnter 3. to delete a word. \n");
    printf("Enter 4. to auto-complete a word.\nEnter 5. to print meaning of a word.\n");
    printf("Enter 6. to print all words with their meaning. \nEnter 7. to activate Spell Checker. \n");
    printf("Enter 8. to Exit \n");
    
    
    while(1)
    {
        printf("\nEnter your choice of operation : \n");
        int choice;
        scanf("%d" , &choice);

	// switch case.
        switch(choice)
        {
	    // case 1 to insert word with its meaning.
            case 1:
            {
                char word[256];
                char meaning[1000];
                printf("Enter a word to insert. \n");
                take_word_input(word);
            
                printf("Enter its meaning. \n");
                take_meaning_input(meaning);
                    
                insert_word(root , word , 0 , meaning);
                break;
            }
                
	    // case 2 to search a word.
            case 2:
            {
                char word[256];
                printf("Enter a word to search. \n");
                take_word_input(word);
                    
                bool find = search_word(root , word , 0); 
                if(find == true)
                {
                    printf("'%s' is present in your Trie Dictionary. \n" , word);
                }
                else
                {
                    printf("There is no such word like '%s' in your Trie Dictionary. \n" , word);
                }
                break;
            }
                
	    // case 3 to delete a word.
            case 3:
            {
                char word[256];
                printf("Enter a word to delete. \n");
                take_word_input(word);
                    
                delete_word(root , word , 0); 
                break;
            }
                
	    // case 4 to print suggestions for auto-completing a word.
            case 4:
            {
                char word[256];
                printf("Enter a word to auto-complete. \n");
                take_word_input(word);
                    
                auto_complete(root , word); 
                break;
            }
                
	    // case 5 to print meaning of a word.
            case 5:
            {
                char word[256];
                printf("Enter a word whose meaning to find. \n");
                take_word_input(word);
                    
                print_meaning(root , word , 0); 
                break;
            }

            // case 6 to print all words with meaning.    
            case 6:
            {
                get_trie(root);
                break;
            }
            
	    // case 7 to auto-correct a word.
            case 7:
            {
                char word[256];
                printf("Enter any word to spell it correct. \n");
                take_word_input(word);
                    
                refine_incorrect(root , word , 0); 
                break;
            }
                
	    // case 8 to exit.
            case 8:
            {
                printf("Exiting , Thankyou for being here !! \n");

		// goto statement to go out of while loop.
                goto EndWhile;
            }
                
	    // default case to exit.
            default:
            {
                printf("Exiting , Thankyou for being here !! \n");

		// goto statement to go out of while loop.
                goto EndWhile;
            }
        }
    }
    

    EndWhile: ;
        
    return 0;
}

