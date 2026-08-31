
class LRUCache { 
public: 

    struct Node { 
        int key; 
        int value; 
        Node *prev; 
        Node *next; 

        Node(int k, int v) { 
            key = k; 
            value = v; 
            prev = nullptr; 
            next = nullptr; 
        }   
    }; 

    int capacity; 

    Node *head, *tail; 
    unordered_map<int, Node*> mpp; 

    LRUCache(int capacity) { 
        this->capacity = capacity; 

        // dummy nodes
        head = new Node(-1, -1); 
        tail = new Node(-1, -1); 

        head->next = tail; 
        tail->prev = head; 
    } 


    void insertAfterHead(Node *node) { 
        Node *currAfterHead = head->next; 

        head->next = node; 
        node->prev = head; 

        node->next = currAfterHead; 
        currAfterHead->prev = node; 
    } 


    void deleteNode(Node *node) { 
        Node *prevNode = node->prev; 
        Node *nextNode = node->next; 

        prevNode->next = nextNode; 
        nextNode->prev = prevNode; 
    } 


    int get(int key) { 

        if (mpp.find(key) == mpp.end()) { 
            return -1; 
        } 
        else { 
            Node *node = mpp[key]; 

            // move this node to front
            deleteNode(node); 
            insertAfterHead(node); 

            return node->value; 
        } 
    } 


    void put(int key, int value) { 

        // key exists
        if (mpp.find(key) != mpp.end()) { 

            Node *node = mpp[key]; 

            // update the value
            node->value = value; 

            // move to front
            deleteNode(node); 
            insertAfterHead(node); 
        } 

        else { 

            // cache is full
            if (mpp.size() == capacity) { 

                Node *lru = tail->prev; 

                mpp.erase(lru->key); // mpp se egrsu
                deleteNode(lru);     // list se bhi
                delete lru;          // free lru
            } 

            // create new node
            Node *node = new Node(key, value); 

            // put in mpp
            mpp[key] = node; 

            // put in front
            insertAfterHead(node); 
        } 
    } 
};
