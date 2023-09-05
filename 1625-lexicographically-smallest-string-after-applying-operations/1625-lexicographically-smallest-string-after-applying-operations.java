class Solution {
    String ans;
    HashSet<String> set = new HashSet<>();
    int a, b;
    private void dfs(String str){
        if(set.contains(str)) return;
        if(ans.compareTo(str) > 0) ans = str;
        set.add(str);
        dfs(add(str));
        dfs(rotate(str));
    }
    private String add(String str){
        StringBuilder s = new StringBuilder();
        for(int i = 0; i < str.length(); i++){
            if(i % 2 == 0) s.append(str.charAt(i));
            else s.append((str.charAt(i) - '0' + a) %10);
        }
        return s.toString();
    }
    private String rotate(String s){
        int n = s.length();
        return s.substring(n-b, n) + s.substring(0, n-b);
    }
    public String findLexSmallestString(String s, int a, int b) {
        ans = s;
        this.a = a;
        this.b = b;
        dfs(s);
        return ans;
    }
}
