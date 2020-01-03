#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp=new ListNode(0);
        ListNode *p=l1,*q=l2,*now=tmp;
        int carry=0;
        while(p!=NULL||q!=NULL){
            int x=(p!=NULL)?p->val:0;
            int y=(q!=NULL)?q->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            now->next=new ListNode(sum%10);
            now=now->next;
            if(q!=NULL) q=q->next;
            if(p!=NULL) p=p->next;
        }
        if(carry!=0){
            now->next=new ListNode(carry);
        }
        return tmp->next;
    }
};

int main()
{
    Solution test;
    ListNode *l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);
    ListNode *l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);
    test.addTwoNumbers(l1,l2);
    cout<<test.addTwoNumbers(l1,l2)->val<<" "<<test.addTwoNumbers(l1,l2)->next->val<<" ";
    cout<<test.addTwoNumbers(l1,l2)->next->next->val;

}
