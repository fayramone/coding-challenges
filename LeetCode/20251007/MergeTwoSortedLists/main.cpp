/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */

#include <iostream>
#include <algorithm>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp;
        ListNode* current = &temp;
        ListNode* first = list1;
        ListNode* second = list2;

        while(first != nullptr && second != nullptr) {
            if (first->val <= second->val) {
                current->next = first;
                first = first->next;
            } else {
                current->next = second;
                second = second->next;
            }
            current = current->next;
        }
        if (first != nullptr) {
            current->next = first;
        } else {
            current->next = second;
        }

        return temp.next;
    }

    void print(ListNode* head);
};

void Solution::print(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;

    ListNode* m1 = new ListNode(1);
    ListNode* m2 = new ListNode(3);
    ListNode* m3 = new ListNode(4);
    m1->next = m2;
    m2->next = m3;

    Solution sol;
    sol.print(n1);
    sol.print(m1);

    Solution res;
    ListNode* newHead = res.mergeTwoLists(n1, m1);
    res.print(newHead);

    return 0;
}
