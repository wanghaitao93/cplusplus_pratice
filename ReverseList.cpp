#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
};

void createList(ListNode* L, int n)
{
    cin>>L->value;
    n--;
    for (int i = 0; i < n; i++)
    {
        ListNode *p = new ListNode;
        cin>>p->value;
        p->next = NULL;
        L->next = p;
        L = p;
    }
}

void Print(ListNode* head)
{
    ListNode* pNode = head;
    while(pNode)
    {
        cout<<pNode->value;
        pNode = pNode->next;
    }
    cout<<endl;
}

ListNode* reverseList(ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;
    
    ListNode* p = head;
    ListNode* q = head->next;
    ListNode* r = NULL;
    head->next = nullptr;
    
    while(q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}

int main()
{
    ListNode *head = new ListNode;
    createList(head, 5);
    Print(head);
    head = reverseList(head);
    Print(head);
    return 1;
}
