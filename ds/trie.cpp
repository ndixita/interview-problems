#include <iostream>
#include <vector>

using namespace std;

const int ALPHASIZE = 26;
struct TrieNode {
    bool isEndOfWord;
    TrieNode *children[ALPHASIZE];
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
    TrieNode *current = root;
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

    return current != NULL && current->isEndOfWord;
}

int main() {
    string keys[] = {"my", "name", "is", "dixita"};
    TrieNode *root = getNewNode();
    int N = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < N; i++) {
        insert(root, keys[i]);
    }

    search(root, "dixita") ? cout << "Yes" : cout << "No";
    return 0;
}
