/********************* 
#6. 从尾到头打印链表
**********************/

#include <stack>

struct ListNode
{
    int value;
    ListNode* next;
};

void PrintListReversingly_Iter(ListNode* pHead)
{
    std::stack<ListNode*> s;
    
    while (pHead)
    {
        s.push(pHead);
        pHead = pHead->next;
    }

    while (!s.empty())
    {
        s.top()->value;
        s.pop();
    }
    
}

void PrintListReversingly_Recu(ListNode* pHead)
{
    if(pHead == nullptr)
        return;

    PrintListReversingly_Recu(pHead->next);

    printf("%d", pHead->value);
}


ListNode* ReversList(ListNode* pHead)
{
    ListNode *pPre = nullptr, *pCur = nullptr, *pNext = nullptr;

    pPre = pHead;
    pCur = pPre->next;

    while (pCur)
    {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }

    pHead->next = nullptr;
    return pPre;
}