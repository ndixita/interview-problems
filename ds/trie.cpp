#include <iostream>
#include <vector>

using namespace std;

const int ALPHASIZE = 26;

struct TrieNode {
    bool isEndOfWord;
    TrieNode* children[ALPHASIZE];
};

TrieNode* getNewNode() {
    TrieNode* p = new TrieNode;
    p->isEndOfWord = false;
    for(int i = 0; i < ALPHASIZE; i++) {
        p->children[i] = NULL;
    }

    return p;
}

void insert(TrieNode* root, string key) {
    TrieNode* current = root;
    for(int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if(!current->children[index]) current->children[index] = getNewNode();
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(TrieNode* root, string key) {
    TrieNode* current = root;
    for(int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if(!current->children[index]) return false;
        current = current->children[index];
    }

    return current && current->isEndOfWord;
}

int main() {
    string temp, toSearch;
    cout << "Enter the words you want to insert" << endl;
    TrieNode* root = getNewNode();
    while((cin >> temp)) {
        int n;
        insert(root, temp);
        cout << "Press 0 to break" << endl;
        cin >> n;
        if(n == 0) break;
    }

    cout << "Enter the word to be searched" << endl;
    cin >> toSearch;
    
    search(root, toSearch) ? cout << "Found! :-D" << endl : cout << "Not Found :-(" << endl;

    return 0;
}