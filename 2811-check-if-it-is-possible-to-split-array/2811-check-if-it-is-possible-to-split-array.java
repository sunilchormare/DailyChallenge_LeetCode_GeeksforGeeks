class Solution {
     public boolean canSplitArray(List<Integer> A, int m) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A.get(i) + A.get(i + 1) >= m)
                return true;
        return A.size() < 3;
    }
}