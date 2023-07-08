#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};
 


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int p1Num = 0,p2Num = 0, highBit = 0;
    struct ListNode *result = NULL;
    struct ListNode *float_p = NULL;
    struct ListNode *pr;
    while (l1 || l2 || highBit) {
        pr = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (result == NULL) {
            result = pr;
            float_p = pr;
        } else {
            float_p->next = pr;
            float_p = pr;
        }
        highBit += l1 ? l1->val : 0;
        highBit += l2 ? l2->val : 0;
        pr->val = highBit % 10;
        highBit = highBit / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    float_p->next = NULL;
    return result;
}

int main(void) {
    struct ListNode fn3 = {val:3, next:NULL};
    struct ListNode fn2 = {val:4, next:&fn3};
    struct ListNode fn1 = {val:2, next:&fn2};

    struct ListNode tn3 = {val:4, next:NULL};
    struct ListNode tn2 = {val:6, next:&tn3};
    struct ListNode tn1 = {val:5, next:&tn2};
    

    

    struct ListNode* p = addTwoNumbers(&fn1, &tn1);
    while (p != NULL) {
        printf("%d->", p->val);
        p = p->next;
    }


    return 0;
}