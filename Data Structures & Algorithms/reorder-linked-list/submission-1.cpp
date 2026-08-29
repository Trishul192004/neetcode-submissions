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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        if(head == nullptr || head->next == nullptr){
            return;
        }

        ListNode *temp = head;
        while(temp != nullptr){
            st.push(temp);
            temp = temp->next;
        }

        int n =st.size();
        temp = head;

        for(int i=0;i<n/2;i++){
            ListNode *last = st.top();
            st.pop();

            last->next = temp->next;
            temp->next = last;
            temp = last->next;
        }

        //ending list
        temp->next = nullptr;


    }
};
