// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         vector<ListNode*> A = {head};
//         while (A.back()->next != NULL)
//             A.push_back(A.back()->next);
//         return A[A.size() / 2];
//     }
// };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
