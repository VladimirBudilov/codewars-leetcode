/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.*/

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;


    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static void addNode(ListNode **list, ListNode *val) {
        if (*list == nullptr) {
            *list = val;
            return;
        }
        ListNode *tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = val;
        val->next = nullptr;
    }


    static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *sortedList = nullptr;

        while (list1 || list2) {
            if (!list1) {
                addNode(&sortedList, list2);
                list2 = list2->next;
            } else if (!list2) {
                addNode(&sortedList, list1);
                list1 = list1->next;
            } else if (list1->val <= list2->val) {
                addNode(&sortedList, list1);
                list1 = list1->next;
            } else if (list1->val >= list2->val) {
                addNode(&sortedList, list2);
                list2 = list2->next;
            }
        }
        return sortedList;
    }
};


int main() {
    ListNode l1_1 = ListNode(1);
    ListNode l1_2 = ListNode(3);
    ListNode l1_3 = ListNode(5);

    ListNode l2_1 = ListNode(2);
    ListNode l2_2 = ListNode(4);
    ListNode l2_3 = ListNode(6);

    l1_1.next = &l1_2;
    l1_2.next = &l1_3;

    l2_1.next = &l2_2;
    l2_2.next = &l2_3;

    ListNode *sorted = Solution::mergeTwoLists(&l1_1, &l2_1);

    while (sorted != nullptr) {
        std::cout << sorted->val << std::endl;
        sorted = sorted->next;
    }
    return 0;
}