/*
Problem: Merge Two Sorted Lists - Easy
Links: https://leetcode.com/problems/merge-two-sorted-lists/
Time Complexity: O(n)
Space Complexity: O(1)

Detail:

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

Example 2:
    Input: list1 = [], list2 = []
    Output: []

Example 3:
    Input: list1 = [], list2 = [0]
    Output: [0]
*/ 

struct ListNode {
      int val;
      ListNode *next;
      //ListNode() : val(0), next(nullptr) {}
      //ListNode(int x) : val(x), next(nullptr) {}
      //ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res=nullptr;
        ListNode* p;
        bool init=0;
        while( list1!=nullptr || list2!=nullptr){

            if(list1==nullptr){
                if(!init){
                    res=list2;
                    p=res;
                    init=true;
                    list2 = list2->next;
                    continue;
                }
                p->next = list2;
                list2 = list2->next;
            }
            else if(list2==nullptr){
                if(!init){
                    res=list1;
                    p=res;
                    init=true;
                    list1 = list1->next;
                    continue;
                }
                p->next = list1;
                list1 = list1->next;
            }
            else{
                if(list1->val > list2->val){
                    if(!init){
                        res=list2;
                        p=res;
                        init=true;
                        list2 = list2->next;
                        continue;
                    }
                    p->next = list2;
                    list2 = list2->next;
                }
                else{
                    if(!init){
                        res=list1;
                        p=res;
                        init=true;
                        list1 = list1->next;
                        continue;
                    }
                    p->next = list1;
                    list1 = list1->next;
                }
            }
            p=p->next;
        }
        return res;
    }
};