// https://leetcode.com/problems/add-and-search-word-data-structure-design/

// Leetcode submitted code
// class WordDictionary {
//     struct TrieNode{
//         bool is_word = false;
//         unordered_map<char, TrieNode*> children;
//     };
//     TrieNode* root = NULL;
// public:
//     /** Initialize your data structure here. */
//     WordDictionary() {
//         TrieNode* temp = new TrieNode;
//         root = temp;
//     }
    
//     /** Adds a word into the data structure. */
//     void addWord(string word) {
//         auto curr = root;
//         for(auto s : word){
//             if (curr->children.find(s) == curr->children.end()){
//                 TrieNode* temp = new TrieNode;
//                 curr->children.insert({s, temp});
//             }
//             curr = curr->children[s];
//         }
//         curr->is_word = true;
//     }
    
//     /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//     bool search(string word) {
//         if (word.size() == 0) return false;
//         return searchUtil(word, root, 0);
//     }
// private:
//     bool searchUtil(string word, TrieNode* node, int index){
//         if (node == NULL) return false;
//         auto curr = node;
//         for(int i = index; i < word.size(); i++){
//             if (word[i] == '.'){
//                 if (curr->children.size() == 0) return false;
//                 bool res = false;
//                 unordered_map<char, TrieNode*>::iterator itr;
//                 for(itr = curr->children.begin(); itr != curr->children.end(); itr++){
//                     res = res || searchUtil(word, itr->second, i+1);
//                 }
//                 return res;
//             } else {
//                 if (curr->children.find(word[i]) == curr->children.end())
//                     return false;
//                 else
//                     curr = curr->children[word[i]];
//             }
//         }
//         return curr && curr->is_word;
//     }
// };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


// executable code in ide
#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode{
    bool is_word = false;
    unordered_map<char, TrieNode*> children;
};
TrieNode* root = NULL;

void wordDictionary() {
    TrieNode* temp = new TrieNode;
    root = temp;
}

void addWord(string word) {
    auto curr = root;
    for(auto s : word){
        if (curr->children.find(s) == curr->children.end()){
            TrieNode* temp = new TrieNode;
            curr->children.insert({s, temp});
        }
        curr = curr->children[s];
    }
    curr->is_word = true;
}

bool searchUtil(string word, TrieNode* node, int index){
    if (node == NULL) return false;

    auto curr = node;
    for(int i = index; i < word.size(); i++){
        if (word[i] == '.'){
            if (curr->children.size() == 0) return false;
            bool res = false;
            unordered_map<char, TrieNode*>::iterator itr;
            for(itr = curr->children.begin(); itr != curr->children.end(); itr++){
                res = res || searchUtil(word, itr->second, i+1);
            }
            return res;
        } else {
            if (curr->children.find(word[i]) == curr->children.end())
                return false;
            else
                curr = curr->children[word[i]];
        }
    }
    return curr && curr->is_word;
}

void search(string word) {
    if (word.size() == 0) return;
    bool res = searchUtil(word, root, 0);
    cout << word << " " << res << endl;
}

int main() {
    // "WordDictionary","addWord","addWord","addWord","search","search","search","search"
    // [],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]
    wordDictionary();
    addWord("bad");
    addWord("dad");
    addWord("mad");

    search("pad");
    search("bad");
    search(".ad");
    search("b..");

    return 0;
}