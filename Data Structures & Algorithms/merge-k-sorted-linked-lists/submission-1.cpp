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

         void convertLL2arr(vector<ListNode*> &lists,vector<int> &array){
            
            for(int i =0 ; i<lists.size();i++){
                ListNode *temp = lists[i];

                while(temp != nullptr){
                    array.push_back(temp->val);
                    temp = temp->next;
                }
            }
        }
        

        ListNode *convertarr2LL(vector<int> &array){

            ListNode *dummy = new ListNode(-1);
            ListNode *temp = dummy;

            for(int i =0 ;i<array.size();i++){
                ListNode * node = new ListNode(array[i]);
                temp->next = node;
                temp = temp->next;
            }
            return dummy->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>array; //empty array
        
        convertLL2arr(lists,array);
        sort(array.begin(),array.end());
        return convertarr2LL(array);

    }
};
