#include <iostream>

using namespace std;

typedef struct Node {
  int value;
  struct Node *next;
} ListNode;

ListNode* FindKthToTail(ListNode* head, int k) {
  if (k < 0) {
    return NULL;
  }

  ListNode *fast = head;
  ListNode *slow = head;

  for (int i = 0; i <= k; i++) {
    if (fast) {
      fast = fast->next;
    } else {
      return NULL;
    }
  }

  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}

int main() {
  int n, k;

  cin >> n;

  ListNode *headNode = NULL;
  ListNode *lastNode = NULL;

  for (int i = 0; i < n; i++) {
    ListNode *newNode = new ListNode;
    newNode->next = NULL;
    cin >> newNode->value;

    if (headNode) {
      lastNode->next = newNode;
      lastNode = newNode;
    } else {
      headNode = lastNode = newNode;
    }
  }

  cin >> k;

  ListNode *result = FindKthToTail(headNode, k);

  if (result) {
    cout << result->value << endl;
  }

  return 0;
}
