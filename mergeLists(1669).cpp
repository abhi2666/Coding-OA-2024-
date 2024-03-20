class Solution {
private:
    ListNode* getLastNode(ListNode* l2){
        ListNode * p = l2;
        while(p->next != nullptr) p = p->next;
        return p;
    }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt1 = 0;
        ListNode* temp1 = list1;
        while(cnt1 < a-1){
            temp1=temp1->next;
            cnt1++;
        }
        cnt1 = 0;
        ListNode* temp2 = list1;
        while(cnt1 < b+1){
            temp2 = temp2->next;
            cnt1++;
        }
        // get last node from list2
        ListNode* last = getLastNode(list2);
        temp1->next = list2;
        last->next = temp2;
        return list1;

    }
};