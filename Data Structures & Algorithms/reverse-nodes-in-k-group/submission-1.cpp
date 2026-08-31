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

    ListNode* findkthNode(ListNode* temp, int k) {

        k -= 1;

        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }


    ListNode* reverseLL(ListNode* head) {

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {

            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevnode = NULL;

        while(temp != NULL) {

            // Find kth node
            ListNode* kthNode = findkthNode(temp, k);

            // If less than k nodes are left
            if(kthNode == NULL) {

                if(prevnode) {
                    prevnode->next = temp;
                }

                break;
            }


            // Store next group
            ListNode* nextnode = kthNode->next;

            // Cut current group
            kthNode->next = NULL;


            // Reverse current group
            reverseLL(temp);


            // If this is the first group
            if(temp == head) {
                head = kthNode;
            }

            // Otherwise connect previous group
            else {
                prevnode->next = kthNode;
            }


            // temp is now the last node of reversed group
            prevnode = temp;

            // Move to next group
            temp = nextnode;
        }

        return head;
    }
};

