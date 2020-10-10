/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        int count = -1, times = 0;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL) fast = fast->next;
            if(fast == slow) count++;
            if(count == 0) times++;
            if(count == 1) break;
            slow = slow->next;
        }
        if(count == -1) return NULL;
        //倒数times节点位置
        fast = slow = head;
        while(times > 0){
            fast = fast->next;
            times--;
        }
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};