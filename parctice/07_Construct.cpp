/********************* 
#7. 重建二叉树
关键思路：
**********************/

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    
    return ConstructCore(preorder, preorder + length - 1 , inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPre, int* endPre, int* startIn, int* endIn)
{
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = startPre[0];
    root->pLeft = root->pRight = nullptr;

    // 叶子节点
    if(startPre == endPre && *startPre == *startIn)
        return root;

    int *rootIn = startIn;
    while (rootIn <= endIn && *rootIn != root->value)
    {
        rootIn++;
    }

    int leftLength = rootIn - startIn;
    int *leftPreEnd = startPre + leftLength;
    
    if(leftLength > 0)
    {
        root->pLeft = ConstructCore(startPre + 1, leftPreEnd, startIn, rootIn - 1);
    }
    if(leftLength < endPre - startPre)
    {
        root->pRight = ConstructCore(leftPreEnd + 1, endPre, rootIn + 1, endIn);
    }

    return root;
}