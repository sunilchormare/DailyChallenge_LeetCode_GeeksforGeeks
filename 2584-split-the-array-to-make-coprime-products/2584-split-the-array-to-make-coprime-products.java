class Solution {
   List<Integer> factorize(int n) {
    List<Integer> res = new ArrayList<>();
    for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
        if (n % i == 0) {
            res.add(i);
            while(n % i == 0)
                n /= i;
        }
    if (n > 1)
        res.add(n);        
    return res;
}
public int findValidSplit(int[] nums) {
    Map<Integer, Integer> left = new HashMap<>(), right = new HashMap<>();
    int res = 0;
    for (var n : nums)
        for (var f : factorize(n))
            right.put(f, right.getOrDefault(f, 0) + 1);
    for (int i  = 0, common = 0; i < nums.length - 1; ++i) {
        for (int f : factorize(nums[i])) {
            left.put(f, left.getOrDefault(f, 0) + 1);
            common += left.get(f) == 1 ? 1 : 0;
            common -= left.get(f).equals(right.get(f)) ? 1 : 0;
        }        
        if (common == 0)
            return i;
    }
    return -1;
}
}