//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    Node* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                          int& preorderIndex, int inorderStart, int inorderEnd, 
                          unordered_map<int, int>& inorderMap) {
        if (inorderStart > inorderEnd) return NULL;
    
        // Get the root value from preorder traversal
        int rootVal = preorder[preorderIndex++];
        Node* root = new Node(rootVal);
    
        // Get the index of root value in inorder traversal
        int rootIndex = inorderMap[rootVal];
    
        // Recursively build left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, preorderIndex, inorderStart, rootIndex - 1, inorderMap);
        root->right = buildTreeHelper(preorder, inorder, preorderIndex, rootIndex + 1, inorderEnd, inorderMap);
    
        return root;
}
    
    void postorderTraversal(Node* root, vector<int>& result) {
        if (!root) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->data);
}
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
         unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i; // Store index for quick lookup
        }
        int preorderIndex = 0;
        return buildTreeHelper(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
    }
    
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends