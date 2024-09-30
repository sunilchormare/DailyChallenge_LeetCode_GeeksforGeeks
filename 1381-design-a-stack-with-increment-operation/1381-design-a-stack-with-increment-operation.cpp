class CustomStack {
private:
    list<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) { this->maxSize = maxSize; }

    void push(int x) {
        // Add the element to the top of the stack if it hasn't reached maxSize
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        // Return -1 if the stack is empty, otherwise remove and return the top
        // element
        if (stack.empty()) return -1;
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    void increment(int k, int val) {
        // Increment the bottom k elements (or all elements if k > stack size)
        auto it = stack.begin();
        for (int i = 0; i < k && it != stack.end(); i++, it++) {
            *it += val;
        }
    }
};