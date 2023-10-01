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
        ListNode* merged_head = new ListNode();
        ListNode* merged_curr = merged_head;

        while (true) {
            if (list1 == nullptr) {
                merged_curr->next = list2;
                break;
            } else if (list2 == nullptr) {
                merged_curr->next = list1;
                break;
            }

            if (list1->val >= list2->val) {
                merged_curr->next = list2;
                list2 = list2->next;
            } else {
                merged_curr->next = list1;
                list1 = list1->next;
            }
            merged_curr = merged_curr->next;
            merged_curr->next = nullptr;
        }
        return merged_head->next;
    }
};

/* Optimized Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newl = new ListNode(0);
        ListNode* new1 = newl;
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while(list1 && list2){
            if(list1->val<=list2->val){
                newl->next = list1;
                list1 = list1->next;
                newl = newl->next;
            }
           else{
                newl->next = list2;
                list2 = list2->next;
                newl = newl->next;
            }
        }
        if(list1){
            newl->next= list1;
        }
        if(list2){
            newl->next= list2;
        }
    return new1->next;
    }
};
*/
