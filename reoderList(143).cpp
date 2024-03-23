class Solution {
private:
    ListNode* reverseList(ListNode* node){
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while(curr!=nullptr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        // reverse list from the middle
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        // now slow will be pointing to the middle node reverse the list from middle->next
        ListNode* q = reverseList(slow->next);
        // break into two lists from middle
        slow->next = nullptr;
        //now you have two lists...traverse them simultaneously and use 4 pointers to make the links
        ListNode* p = head;
        while(q!=nullptr){
            ListNode* t1 = p->next;
            ListNode* t2 = q->next;
            //make connections
            p->next = q;
            q->next = t1;
            // update pointers value
            p = t1;
            q = t2;
        }
    }
};