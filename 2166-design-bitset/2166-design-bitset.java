class Bitset {
    StringBuilder s = new StringBuilder(), flipped = new StringBuilder();
    int siz = 0, ones = 0;
    public Bitset(int size) {
        siz = size;
        for (int i = 0; i < size; i++) {
            s.append(0); flipped.append(1);
        }
    }
    public void fix(int idx) {
        if(s.charAt(idx) == '0') ones++;  
        s.setCharAt(idx, '1'); flipped.setCharAt(idx, '0'); 
    }
    public void unfix(int idx) {
        if(s.charAt(idx) == '1') ones--;
        s.setCharAt(idx, '0'); flipped.setCharAt(idx, '1'); 
    }
    public void flip() {
        StringBuilder temp = s;
        s = flipped;
        flipped = temp;
        ones = siz - ones;
    }
    public boolean all() { return ones == siz; }
    public boolean one() { return ones > 0; }
    public int count() { return ones; }
    public String toString() { return s.toString(); }
}