// #include <iostream>
// #include <vector>

// struct ListNode {
//         int val;
//         ListNode *next;
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int x) : val(x), next(nullptr) {}
//         ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// ListNode* create_list(const std::vector<int>& values) {
//     if (values.empty()) return nullptr;

//     ListNode* head = new ListNode(values[0]);
//     ListNode* current = head;

//     for (size_t i = 1; i < values.size(); ++i) {
//         current->next = new ListNode(values[i]);
//         current = current->next;
//     }

//     return head;
// }

// ListNode* append(ListNode* head, int val) {
//     if (head == nullptr) return new ListNode(val);

//     ListNode* current = head;
//     while (current->next != nullptr) {
//         current = current->next;
//     }
//     current->next = new ListNode(val);
//     return head;
// }

// ListNode* prepend(ListNode* head, int val) {
//     return new ListNode(val, head);
// }

// void print_list(ListNode* head) {
//         std::cout << "[";
//         while (head != nullptr) {
//             std::cout << head->val;
//             head = head->next;
//             if (head != nullptr) std::cout << ",";
//         }
//         std::cout << "]";
//     } 

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* result = nullptr;
//         int carry = 0;
//         while(l1 != nullptr || l2 != nullptr || carry > 0) {
//             int a = (l1 == nullptr) ? 0 : l1->val;
//             int b = (l2 == nullptr) ? 0 : l2->val;
            
//             int sum = a + b + carry;
//             carry = sum / 10;
//             int digit = sum % 10;

//             result = append(result, digit);

//             if (l1 != nullptr) l1 = l1->next;
//             if (l2 != nullptr) l2 = l2->next;
//         }

//         return result;
//     }
// };



// int main() {
//     ListNode* list1 = create_list( { 2, 4, 3 } );
//     ListNode* list2 = create_list( { 5, 6, 4 } );
//     ListNode* result_list;

//     Solution sol;
//     print_list(result_list = sol.addTwoNumbers(list1, list2));

//     return 0;
// }