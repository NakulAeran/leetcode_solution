/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;

public:
    MedianFinder(){}

    void addNum(int num)
    {
        leftHeap.push(num);
        if(!rightHeap.empty() && rightHeap.top()<leftHeap.top()){
            int right = rightHeap.top();
            int left = leftHeap.top();
            rightHeap.pop();
            leftHeap.pop();
            rightHeap.push(left);
            leftHeap.push(right);
        }
        if(leftHeap.size() > rightHeap.size()){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
    }

    double findMedian()
    {
        if(leftHeap.size()==rightHeap.size())return (leftHeap.top() + rightHeap.top())/2.0;
        else return rightHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
