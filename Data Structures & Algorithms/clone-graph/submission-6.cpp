/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        // 1. Empty graph
        if(node == NULL) {
            return NULL;
        }

        // 2. Already cloned?
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }

        // 3. Create clone
        Node* clone = new Node(node->val);

        // 4. Store original -> clone
        mp[node] = clone;

        // 5. Clone neighbours
        for(auto neighbour : node->neighbors) {

            clone->neighbors.push_back(
                cloneGraph(neighbour)
            );
        }

        // 6. Return clone
        return clone;
    }
};