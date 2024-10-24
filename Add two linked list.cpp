#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);  // Dummy node to store result
    ListNode* current = dummy;          // Pointer to build the result list
    int carry = 0;                      // Initialize carry to 0

    // Traverse both lists
    while (l1 != NULL || l2 != NULL || carry) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        // Calculate sum and carry
        int sum = val1 + val2 + carry;
        carry = sum / 10;

        // Create a new node with the sum's remainder (the current digit)
        current->next = new ListNode(sum % 10);
        current = current->next;

        // Move to the next nodes in l1 and l2 if available
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy->next;  // The next node of dummy contains the result
}

// Function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val;
        if (node->next != NULL) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

// Function to create a linked list from user input
ListNode* createList() {
    int num;
    cout << "Enter digits of the number in reverse order (enter -1 to stop):" << endl;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    while (true) {
        cin >> num;
        if (num == -1) break;  // Stop taking input when user enters -1

        ListNode* newNode = new ListNode(num);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

int main() {
    // Creating two linked lists from user input
    cout << "Input for first number:" << endl;
    ListNode* l1 = createList();

    cout << "Input for second number:" << endl;
    ListNode* l2 = createList();

    // Adding the two linked lists
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Resultant Linked List: ";
    printList(result);

    return 0;
}
