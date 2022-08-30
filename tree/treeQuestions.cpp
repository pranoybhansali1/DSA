// If trees are identical / Same tree
// https://leetcode.com/problems/same-tree/

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL)
        return true;
    if(p==NULL || q==NULL)
        return false;
    if(p->val == q->val)
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    else
        return false;
}

// Children Sum Parent
// https://practice.geeksforgeeks.org/problems/children-sum-parent/1

int isSumProperty(Node *root)
{
    int sum = 0;
    if(!root)
        return 1;
    if(!root->left && !root->right)
        return 1;
    if(root->left && root->right)
        sum = root->left->data + root->right->data;
    else {
        Node *temp = root->left ? root->left : root->right;
        sum = temp->data;
    }
    if(sum != root->data)
        return 0;
    return ((sum == root->data) && isSumProperty(root->left) && isSumProperty(root->right));
}

// K distance from root
// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1

void KdistanceUtil(struct Node *root, int k) {
    if(root == NULL)
        return;
    if(k == 0) {
        ans.push_back(root->data);
        return;
    }
    KdistanceUtil(root->left, k-1);
    KdistanceUtil(root->right, k-1);
    return;
}
