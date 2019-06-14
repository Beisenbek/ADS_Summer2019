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

        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL) return head;
            if(head->next == NULL) return head;
            if(head->val == head->next->val){
                head = head->next;
                return deleteDuplicates(head);
            }
            return deleteDuplicates(head->next);
        }
};

int main(){

    Solution s;
    ListNode * head = NULL;

    int a[] = {1, 1, 2, 3, 4, 5, 5};

    for(int i = 0; i < 7; ++i){
        head = s.add(head, a[i]);
    }

    s.print(head);
    s.deleteDuplicates(head);
    s.print(head);

    return 0;
}