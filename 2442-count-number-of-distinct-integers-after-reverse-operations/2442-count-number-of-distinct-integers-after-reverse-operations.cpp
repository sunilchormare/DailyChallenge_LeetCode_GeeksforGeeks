class Solution {
    int reverse(int n){
    int val = 0;
    while(n > 0){
        val = val * 10 + (n % 10);
        n /= 10;
    }
    return val;
}

public int countDistinctIntegers(int[] nums) {
    HashSet<Integer> st = new HashSet<>();
    for (int i : nums) {
        st.add(i);
        st.add(reverse(i));
    }
    return st.size();
}
}