#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

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


class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return nullptr;
		vector<Node*> nodes(101, nullptr);
		queue<Node*> q;
		q.push(node);
		nodes[node->val] = new Node(node->val);
		while(!q.empty()) {
			Node* curr = q.front();
			q.pop();
			for (Node* neighbor: curr->neighbors) {
				if (!nodes[neighbor->val]) {
					nodes[neighbor->val] = new Node(neighbor->val);
					q.push(neighbor);
				}
				nodes[curr->val]->neighbors.push_back(nodes[neighbor->val]);
			}
		}
		return nodes[node->val];
	}
};
