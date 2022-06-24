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
    int pairSum(ListNode* head) {
       vector<int> vec;
        
        ListNode *curr = head;
        
        while(curr)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        int i=0,j=vec.size()-1;
        
        int maxVal = 0 ;
        
        while(i<j)
            maxVal = max(maxVal , vec[i++] + vec[j--]);            
        
        return maxVal;  
    }
};