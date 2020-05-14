#include <bits/stdc++.h> 

using namespace std; 

struct Trie { 
	bool isEndOfWord; 
	unordered_map<char, Trie*> map; 
	string meaning; 
}; 

// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
	Trie* node = new Trie; 
	node->isEndOfWord = false; 
	return node; 
} 


void insert(Trie*& root, const string& str, const string& meaning) 
{ 
	if (root == NULL){
        root = getNewTrieNode(); 
    } 
		
	Trie* temp = root; 
	for (int i = 0; i < str.length(); i++) 
    { 
		char x = str[i]; 
		if (temp->map.find(x) == temp->map.end()){
            temp->map[x] = getNewTrieNode();
        } 
		temp = temp->map[x]; 
	} 
	temp->isEndOfWord = true; 
	temp->meaning = meaning; 
} 


string getMeaning(Trie* root, const string& word) 
{ 

	if (root == NULL) 
		return ""; 

	Trie* temp = root; 

	for (int i = 0; i < word.length(); i++) { 
		temp = temp->map[word[i]]; 
		if (temp == NULL) 
			return ""; 
	} 
	if (temp->isEndOfWord) 
		return temp->meaning; 
	return ""; 
} 

int main() 
{ 
	Trie* root = NULL; 

	// Build the dictionary 
	insert(root, "language", "the method of human communication"); 
	
    insert(root, "computer", "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical\ 
    operations automatically via computer programming"); 
	
    insert(root, "map", "a diagrammatic representation of an area"); 
	insert(root, "book", "a written or printed work consisting of pages glued or sewn together along one side and bound in covers."); 
	insert(root, "science", "the intellectual and practical activity encompassing the systematic study \ 
of the structure and behaviour of the physical and natural world through observation and experiment."); 

	string str = "science"; 
	cout << getMeaning(root, str); 

	return 0; 
} 


