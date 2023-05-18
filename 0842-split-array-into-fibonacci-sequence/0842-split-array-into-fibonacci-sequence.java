class Solution {

public  List<Integer> splitIntoFibonacci(String s) {
        List<Integer> ans = new ArrayList<>();
        splitIntoFibonacci(s, 0, new ArrayList<>(), ans);
        return ans;
    }

public  void splitIntoFibonacci(String s, int pos, List<Integer> local, List<Integer> ans) {
        if (pos == s.length() && isFibSequence(local)) {
            ans.addAll(local);
            return;
        }
    for (int i = pos; i < s.length(); i++) {
        if (!ans.isEmpty())break;
        String substr = s.substring(pos, i + 1);
        if ((overFlow(substr))
                || (local.size()>2 && !isFibSequence(local))
                || (substr.length()>1 && substr.charAt(0)=='0'))break;
        local.add((Integer.parseInt(substr)));
        splitIntoFibonacci(s, i + 1, local, ans);
        local.remove(local.size() - 1);
    }
}

 public  boolean overFlow(String s) {
        return s.length() > 10 || Long.parseLong(s) > Integer.MAX_VALUE;
}

private  boolean isFibSequence(List<Integer> local) {
        if (local.size() < 3) return false;
        for (int i = 2; i < local.size(); i++) {
            int a = local.get(i - 1);
            int b = local.get(i - 2);
            int c = local.get(i);
            if (c != (a + b)) return false;
        }
        return true;
    }
}