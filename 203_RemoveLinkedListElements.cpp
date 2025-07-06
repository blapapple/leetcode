#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
    public:
        ListNode* sol(int val, struct ListNode* head){
            ListNode* ret = head;
            while(ret != nullptr && ret->val == val){
                ListNode* temp = ret;
                ret = ret->next;
                delete temp;
            }
            ListNode* ptr = ret;

            while(ptr != nullptr){
                if(ptr->next != nullptr && ptr->next->val == val){
                    ListNode* temp = ptr->next;
                    ptr->next = ptr->next->next;
                    delete temp;
                    continue;
                }
                ptr = ptr->next;
            }
            return ret;
        }
};

int main() {
    std::ifstream file("./input.txt");
    struct ListNode* head = new ListNode();
    if(file.is_open()) {
        std::string str;
        int target;
        std::getline(file, str);
        std::stringstream ss(str);
        std::string token;
        struct ListNode* ptr = head;
        while (std::getline(ss, token, ' ')){
            struct ListNode* temp = new ListNode(std::stoi(token));
            ptr->next = temp;
            ptr = ptr->next;
        }   
        std::getline(file, str);
        target = std::stoi(str);
        Solution sol;
        ListNode* ret = sol.sol(target, head->next);
        if(head->next == nullptr){
            return 0;
        }
        while(head != nullptr){
            struct ListNode* temp = head;
            head = head->next;
            std::cout << temp->val << " ";
            delete temp;
        }
    }
    return 0;
}