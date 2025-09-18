import java.util.*;

class TaskManager {
    private static class Task implements Comparable<Task> {
        int userId, taskId, priority;

        Task(int userId, int taskId, int priority) {
            this.userId = userId;
            this.taskId = taskId;
            this.priority = priority;
        }

        @Override
        public int compareTo(Task other) {
            if (this.priority != other.priority) {
                return Integer.compare(other.priority, this.priority);
            }
            return Integer.compare(other.taskId, this.taskId);
        }
    }

    private final TreeMap<Task, Integer> sortedTasks;
    private final Map<Integer, Task> taskMap; 

    public TaskManager(List<List<Integer>> tasks) {
        sortedTasks = new TreeMap<>();
        taskMap = new HashMap<>();

        for (List<Integer> task : tasks) {
            int userId = task.get(0), taskId = task.get(1), priority = task.get(2);
            add(userId, taskId, priority);
        }
    }

    public void add(int userId, int taskId, int priority) {
        Task task = new Task(userId, taskId, priority);
        sortedTasks.put(task, userId);
        taskMap.put(taskId, task);
    }

    public void edit(int taskId, int newPriority) {
        Task task = taskMap.get(taskId);
        if (task != null) {
            sortedTasks.remove(task);
            task.priority = newPriority;
            sortedTasks.put(task, task.userId);
        }
    }

    public void rmv(int taskId) {
        Task task = taskMap.get(taskId);
        if (task != null) {
            sortedTasks.remove(task);
            taskMap.remove(taskId);
        }
    }

    public int execTop() {
        if (sortedTasks.isEmpty()) {
            return -1;
        }
        Task topTask = sortedTasks.firstKey();
        sortedTasks.remove(topTask);
        taskMap.remove(topTask.taskId);
        return topTask.userId;
    }
}