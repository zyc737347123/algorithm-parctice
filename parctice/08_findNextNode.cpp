/* **********************
#8. 二叉树的下一个节点
********************** */

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node *father;
};

Node *findNextNode(Node *pNode)
{
    // error: not check pNode

    // node have right child
    if (pNode->right != nullptr)
    {
        pNode = pNode->right;
        while (pNode->left != nullptr)
        {
            pNode = pNode->left;
        }
    }
    else // error : not check father ptr
    {
        if (pNode == pNode->father->left)
        {
            // node not have right child and node is left child
            pNode = pNode->father;
        }
        else
        {
            // node not have right child and node is right child
            Node* pTmp = pNode;
            while(pNode->father != nullptr){
                pNode = pNode->father;
                if(pNode->left == pTmp)
                {
                    break;
                }
                pTmp = pNode;
            }
            pNode = nullptr;
        }
    }

    return pNode;
}

Node* getNext(Node* pNode)
{
    if(pNode == nullptr)
    {
        return nullptr;
    }

    Node* pNext = nullptr;

    if(pNode->right != nullptr)
    {
        Node* pRight = pNode->right;
        pNext = pRight;
        while(pNext->left != nullptr)
        {
            pNext = pNext->left;
        }
    }
    else if(pNode->father != nullptr)
    {
        Node* pCur = pNode;
        Node* pFarther = pNode->father;
        while(pFarther != nullptr && pCur != pFarther->right)
        {
            pCur = pFarther;
            pFarther = pFarther->father;
        }
        pNext = pFarther;
    }

    return pNext;
}
