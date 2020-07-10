// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        
        Node* curr = head;
        
        while (curr != NULL){
            if (curr->child != NULL)
                merge(curr);
            curr = curr->next;
        }
        
        return head;
    }
    
    void merge(Node* node){
        Node* curr = node->child;
        
        while(curr->next != NULL)
            curr = curr->next;
        
        if (node->next != NULL){
            node->next->prev = curr;
            curr->next = node->next;
        }
        node->child->prev = node;
        node->next = node->child;
        node->child = NULL;
    }
    
//     Node* flatten(Node* head) {
//         if (head == NULL) return NULL;
        
//         Node* curr = head;
        
//         while (curr != NULL) {
//             Node* next = curr->next;
//             if (curr->child != NULL) {
//                flattenUtil(curr);
//                 curr->child = NULL;
//             }
//             curr = next;
//         }
//         return head;
//     }
    
//     void flattenUtil(Node* node){
//         Node* temp = node->next;
//         Node* curr = node->child;
        
//         node->next = curr;
//         curr->prev = node;
        
//         while(curr->next != NULL) {
//             Node* tNext = curr->next;
//             if (curr->child != NULL) {
//                 flattenUtil(curr);
//                 curr->child = NULL;
//             }
//             curr = tNext;
//         }
        
//         if (curr->next == NULL) {
//             if (curr->child != NULL) {
//                 flattenUtil(curr);
//                 curr->child = NULL;
//             }
//         }
        
//         curr->next = temp;
//         if (temp != NULL)
//             temp->prev = curr;
//     }
};