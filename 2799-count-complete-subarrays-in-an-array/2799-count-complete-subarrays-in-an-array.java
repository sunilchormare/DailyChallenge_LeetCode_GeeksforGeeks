class Solution {
   public int countCompleteSubarrays(int[] A) {
        Set<Integer> s = new HashSet<>();
        for (int a : A)
            s.add(a);
        int n = A.length, k = s.size(), res = 0, i = 0;
        Map<Integer, Integer> count = new HashMap<>();

        for (int j = 0; j < n; ++j) {
            if (count.getOrDefault(A[j], 0) == 0)
                k--;
            count.put(A[j], count.getOrDefault(A[j], 0) + 1);
            while (k == 0) {
                count.put(A[i], count.get(A[i]) - 1);
                if (count.get(A[i]) == 0)
                    k++;
                i++;
            }
            res += i;
        }
        return res;
    }
}