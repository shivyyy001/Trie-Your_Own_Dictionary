# Library For Trie Data Structure - Your Own Dictionary.
### Description :
##### What is Trie ? 
Trie is a type of search tree whose nodes stores the letters of alphabet generally , or it can contain any of the 256 characters (Except NULL '\0' character as it behaves as the Root Node of Trie). By using tries , searching complexities can be reduced. So basically it works like a dictionary storing words with its meaning in it which can be inserted , searched and deleted. It also helps in auto-complete and pattern matching algorithms.

###### This is how it looks like and should be visualized ->
<pre>
                                                                  \0
                                                                /    \
                                                               a      b
                                                              / \    / \  
                                                            (<b>n</b>)  r (<b>e</b>)  a
                                                            / \   \      \
                                                          (<b>d</b>) (<b>s</b>) (<b>e</b>)    (<b>t</b>)             
                                                           
'\0' (NULL character) is the Root Node of Trie . The letters which are marked in () represents that a word ends at that Node . So
there are words like an, and, ans, are, be, bat present in this above trie.
</pre>

#### Real Life Applications of Tries is as follows :
- Auto-Complete
- Pattern Matching
- Text Search
- Browser History
- Spell Checkers or Auto-Correct

#### Note !! :
1. This Trie can contain a word with its meaning . The word should be a string (character array in C) , and can be of any length. But the meaning should be of length at max 1000 as according to this trie's implementation. We can also resize the max meaning length to be more or less than 1000 by changing the size during its initialization in returnTrie_Object() function.
2. The word that needs to be inserted can contain any character except NULL character ('\0') as NULL character behaves as the root node of the trie. So basically a word can be made of 255 different characters generally. NULL character can be inserted as the last character of the word , but it should not be inserted in between the word.

#### Why Tries over HashMaps for dictionary implementation ?
- Lets say the user needs to store thousands of words starting with 'a' . HashMaps has to store all the thousand words in it starting with 'a' , whereas Tries has to store only one Node for character 'a' , thus space gets optimised.
- Pattern matching and Auto-complete are amazing features of Tries . If these features are aimed to be implemented in HashMaps , then the runtime complexities will be more in HashMaps as we then need to traverse Full HashMap and the words in it as well.
- Tries can provide an alphabetical ordering of the entries by key ,meaning they give out data (words) in sorted manner when printed, but Unordered Maps gives out data in unsorted manner and Ordered Maps has more runtime complexity than Tries to keep the data sorted inside it.
___

### About Idea :
- The main source of inspiration was Search Engines. 
- There was keenness to know how auto-complete , or pattern maching in search engines actually work behind the scene.
- The idea was to implement something productive for users which helps them and also makes them keen to know more about it.
- To help user in learning new words with their meanings while playing around with such a dictionary.
___
### Project Goals : 
- The ultimate goal was to implement a dictionary that has key functions like :
     - Adding a word with its meaning.
     - Searching a word.
     - Deleting a word , if needed.
     - Auto Complete feature implementation , which works through pattern matching.
     - Printing the meaning of a word , after searching.
     - Printing all words with their meaning , present in the dictionary.
- Making it as a library for user , as there is no inbuilt library for Tries data structure in any of the programming languages.
- Performing every operation in efficient runtime complexity and efficient space complexity.

___

### Design and Specifications :
Created 2 files , one is Trie.h file which contains Trie data structure implementation , and the other is Main_Function.c file which contains the main function to use Trie.h file. <br>
Trie.h file was included in Main_Function.c file like this : <b> ``` #include "Trie.h" ``` </b> . After including it any function implemented for trie in Trie.h file can be used in Main_Function.c file. <b><i> That's how Trie.h file works as a library file for us :smiley: </i></b>.

#### About Main_Function.c file and its working :
The Main_Function.c file contains the main function for the program which will let the user use the Trie.h file's functionality according to his need as the Trie.h file is included in Main_Function file as : ``` #include "Trie.h" ```.<br>
So , when user will run the Main_Function.c file , the output screen will show different choice of functions to perform , like :
- Add a word with its meaning in Trie Dictionary.
- Search a word.
- Delete a word.
- Print meaning of a word.
- Auto-complete a prefix word with different choices of words present in Trie Dictionary.
- Print all words with their meaning that are currently present in Trie Dictionary.
- Exit.

Until user chooses Exit option , the program will keep running and keep performing the Operations that user ask it to by providing input.


#### About Trie.h file and its working :
Trie.h file contains all the Functions of Trie data structure that are implemented . These functions include Adding a word with its meaning , Searching a word , Deleting a word , Printing the meaning of a word , Auto-Completing a prefix word with different choices of words present in Trie , Printing all word with their meaning that are currently present in Trie. 

##### Details/Specifications of Trie.h file :

