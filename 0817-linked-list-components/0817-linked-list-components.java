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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> setG (G.begin(), G.end());
        int res = 0;
        while (head != NULL) {
            if (setG.count(head->val) && (head->next == NULL || !setG.count(head->next->val))) res++;
            head = head->next;
        }
        return res;
    }
};