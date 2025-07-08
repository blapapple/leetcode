
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "headers.h"
// @lc code=start
class MinStack {
  private:
    struct StackNode {
        int val;
        shared_ptr<StackNode> next;
        StackNode() : val(0), next(nullptr) {}
        StackNode(int val) : val(val), next(nullptr) {}
        StackNode(int val, shared_ptr<StackNode> next) : val(val), next(next) {}
    };

    shared_ptr<StackNode> topNode;
    int size;
    multiset<int> mset;

  public:
    MinStack() : topNode(nullptr), size(0) {}

    void push(int val) {
        auto it = make_shared<StackNode>(val, topNode);
        topNode = it;
        mset.insert(val);
        size++;
    }

    void pop() {
        if (topNode != nullptr) {
            auto it = mset.find(topNode->val);
            if (it != mset.end()) {
                mset.erase(it);
            }
            topNode = topNode->next;
            size--;
        }
    }

    int top() { return topNode->val; }

    int getMin() {
        auto it = *mset.begin();
        return it;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
    MinStack s;
    return 0;
}