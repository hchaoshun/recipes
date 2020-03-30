#include <iostream>

struct Node{
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

//tmp一直是最后一个节点，随着递归传递返回
Node *reverse(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  std::cout << "head: " << head->val << std::endl;
  Node *tmp = reverse(head->next);
  if (tmp != nullptr) {
    std::cout << "tmp: " << tmp->val << std::endl;
  }
  head->next->next = head;
  head->next = nullptr;
  return tmp;
}

void print(Node *head) {
  while (head != nullptr) {
    std::cout << head->val << ",";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  Node *head = new Node(1);
  Node *p = head;
  head->next = new Node(2);
  head = head->next;
  head->next = new Node(3);
  head = head->next;
  head->next = new Node(4);

  Node *res = reverse(p);
  print(res);
  return 0;
}
