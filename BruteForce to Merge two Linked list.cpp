#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    vector<int> values;  

    ListNode* current = l1;
    while (current != nullptr) {
        values.push_back(current->value);
        current = current->next;
    }

    current = l2;
    while (current != nullptr) {
        values.push_back(current->value);
        current = current->next;
    }

    sort(values.begin(), values.end());

    ListNode* dummy = new ListNode(-1);  // Dummy node to start the new list
    ListNode* tail = dummy;

    for (int val : values) {
        tail->next = new ListNode(val);  // Create new node for each value
        tail = tail->next;
    }

    return dummy->next;  // Return the head of the new merged list
}

ListNode* createLinkedList(int n) {
    if (n <= 0) return nullptr;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter the values of the nodes: " << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Node " << i + 1 << ": ";
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// Main function
int main() {
    int n1, n2;
    cout << "Enter the number of nodes in the first linked list: ";
    cin >> n1;
    ListNode* l1 = createLinkedList(n1);

    cout << "Enter the number of nodes in the second linked list: ";
    cin >> n2;
    ListNode* l2 = createLinkedList(n2);

    ListNode* mergedList = mergeTwoLists(l1, l2);

    cout << "Merged linked list : ";
    printList(mergedList);

    return 0;
}
