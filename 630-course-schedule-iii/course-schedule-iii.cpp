#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        // Sort courses by their last day (deadline)
        std::sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        std::priority_queue<int> maxHeap;
        int totalTime = 0;

        for (const auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            totalTime += duration;
            maxHeap.push(duration);

            // If total time exceeds the deadline, drop the longest course
            if (totalTime > lastDay) {
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};
