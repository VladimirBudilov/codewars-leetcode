/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1 2 3
class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        long int n1 = 0;
        long int n2 = 0;

        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *res = new ListNode();
        ListNode *tmpNode = res;
        int sum = 0;
        int temp = 0;

        while (l1 && l2) {
            sum = l1->val + l2->val + temp;
            if (sum > 9)
                temp = 1;
            else
                temp = 0;
            tmpNode->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
            sum = 0;
            if (!l1 || !l2)
                break;
            tmpNode->next = new ListNode();
            tmpNode = tmpNode->next;
        }
        while (l1) {
            tmpNode->next = new ListNode();
            tmpNode = tmpNode->next;
            tmpNode->val = (l1->val + temp) % 10;
            if (l1->val + temp > 9)
                temp = 1;
            else
                temp = 0;
            l1 = l1->next;
        }
        while (l2) {
            tmpNode->next = new ListNode();
            tmpNode = tmpNode->next;
            tmpNode->val = (l2->val + temp) % 10;
            if (l2->val + temp > 9)
                temp = 1;
            else
                temp = 0;
            l2 = l2->next;
        }
        if (temp) {
            tmpNode->next = new ListNode();
            tmpNode = tmpNode->next;
            tmpNode->val = 1;
        }
        return res;
    }
};


int main() {
    ListNode l1_1 = ListNode(9);
    ListNode l1_2 = ListNode(9);
    ListNode l1_3 = ListNode(9);

    ListNode l2_1 = ListNode(9);
    //ListNode l2_2 = ListNode(4);
    //ListNode l2_3 = ListNode(1);

    l1_1.next = &l1_2;
    l1_2.next = &l1_3;

    //l2_1.next = &l2_2;
    //l2_2.next = &l2_3;

    ListNode *sorted = Solution::addTwoNumbers(&l1_1, &l2_1);

    while (sorted != nullptr) {
        std::cout << sorted->val << std::endl;
        sorted = sorted->next;
    }
    return 0;
}



