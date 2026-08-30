/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution { 
public: 
    Node* copyRandomList(Node* head) { 
        if (head == nullptr) return nullptr;

        Node *temp = head; 
        unordered_map<Node*, Node*> mpp; 

        // Step 1: Create a original-to-copy node mapping
        while (temp != NULL) { 
            Node* newnode = new Node(temp->val); 
            mpp[temp] = newnode; 
            temp = temp->next; 
        } 

        temp = head; 

        // Step 2: Connect next and random pointers for copied nodes
        while (temp != NULL) { 
            Node* copynode = mpp[temp]; 
            copynode->next = mpp[temp->next]; 
            copynode->random = mpp[temp->random]; 
            temp = temp->next; // <-- Missing line that caused the TLE
        } 

        return mpp[head]; 
    } 
};
