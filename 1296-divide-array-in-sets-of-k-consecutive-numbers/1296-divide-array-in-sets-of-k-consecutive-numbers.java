class Solution {
    public boolean isPossibleDivide(int[] A, int k) {
        Map<Integer, Integer> c = new TreeMap<>();
        for (int i : A) c.put(i, c.getOrDefault(i, 0)+1);
        Queue<Integer> start = new LinkedList<>();
        int last_checked = -1, opened = 0;
        for (int i : c.keySet()) {
            if (opened > 0 && i > last_checked + 1 || opened > c.get(i)) return false;
            start.add(c.get(i) - opened);
            last_checked = i; opened = c.get(i);
            if (start.size() == k) opened -= start.remove();
        }
        return opened == 0;
    }
}