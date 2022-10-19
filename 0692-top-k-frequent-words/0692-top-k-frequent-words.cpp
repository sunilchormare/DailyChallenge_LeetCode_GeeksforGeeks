class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
   unordered_map<string, int> counter;
        for (string word : words) {
            counter[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        for (auto p : counter) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    struct compare {
        bool operator()(pair<int, string>& l, pair<int, string>& r) {
            return l.first > r.first || (l.first == r.first && l.second.compare(r.second) < 0);
        }
    };
    
};