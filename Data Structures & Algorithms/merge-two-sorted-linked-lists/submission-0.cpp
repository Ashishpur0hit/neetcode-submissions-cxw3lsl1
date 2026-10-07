/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3=NULL,*temp=NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                if(!list3)
                {
                    list3 = new ListNode(list1->val);
                    temp = list3;
                }
                else 
                {
                    temp->next = new ListNode(list1->val);
                    temp=temp->next;
                }
                list1 = list1->next;
            }
            else
            {
                if(!list3)
                {
                    list3 = new ListNode(list2->val);
                    temp = list3;
                }
                else 
                {
                    temp->next = new ListNode(list2->val);
                    temp=temp->next;
                }
                list2=list2->next;
            }
        }


        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return list3;
    }
};
