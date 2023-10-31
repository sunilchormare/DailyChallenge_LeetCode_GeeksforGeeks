class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> m = new HashMap<>();
        for (int i = 0; i < names.length; m.put(names[i], 1), i++)
            if (m.containsKey(names[i])) {
                int k = m.get(names[i]);
                while (m.containsKey(names[i] + "(" + k + ")"))
                    k++;
                m.put(names[i], k + 1);
                names[i] = names[i] + "(" + k + ")";
            }
        return names;
    }
}