/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
    if(node == null)
            return node;
        
        Map<Node, Node> visited = new HashMap<Node, Node>();
        Deque<Node> stack = new ArrayDeque<Node>();
        stack.push(node);
        visited.put(node, new Node(node.val));
        
        while(!stack.isEmpty()){
            Node top = stack.pop();
            for(Node neighbor : top.neighbors){
                if(!visited.containsKey(neighbor)){
                    visited.put(neighbor, new Node(neighbor.val));
                    stack.push(neighbor);
                }
                
                visited.get(top).neighbors.add(visited.get(neighbor));
            }
        }
        
        return visited.get(node);
        
    }
}