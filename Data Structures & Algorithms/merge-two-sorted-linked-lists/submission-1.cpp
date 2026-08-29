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