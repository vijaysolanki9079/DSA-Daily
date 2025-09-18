#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class TaskManager {
private:
    // Task structure to store in priority queue
    struct Task {
        int userId;
        int taskId;
        int priority;
        
        Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
        
        // Custom comparator for max heap
        // Higher priority first, then higher taskId for ties
        bool operator<(const Task& other) const {
            if (priority != other.priority) {
                return priority < other.priority; // Max heap for priority
            }
            return taskId < other.taskId; // Max heap for taskId
        }
    };
    
    // Max heap to store tasks ordered by priority, then taskId
    priority_queue<Task> taskHeap;
    
    // Map to store task details: taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> taskMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        // Add to heap
        taskHeap.push(Task(userId, taskId, priority));
        
        // Add to map for quick lookup
        taskMap[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        // Update the task in the map
        int userId = taskMap[taskId].first;
        taskMap[taskId].second = newPriority;
        
        // Add new version to heap (old version will be ignored during execTop)
        taskHeap.push(Task(userId, taskId, newPriority));
    }
    
    void rmv(int taskId) {
        // Remove from map (heap entries will be ignored during execTop)
        taskMap.erase(taskId);
    }
    
    int execTop() {
        // Find the valid task with highest priority
        while (!taskHeap.empty()) {
            Task top = taskHeap.top();
            taskHeap.pop();
            
            // Check if this task still exists and has the same priority
            auto it = taskMap.find(top.taskId);
            if (it != taskMap.end() && it->second.second == top.priority) {
                // Valid task found - remove it and return userId
                int userId = it->second.first;
                taskMap.erase(it);
                return userId;
            }
            // Otherwise, this is a stale entry, continue to next task
        }
        
        // No tasks available
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */