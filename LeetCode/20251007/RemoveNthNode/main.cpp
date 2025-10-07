/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* current = head;
        while(current != nullptr) {
            current = current->next;
            ++size;
        }

        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* prev = head;
        for (int i = 0; i < size - n - 1; ++i) {
            prev = prev->next;
        }

        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;

        return head;
    }

    void print(ListNode* head) {
        ListNode* current = head;
        while(current != nullptr) {
            std::cout << current->val;
            if (current->next != nullptr) 
                std::cout << " -> ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sol;
    sol.print(n1);
    
    ListNode* newHead = sol.removeNthFromEnd(n1, 2);
    sol.print(newHead);

    return 0;
}
