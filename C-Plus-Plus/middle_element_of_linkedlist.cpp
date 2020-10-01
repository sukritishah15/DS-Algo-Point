#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

void middleelement(node *head)
{
  if (head == NULL)
    return;

  node *slow = head;
  node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  cout << "The middle element is " << slow->data;
}
void push(node **head_ref, int data)
{
  node *temp = new node();
  temp->data = data;
  temp->next = (*head_ref);
  (*head_ref) = temp;
}

int main()
{
  node *head = NULL;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    push(&head, val);
  }
  middleelement(head);
  return 0;
}

/*

Problem:
Given the reference to the head of a linked list, find out the middle element in the list

Sample problem 1:-
Enter n: 5
Linked list : 1->2->3->4->5

Sample Output:-
The middle element is 3

Time Complexity - O(n)
Space Complexity - O(1)

*/