#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* head = nullptr;
    if (l1->value <= l2->value) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    
    ListNode* current = head;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->value <= l2->value) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;  // Move to the next node in the merged list
    }

    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return head;  // Return the head of the merged list
}

ListNode* createLinkedList(int n) {
    if (n <= 0) return nullptr;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter the values of the nodes in sorted order: " << endl;
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
    cout << "Enter the number of nodes in the first sorted linked list: ";
    cin >> n1;
    ListNode* l1 = createLinkedList(n1);

    cout << "Enter the number of nodes in the second sorted linked list: ";
    cin >> n2;
    ListNode* l2 = createLinkedList(n2);

    ListNode* mergedList = mergeTwoLists(l1, l2);

    cout << "Merged linked list: ";
    printList(mergedList);

    return 0;
}
