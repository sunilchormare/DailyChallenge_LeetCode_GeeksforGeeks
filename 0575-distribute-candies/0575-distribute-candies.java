class Solution {
    public int distributeCandies(int[] candies) {
	int total = candies.length;
	Set<Integer> kinds = new HashSet<Integer>();
	for (int i = 0; i < total; i++) {
		kinds.add(candies[i]);
	}
	if (kinds.size() > total / 2) {
		return total / 2;
	} else {
		return kinds.size();
	}
}
}