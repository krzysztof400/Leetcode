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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while(curr != nullptr){
            len++;
            curr = curr->next;
        }

        if(len%2==0){
            for(int i =0; i<len/2; i++){
                head = head->next;
            }
        }
        else{
            for(int i = 0; i<(len-1)/2; i++){
                head = head->next;
            }
        }
        return head;
    }
};