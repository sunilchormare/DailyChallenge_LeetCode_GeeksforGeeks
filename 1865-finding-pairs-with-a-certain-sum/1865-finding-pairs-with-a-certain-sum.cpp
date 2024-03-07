class FindSumPairs {
public:
    // store both arrays  
    vector<int> arr1, arr2;
    
    // map to store each element occurance of arr2
    // and when finding count we can directly get number of times that elament is present, to add in our answer
    unordered_map<int,int> m2;
  
    // store both arrays, and make frequency map of arr2 elements
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
      arr1 = nums1; arr2 = nums2;
      for(auto &i: arr2) m2[i]++;
    }

    void add(int index, int val) {
      int prev = arr2[index];
      arr2[index] += val;
      
      // now when we add val at index in arr2
      // we should decrease the count of element originally in arr2 at index from the map
      //because it's one occurence is removed from the array so remove from map also
      m2[prev]--;
      if(m2[prev] == 0) m2.erase(prev);
      
      // then the number is changed to some new number so we increment it's count in map also
      m2[arr2[index]]++;
    }
    
    int count(int tot) {
      int ans = 0;
      // now we can traverse in arr1 
      // and find 'target = (tot-arr1[i])' in arr2
      // and we kept map for arr2 elements for we can get all counts of target in O(1)
      for(auto &i: arr1){
        if(m2.find(tot-i) != m2.end()){
          ans += m2[tot-i];
        }
      }
      return ans;
    }
};