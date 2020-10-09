//Given a linked list, rotate the list to the right by k places, where k is non-negative.
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *insertNode(ListNode *head, int value) {
    auto *node = new ListNode(value);
    if (head) {
        ListNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = node;
    } else {
        head = node;
    }
    return head;
}

ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) return head;
    int n = 1;
    ListNode *tail = head;
    while (tail->next) {
        ++n;
        tail = tail->next;
    }
    k = k % n;
    if (k == 0) return head;
    ListNode *newHead = head;
    ListNode *newTail = head;
    while (n > k) {
        newTail = newHead;
        newHead = newHead->next;
        --n;
    }
    newTail->next = nullptr;
    tail->next = head;
    return newHead;

}

void printLinkedList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int value;
    ListNode *head = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertNode(head, value);
    }
    //Before rotation
    cout << "Original List\n";
    printLinkedList(head);
    head = rotateRight(head, k);
    //After rotation
    cout << "Clockwise Rotation by " << k << "\n";
    printLinkedList(head);
    return 0;
}
/*
 * Input
 * 5 2
 * 1 2 3 4 5
 *
 * Output
 * Original List
 * 1 2 3 4 5
 * Clockwise Rotation by 2
 * 4 5 1 2 3
 */
