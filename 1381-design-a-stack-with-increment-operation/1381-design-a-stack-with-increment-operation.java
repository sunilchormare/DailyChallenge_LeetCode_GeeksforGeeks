class CustomStack {

    private List<Integer> stack;
    private int maxSize;

    public CustomStack(int maxSize) {
        // Initialize the stack as a LinkedList for efficient add/remove operations
        stack = new LinkedList<>();
        this.maxSize = maxSize;
    }

    public void push(int x) {
        // Add the element to the top of the stack if it hasn't reached maxSize
        if (stack.size() < maxSize) {
            stack.addLast(x);
        }
    }

    public int pop() {
        // Return -1 if the stack is empty, otherwise remove and return the top element
        if (stack.isEmpty()) return -1;
        return stack.removeLast();
    }

    public void increment(int k, int val) {
        // Create an iterator to traverse the stack from bottom to top
        ListIterator<Integer> iterator = stack.listIterator();

        // Increment the bottom k elements (or all elements if k > stack size)
        while (iterator.hasNext() && k > 0) {
            int current = iterator.next();
            iterator.set(current + val);
            k--;
        }
    }
}