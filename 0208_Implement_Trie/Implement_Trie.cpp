using namespace std;
#include <string>
#include <unordered_map>

class TrieNode {
public:
	TrieNode* children[26];
	bool isEndOfWord;

	TrieNode() {
		for (int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
		isEndOfWord = false;
	}

};

class Trie {
private:
	TrieNode* root;

public:
    Trie() {
    	root = new TrieNode();
    }

	void insert(string word) {
		TrieNode* curr = root;
		for (char c: word) {
			int index = c - 'a';
			if (!curr->children[index]) {
				curr->children[index] = new TrieNode();
			}
			curr = curr->children[index];
		}
		curr->isEndOfWord = true;
	}

	bool search(string word) {
		TrieNode* curr = root;
		for (char c: word) {
			int index = c - 'a';
			if (!curr->children[index]) return false;
			curr = curr->children[index];
		}
		return (curr->isEndOfWord && curr);
	}

	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (char c: prefix) {
			int index = c - 'a';
			if (!curr->children[index]) return false;
			curr = curr->children[index];
		}
		return (curr != nullptr);
	}
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
