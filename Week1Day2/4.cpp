/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* newHead = NULL;
    
    void  swap(ListNode * f, ListNode * s){
        if(s != NULL){
            ListNode * t = s->next;
            s->next = f;
            swap(s, t);
        }else{
            newHead = f;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        swap(NULL, head);  
        return newHead;
    }
};