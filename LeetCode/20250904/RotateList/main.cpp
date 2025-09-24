#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        ListNode* new_tail = head;
        for (int i = 0; i < len - k - 1; i++) {
            new_tail = new_tail->next;
        }

        ListNode* new_head = new_tail->next;

        new_tail->next = nullptr;
        tail->next = head;

        return new_head;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4); 
    ListNode n5(5);



    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    PrintList(&n1);

    Solution sol;

    PrintList(sol.rotateRight(&n1, 3));

    

    return 0;
}