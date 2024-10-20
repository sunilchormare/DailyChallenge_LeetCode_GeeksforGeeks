class Solution {

    int index = 0;

    public boolean parseBoolExpr(String expression) {
        return evaluate(expression);
    }

    // Recursively parse and evaluate the boolean expression
    private boolean evaluate(String expr) {
        char currChar = expr.charAt(index++);

        // Base cases: true ('t') or false ('f')
        if (currChar == 't') return true;
        if (currChar == 'f') return false;

        // Handle NOT operation '!(...)'
        if (currChar == '!') {
            index++; // Skip '('
            boolean result = !evaluate(expr);
            index++; // Skip ')'
            return result;
        }

        // Handle AND '&(...)' and OR '|(...)'
        List<Boolean> values = new ArrayList<>();
        index++; // Skip '('
        while (expr.charAt(index) != ')') {
            if (expr.charAt(index) != ',') {
                values.add(evaluate(expr)); // Collect results of subexpressions
            } else {
                index++; // Skip commas
            }
        }
        index++; // Skip ')'

        // Manual AND operation: returns false if any value is false
        if (currChar == '&') {
            for (Boolean v : values) {
                if (!v) return false;
            }
            return true;
        }

        // Manual OR operation: returns true if any value is true
        if (currChar == '|') {
            for (Boolean v : values) {
                if (v) return true;
            }
            return false;
        }

        return false; // This point should never be reached
    }
}