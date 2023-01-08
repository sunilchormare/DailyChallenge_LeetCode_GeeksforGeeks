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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val>l2->val) 
        {
            ListNode* t=l1;
            l1=l2;
            l2=t;
            //ap(l1,l2);
        }
        ListNode* res=l1;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode* tem=NULL;
            while(l1!=NULL&& l1->val<=l2->val)
            {
             tem=l1;
             l1=l1->next;
                
            }
            tem->next=l2;
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
           
        }
        
        return res; 
    }
};