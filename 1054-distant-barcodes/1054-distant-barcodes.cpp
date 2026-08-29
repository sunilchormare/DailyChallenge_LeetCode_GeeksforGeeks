class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int barcode : barcodes) {
            freq[barcode]++;
        }

        // Convert to {barcode, frequency}
        vector<pair<int, int>> items;

        for (auto& [barcode, count] : freq) {
            items.push_back({barcode, count});
        }

        // Sort by frequency descending
        sort(items.begin(), items.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {
                 return a.second > b.second;
             });

        vector<int> result(barcodes.size());

        int index = 0;

        for (auto& [barcode, count] : items) {

            while (count > 0) {

                result[index] = barcode;

                count--;

                // Move to next even position
                index += 2;

                // If even positions are exhausted,
                // start from the first odd position.
                if (index >= result.size()) {
                    index = 1;
                }
            }
        }

        return result;
    }
};