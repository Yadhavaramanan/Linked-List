#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int value;              // Node value
    ListNode* next;         // Pointer to the next node

    ListNode(int val) : value(val), next(nullptr) {}
};

pair<bool, int> detectCycle(ListNode* head) {
    unordered_map<ListNode*, int> visited; 
    ListNode* current = head;
    int index = 0;

    while (current) {
        if (visited.find(current) != visited.end()) {
            int cycle_start_index = visited[current];
            return {true, index - cycle_start_index};  
        }
        visited[current] = index;
        current = current->next;
        index++;
    }

    return {false, 0};  
}


ListNode* createLinkedList(int& cyclePos) {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) return nullptr;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleNode = nullptr;

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

        
        if (i == cyclePos) {
            cycleNode = newNode;
        }
    }

    
    char createCycle;
    cout << "Do you want to create a cycle? (y/n): ";
    cin >> createCycle;

    if (createCycle == 'y' || createCycle == 'Y') {
        cout << "Enter the position (0-based) where the cycle starts (enter -1 for no cycle): ";
        cin >> cyclePos;
        if (cyclePos >= 0 && cyclePos < n) {
            cycleNode = head;
            for (int i = 0; i < cyclePos; i++) {
                cycleNode = cycleNode->next;
            }
            tail->next = cycleNode;  // Create the cycle
        }
    }

    return head;
}

// Main function
int main() {
    int cyclePos = -1;
    ListNode* head = createLinkedList(cyclePos);

    pair<bool, int> result = detectCycle(head);
    if (result.first) {
        cout << "Cycle detected with length: " << result.second << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

   
    return 0;
}
