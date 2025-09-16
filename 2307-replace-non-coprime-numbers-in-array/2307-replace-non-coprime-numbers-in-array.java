class Solution {
        public List<Integer> replaceNonCoprimes(int[] A) {
        LinkedList<Integer> res = new LinkedList();
        for (int a : A) {
            while (true) {
                int last = res.isEmpty() ? 1 : res.getLast();
                int x = gcd(last, a);
                if (x == 1) break; // co-prime
                a *= res.removeLast() / x;
            }
            res.add(a);
        }
        return res;
    }

    private int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
}