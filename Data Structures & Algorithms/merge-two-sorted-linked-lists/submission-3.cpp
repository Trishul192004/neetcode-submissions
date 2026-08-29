/*

class Solution {
public:

    vector<int> convertlist2array(ListNode* list) {

        vector<int> arr;

        ListNode* temp = list;

        while(temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        return arr;
    }


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Convert list1 to array
        vector<int> arr1 = convertlist2array(list1);

        // Convert list2 to array
        vector<int> arr2 = convertlist2array(list2);


        // Put both arrays into arr3
        vector<int> arr3;

        for(int x : arr1) {
            arr3.push_back(x);
        }

        for(int x : arr2) {
            arr3.push_back(x);
        }


        // Sort arr3
        sort(arr3.begin(), arr3.end());


        // Convert arr3 back to linked list
        ListNode* dummy = new ListNode(0);

        ListNode* temp = dummy;

        for(int x : arr3) {

            temp->next = new ListNode(x);

            temp = temp->next;
        }


        return dummy->next;
    }
};

*/

class Solution{
    public:
     ListNode *mergeTwoLists(ListNode *list1,ListNode *list2){
            ListNode *dummy = new ListNode(0);
            ListNode *temp = dummy;
            
            while(list1 != nullptr && list2 != nullptr){
                if(list1->val <= list2->val){
                    temp->next = list1;
                    list1  = list1 ->next;
                }
                else{
                    temp->next = list2;
                    list2= list2->next;
                }
                temp = temp->next;
            }
            //if list1 still has nodes
            if(list1 != nullptr){
                temp->next = list1;
            }

            //if list2 still has nodes
            if(list2 != nullptr){
                temp->next = list2;
            }

            return dummy->next;
     
     }
};


