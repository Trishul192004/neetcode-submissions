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


/* MY STACK APPRCH..
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

*/

// optimal

class Solution {
public:

    void reorderList(ListNode* head) {

        // If list has 0 or 1 node, nothing to do
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // --------------------------------
        // STEP 1: Find the middle
        // --------------------------------

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the middle
        // Example:
        // 1 → 2 → 3 → 4 → 5
        //         ↑
        //       slow


        // --------------------------------
        // STEP 2: Separate the two halves
        // --------------------------------

        ListNode* second = slow->next;

        // Cut the list
        slow->next = nullptr;

        // Now:
        // first:  1 → 2 → 3 → NULL
        // second: 4 → 5 → NULL


        // --------------------------------
        // STEP 3: Reverse second half
        // --------------------------------

        ListNode* prev = nullptr;

        while (second != nullptr) {

            ListNode* next = second->next;

            second->next = prev;

            prev = second;

            second = next;
        }

        // prev is now the beginning of reversed second half
        // 5 → 4 → NULL

        second = prev;


        // --------------------------------
        // STEP 4: Merge the two halves
        // --------------------------------

        ListNode* first = head;

        while (second != nullptr) {

            // Save next nodes
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            // Connect first node to second node
            first->next = second;

            // Connect second node to next first node
            second->next = firstNext;

            // Move both pointers
            first = firstNext;
            second = secondNext;
        }
    }
};
