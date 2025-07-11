/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include "headers.h"
// @lc code=start
class MedianFinder {
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<>> minPq;

  public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxPq.size() == minPq.size()) {
            if (maxPq.empty() || num <= minPq.top()) {
                maxPq.push(num);
            } else {
                maxPq.push(minPq.top());
                minPq.pop();
                minPq.push(num);
            }
        } else {
            if (num >= maxPq.top()) {
                minPq.push(num);
            } else {
                minPq.push(maxPq.top());
                maxPq.pop();
                maxPq.push(num);
            }
        }
    }

    double findMedian() {
        if (maxPq.size() == minPq.size()) {
            return (maxPq.top() + minPq.top()) / 2.0;
        } else {
            return maxPq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
