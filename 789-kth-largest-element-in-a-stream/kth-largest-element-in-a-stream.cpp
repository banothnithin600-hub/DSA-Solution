class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;  
    int k; // Number representing the k-th largest element

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        // Add initial numbers to the heap
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // Add the new value to the min-heap
        minHeap.push(val);
        
        // If the size of the heap exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // The root of the min-heap is the k-th largest element
        return minHeap.top();
    }
};
