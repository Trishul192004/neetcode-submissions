/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *left = dummy;
        ListNode *right = head;
        

        //move right n steps ahead as left steps 1 step behind to point to node to be deleted
        for(int i=0;i<n;i++){
            right = right->next;

        }

        while(right != nullptr){
            left = left->next;
            right = right->next;

        }


        ListNode * deleteNode = left->next;
        left->next = left->next->next;

        delete deleteNode;
        return dummy->next;

        }
    
    };

