class Solution {
    public String fractionAddition(String expression) {
        expression = expression.replaceAll("-", "\\+-");
        String[] fractions = expression.split("\\+");
        
        List<int[]> fr = new ArrayList();
        
        int commonDenom = 1;
        
        for (String s : fractions) {
            if (s.length() == 0)
                continue;
            
            String[] a = s.split("/");
            int n = Integer.parseInt(a[0]);
            int d = Integer.parseInt(a[1]);
            
            if (commonDenom % d != 0)
                commonDenom *= d;
            fr.add(new int[]{n, d});
        }
        
        int sum = 0;
        for (int[] a : fr) {
            sum += (a[0] * commonDenom / a[1]);
        }

        int gcdSumDenom = gcd(Math.abs(sum), commonDenom);
        sum /= gcdSumDenom;
        commonDenom /= gcdSumDenom;
        
        return "" + sum + "/" + (commonDenom == 0 ? 1 : commonDenom);
    }
    
    public int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}