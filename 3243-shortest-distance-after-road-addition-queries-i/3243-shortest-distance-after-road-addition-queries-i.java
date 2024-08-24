import java.util.*;

class Solution {
    public int fun(ArrayList<ArrayList<Integer>> list, int n) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        q.add(0);
        visited[0] = true;
        int count = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.poll();
                if (curr == n - 1) {
                    return count;
                }
                for (int neighbor : list.get(curr)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.add(neighbor);
                    }
                }
            }
            count++;
        }
        return -1; // No path to 'n'
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] arr) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            List<Integer> dummy = new ArrayList<>();
            dummy.add(i);
            list.add(new ArrayList<>(dummy));
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            list.get(u).add(v);
            ans.add(fun(list, n));
        }

        int[] num = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            num[i] = ans.get(i);
        }
        return num;
    }
}