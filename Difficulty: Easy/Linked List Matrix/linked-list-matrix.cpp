//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        // code Here
        Node* head = new Node(mat[0][0]);

    // Array to store pointers to the first nodes of each row
    vector<Node*> rowHead(n);

    // Initialize the first row
    rowHead[0] = head;

    // Create the first row of the linked list
    Node* temp = head;
    for (int j = 1; j < n; ++j) {
        temp->right = new Node(mat[0][j]);
        temp = temp->right;
    }

    // Create the rest of the rows
    for (int i = 1; i < n; ++i) {
        rowHead[i] = new Node(mat[i][0]);
        temp = rowHead[i];

        for (int j = 1; j < n; ++j) {
            temp->right = new Node(mat[i][j]);
            temp = temp->right;
        }
    }

    // Link the rows vertically (down pointers)
    for (int i = 0; i < n - 1; ++i) {
        Node* currRow = rowHead[i];
        Node* nextRow = rowHead[i + 1];

        while (currRow != nullptr && nextRow != nullptr) {
            currRow->down = nextRow;
            currRow = currRow->right;
            nextRow = nextRow->right;
        }
    }

    return head;  
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends