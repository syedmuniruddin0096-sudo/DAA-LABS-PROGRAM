#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

// Compare function for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Print Huffman Codes
void printCodes(Node* root, string str) {
    if (!root)
        return;

    // If leaf node
    if (root->data != '$')
        cout << root->data << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};
    int n = 4;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create nodes and push into queue
    for (int i = 0; i < n; i++) {
        pq.push(new Node(arr[i], freq[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print codes
    printCodes(pq.top(), "");

    return 0;
}
