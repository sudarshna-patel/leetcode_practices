// https://leetcode.com/problems/map-sum-pairs/

class MapSum {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int val=0;
    };
    TrieNode* root = new TrieNode;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        for(auto s : key){
            if(curr->children.find(s) == curr->children.end()){
                TrieNode* temp = new TrieNode;
                curr->children.insert({s, temp});
            }
            curr = curr->children[s];
        }
        curr->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        int res = 0;
        for(auto s : prefix){
            if(curr->children.find(s) == curr->children.end()){
                return 0;
            }
            curr = curr->children[s];
        }
        
        return sumUtil(curr);
    }
    
    int sumUtil(TrieNode* node){
        if (node == NULL) return 0;
        
        int sum = 0;
        unordered_map<char, TrieNode*>::iterator itr;
        for(itr = node->children.begin(); itr != node->children.end(); itr++){
            sum += sumUtil(node->children[itr->first]);
        }
        
        return sum + node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */