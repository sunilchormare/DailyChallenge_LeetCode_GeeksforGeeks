class Robot {

    int m, n;
    int x, y;
    char direction;
    int len;

    public Robot(int width, int height) {
        this.m = height;
        this.n = width;
        this.x = 0;
        this.y = 0;
        this.direction = 'E';
        this.len = 0;
    }
    
    public void step(int num) {
        if (num == 0) return;
        int totalLen = 2 * (m + n) - 4;
        int rem = (len + num) % totalLen;
        len = rem;
        if (rem == 0) {
            x = 0;
            y = 0;
            direction = 'S';
        } else if (rem > 2 * n + m - 3) {
            x = 0;
            y = totalLen - rem;
            direction = 'S';
        } else if (rem > n + m - 2) {
            x = 2*n+m-3-rem;
            y = m-1;
            direction = 'W';
        } else if (rem > n - 1) {
            x = n-1;
            y = rem-n+1;
            direction = 'N';
        } else {
            x = rem;
            y = 0;
            direction = 'E';
        }
    }
    
    public int[] getPos() {
        return new int[]{x, y};
    }
    
    public String getDir() {
        switch (direction) {
            case 'N': return "North";
            case 'S': return "South";
            case 'E': return "East";
            default: return "West";
        }
    }
}