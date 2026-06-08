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
    private:
     ListNode* reverse(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;  
}
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second=slow->next;
        slow->next=NULL;
        second=reverse(second);

        ListNode* first=head;
        while(second){
            ListNode* next1=first->next;
            ListNode* next2=second->next;

            first->next=second;
            second->next=next1;
            first=next1;
            second=next2;
        }
    }
};
