#include <iostream>

using namespace std;

class TrieNode {
public:
    char data; //data is stored in each node as char 
    bool isEnd; //set to true to identify that it's a word
    TrieNode* links[26]; // to maintain the link for next letter
    TrieNode(char c) {
        this->data = c;
        this->isEnd = false;
        for(int i = 0; i < 26; i++) {
            this->links[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    
    Trie() {
        root = new TrieNode('0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root, *q = NULL;
        for(char c : word) {
            if(p->links[c-'a'] == NULL) {
                q = new TrieNode(c);
                p->links[c-'a'] = q;
            } else {
                q = p->links[c-'a'];
            }
            p = q;
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        int i = 0;
        while(i < word.length()) {
            if(p->links[word.at(i)-'a'] == NULL)
                return false;
            p = p->links[word.at(i)-'a'];
            i++;
        } 
        if(p->isEnd == true)
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        int i = 0;
        while(i < prefix.length()) {
            if(p->links[prefix.at(i)-'a'] == NULL)
                return false;
            p = p->links[prefix.at(i)-'a'];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
	Trie* obj = new Trie();
	obj->insert("apple");	
	cout<<obj->search("apple")<<endl;
	cout<<obj->search("orange")<<endl;
	cout<<obj->startsWith("app")<<endl;

	return 0;
}
