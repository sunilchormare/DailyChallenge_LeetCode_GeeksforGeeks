class Solution {
public:
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> res;
//         //if(head->next==NULL) return {0};
//         while(head!=NULL)
//         {
//             ListNode *tem=head;
//             while(tem->next!=NULL)
//             {
//                 if(tem->val>head->val){
//                     res.push_back(tem->val);
//                     //cout<<tem->val<<" ";
//                     break;
//                 }
//                 tem=tem->next;
//             }
//             if(tem->next==NULL)
//                 res.push_back(0);
            
//             head=head->next;
//         }
//         return res;
    //}
     vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stack;
        for (ListNode* node = head; node; node = node->next) {
            while (stack.size() && res[stack.back()] < node->val) {
                res[stack.back()] = node->val;
                stack.pop_back();
            }
            stack.push_back(res.size());
            res.push_back(node->val);
        }
        for (int i: stack) res[i] = 0;
        return res;
    }
};