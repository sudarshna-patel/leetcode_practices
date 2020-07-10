// https://leetcode.com/problems/word-search-ii/

class Solution {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool is_word = false;
    };
    TrieNode* root = new TrieNode;
public:
    void insert(string key) {
        TrieNode* curr = root;
        for(auto s : key){
            if(curr->children.find(s) == curr->children.end()){
                TrieNode* temp = new TrieNode;
                curr->children.insert({s, temp});
            }
            curr = curr->children[s];
        }
        curr->is_word = true;
    }
    
    void findWords(vector<vector<char>>& board, int i, int j, TrieNode* root, string word, set<string>& result){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == ' ')
            return;
        
        if ( root->children.find(board[i][j]) == root->children.end())
            return;
        else {
            word = word + board[i][j];
            root = root->children[board[i][j]];
            
            if (root->is_word)
                result.insert(word);
            
            char c = board[i][j];
            board[i][j] = ' ';
            findWords(board, i+1, j, root, word, result);
            findWords(board, i-1, j, root, word, result);
            findWords(board, i, j+1, root, word, result);
            findWords(board, i, j-1, root, word, result);
            board[i][j] = c;        
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            insert(words[i]);
        
        set<string> result_set;
        for ( int i = 0; i < board.size(); i++ )
            for ( int j = 0; j < board[i].size(); j++ )
                findWords(board, i, j, root, "", result_set);
        
        vector<string> result;
        for(auto it : result_set)
            result.push_back(it);
        return result;  
    }
};