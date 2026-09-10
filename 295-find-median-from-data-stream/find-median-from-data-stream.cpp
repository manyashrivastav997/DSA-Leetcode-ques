#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> max_heap; // Stores the smaller half of numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap; // Stores the larger half of numbers

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Always push to max_heap first
        max_heap.push(num);
        
        // Balance: The largest element of the smaller half goes to the larger half
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        // Maintain the property that max_heap can have at most one more element than min_heap
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};
