/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
      int val;
      ListNode *next;
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = head;
        while (next != nullptr) {
            next = next->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
