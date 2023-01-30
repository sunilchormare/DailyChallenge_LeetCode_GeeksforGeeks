class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
         int first = INT_MAX, last = 0, prev_val = h->val, min_d = INT_MAX;
    for (int i = 0; h->next != nullptr; ++i) {
        if ((max(prev_val, h->next->val) < h->val) || 
            (min(prev_val, h->next->val) > h->val)) {
            if (last != 0)
                min_d = min(min_d, i - last);
            first = min(first, i);
            last = i;
        }
        prev_val = h->val;
        h = h->next;
    }
    if (min_d == INT_MAX)
        return {-1, -1};
    return {min_d, last - first};
    }
};