```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);
        visited[node] = new Node(node->val);

        while (!q.empty()) {
            auto n = q.front();
            q.pop();

            for (auto& neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution solution;
    Node* clone = solution.cloneGraph(node1);

    cout << "Cloned graph node value: " << clone->val << endl;

    return 0;
}
```