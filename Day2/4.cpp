#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
    public:

        void print(ListNode * head){
            ListNode * it = head;
            while(it->next != NULL){
                cout << it->val << " ";
                it = it->next;
            }
            if(it != NULL){
             cout << it->val << " ";
            }
            cout << endl;
        }

        ListNode * add(ListNode * head, int x){
            if(head == NULL){
                head = new ListNode(x);
            }
            else {
                ListNode * it = head;
                while(it->next != NULL){
                    it = it->next;
                }
                it->next = new ListNode(x);
            }
            return head;
        }

        ListNode* deleteDuplicates(ListNode* it, ListNode * head) {
            if(it == NULL || it->next == NULL) return head;
            
            if(it->val == it->next->val){
                it->next = it->next->next;
            }else{
                it = it->next;
            }

            return deleteDuplicates(it, head);
        }
};

int main(){

    Solution s;
    ListNode * head = NULL;

    int a[] = {1, 1, 1, 2,2,2};

    for(int i = 0; i < 6; ++i){
        head = s.add(head, a[i]);
    }

    s.print(head);
    s.deleteDuplicates(head, head);
    s.print(head);

    return 0;
}