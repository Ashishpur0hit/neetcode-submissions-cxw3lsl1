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
    unordered_map<int,Node*>map;

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* n = new Node();
        n->val = node->val;
        map[n->val]=n;

        for(auto x : node->neighbors)
        {
            if(map.count(x->val)) n->neighbors.push_back(map[x->val]);
            else 
            {
                Node *temp = cloneGraph(x);
                n->neighbors.push_back(temp);
            }
        }
        return n;

    }
};