- <i>The main part of Trie.h file is <b> ``` struct TrieNode ``` </b>, which is a structure for nodes of our Trie . It contains data of that node , children of that node , bool is_Terminal to check if a word ends at that node or not and string meaning to store meaning of the word which will be inserted.</i>
- <i>The <b>```Child_Size```</b> is defined as 256 , which means every node can have at max 256 Child Nodes. NULL character can only be included if its the last character of the given word , else every node can have at max 255 Child Nodes except the NULL character node.</i>
- <i>Child_Size is defined as 256 using : <b>``` #define Child_Size 256 ```</b>. So whereever we use Child_Size variable it means 256. </i>
##### Below is the Detailed Explanation of each function in Trie.h file :
| Function  | Description | Function name in Trie.h file | Return Type |
|   :---:   |    :---:    |         :---:         |     :--:    |
|Return Trie Node Object|This function takes a parameter as character val , creates an object of TrieNode structure , sets its data to val , sets its is_Terminal to false , initializes the meaning string for that object, makes every child of that object as NULL initially , and hence returns the object to main function for initialization of root of our Trie.|returnTrie_Object()|struct TrieNode * |
|Insert Word with its meaning|This function takes 4 parameters as root of our Trie , string word to be inserted , pos variable to traverse word and string meaning which is to be inserted corresponding to the word . This function inserts the word with its meaning in our Trie if its not present but if its present then this function is used to change the meaning of that word to latest meaning that we provided. |insert_word()|void|
|Search a word|This function takes 3 parameters as root of our Trie , string word to be searched and pos variable to traverse word . This function returns true if the word is present in our Trie dictionary else it returns false.|search_word()|bool|
|Delete a word|This function takes 3 parameters as root of our Trie , string word to be deleted and pos variable to traverse word . This function is used to delete a word from our trie dictionary if it is present. It deletes only those characters of a word which have no child and where another word does not ends , so that deletion should not affect other words. It simply returns if the word is not present in our trie.|delete_word()|void|
|Print meaning of a word|This function takes 3 parameters as root of our Trie , string word to print its meaning and pos variable to traverse word . This function is used print meaning of the word if the word is present else this function just returns saying that the word is not present.|print_meaning()|void|
|Helper function to print all words with their meaning|This function takes 1 parameter as root of our Trie . This function creates a temporary string word to store current word while printing all words . This function calls print_all_words_with_meaning() with root , string word and current position as parameters to print all words with their meaning if any Trie dictionary is not empty . If there are no words yet it just returns saying that No words are present yet.|get_trie()|void|
|Print all words with their meaning|This function takes 3 parameters as root of our Trie , string word to store current word and pos variable to traverse current word . This function prints all words with their meaning that are currently present in Trie dictionary.|print_all_words_with_meaning()|void|
|Helper function to perform auto-complete|This function takes 2 parameters as root of our Trie and prefix string word to auto-complete . This function first searches if the given prefix word is present in our trie or not by calling search_the_prefix_word() function with parameters as root of our Trie , prefix string word and pos variable to traverse the word. If search_the_prefix_word() function returns a TrieNode means the prefix word is present in Trie and it has returned TrieNode of last character of prefix word , hence this helper function then calls print_for_autocomplete() function with parameters as that TrieNode returned by search_the_prefix_word() function as root to auto-complete it , prefix string word to auto-complete, temporary string to store current word , and pos variable to traverse current word to print all the words that start with prefix word to behave as an auto-complete function . Else if the search_the_prefix_word() function returns NULL , means no word is present in our trie which starts with given prefix word , hence then this helper function just returns saying no words found to complete the given prefix word.|auto_complete()|void|
|Search a prefix word for auto_complete function|This function takes 3 parameters as root of our Trie , prefix string word to search and pos variable to traverse word . This function returns TrieNode of last character of prefix word if prefix word is present in Trie as itself or as prefix of another words else it returns NULL.|search_the_prefix_word()|struct TrieNode * |
|Print function to print the auto-completed words for a prefix|This function 4 parameters as TrieNode of last character of prefix word returned by search_the_prefix_word() function as root , prefix string word , temporary string to store current completed word till now , fill variable to fill temporary string . This function prints all the words that complete the given prefix string . So this function gives our Trie an auto-complete a prefix functionality.|print_for_autocomplete()|void|


___

### Steps to Compile and Run on Online IDE or any personal IDE :
###### (like GDB online debugger and compiler or CodeBlocks)
- Download and extract both files to save it in your local system.
- In case of personal IDE -> open both files in your personal IDE , Compile both files , and Run the Main_Function.c file to execute.
- In case of Online IDE   -> upload both files on Online IDE , Compile both files , and Run the Main_Function.c file to execute.

### Steps to Compile and Run in VI Editor in Linux :
###### For Trie.h file ->
- Create a file named Trie.h in your Linux Machine using the following command :<br>
``` vim Trie.h ```.
- Go to insert mode in your file by pressing ``` i ``` and then copy the content of Trie.h file from this repository to that file which you have created.
- Save your file using the following command :<br>
``` Press Esc key ``` to go to Command mode. Then type ``` :wq ``` and ``` press Enter key ``` to save the file.
- Compile your file using command : ``` gcc Trie.h ```.

###### For Main_Function.c file ->
- Next Create a file named Main_Function.c in your Linux Machine using the following command :<br>
``` vim Main_Function.c ```.
- Go to insert mode in your file by pressing ``` i ``` and then copy the content of Main_Function.c file from this repository to that file which you have created.
- Save your file using the following command :<br>
``` Press Esc key ``` to go to Command mode. Then type ``` :wq ``` and ``` press Enter key ``` to save the file.
- Compile your file using command : ``` gcc Main_Function.c ```.
- Now there will be a output file created named "a.out" which is a compiled executable file. So to see the results of execution use command :
``` ./a.out ``` to open a.out file.

