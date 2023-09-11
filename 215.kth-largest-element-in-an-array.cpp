/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start


class helperClass{
    private : 
        vector<int> heap;

        void heapifyup(int index){
            int parent = (index-1)/2;
            if(heap[parent] > heap[index]){
                swap(heap[parent],heap[index]);
                heapifyup(parent);
            }
        }

        void heapify(int index){
            int smallestIndex = index;
            int leftChild = 2*index+1;
            int rightChild = 2*index+2;
            if(leftChild < heap.size() && heap[leftChild] < heap[smallestIndex]){
                smallestIndex = leftChild;
            }
            if(rightChild < heap.size() && heap[rightChild] < heap[smallestIndex]){
                smallestIndex = rightChild;
            }
            if(smallestIndex!= index){
                swap(heap[smallestIndex],heap[index]);
                heapify(smallestIndex);
            }
        }


    public : 
        void insert(int n){
            int index = heap.size();
            heap.push_back(n);
            heapifyup(index);
        }
        void deleteMin(){
            if(!heap.size())return;
            swap(heap[0], heap[heap.size()-1]);
            heap.pop_back();
            heapify(0);
            return;
        }
        int getTop(){
            if(!heap.size())return -1;
            return heap[0];
        }
};



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        helperClass s;
        for(int i=0;i<nums.size();i++)s.insert(nums[i]);
        k = nums.size()-k;
        for(int i=0;i<k;i++)s.deleteMin();
        return s.getTop();
    }
};
// @lc code=end

