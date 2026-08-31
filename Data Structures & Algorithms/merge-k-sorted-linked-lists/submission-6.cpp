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
/* BRUTE FORCE CONVERSION ARR LL MERGING//

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
*/


class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;


        // Put first node of every list into heap
        for(int i = 0; i < lists.size(); i++) {

            if(lists[i] != nullptr) {

                pq.push({
                    lists[i]->val,
                    lists[i]
                });
            }
        }


        // Dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;


        while(!pq.empty()) {

            // Get smallest node
            auto it = pq.top();
            pq.pop();


            // Add smallest node to answer
            temp->next = it.second;
            temp = temp->next;


            // Add next node from the same list
            if(it.second->next != nullptr) {

                pq.push({
                    it.second->next->val,
                    it.second->next
                });
            }
        }


        return dummy->next;
    }
};






