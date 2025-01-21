//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
  
   Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* getKthNode(Node* temp, int k) {
    while (temp != NULL && --k > 0) {
        temp = temp->next;
    }
    return temp;
}

Node* reverseKGroup(Node* head, int k) {
    if (head == NULL || k <= 1) return head; // Handle edge cases
    
    Node* dummy = new Node(0); // Dummy node to handle the head easily
    dummy->next = head;
    Node* prevLast = dummy;

    while (true) {
        Node* groupStart = prevLast->next;
        Node* groupEnd = getKthNode(groupStart, k);

        if (groupEnd == NULL) {
            // Reverse the remaining nodes if any
            prevLast->next = reverseLinkedList(groupStart);
            break; // No more groups to process
        }

        Node* nextGroupStart = groupEnd->next;
        groupEnd->next = NULL; // Temporarily break the group

        // Reverse the isolated group
        reverseLinkedList(groupStart);

        // Connect reversed group back to the main list
        prevLast->next = groupEnd;
        groupStart->next = nextGroupStart;

        // Move pointers for the next iteration
        prevLast = groupStart;
    }

    return dummy->next;
}

};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends