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


// Level order traversal
// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
vector<int> levelOrder(Node* root)
{
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    while(q.empty() != 1) {
        Node* temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return v;
}

//  Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// 1st method - Using NULL pointer
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> v;
    if(!root)
        return ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    TreeNode* temp;
    while(q.empty() != 1) {
        temp = q.front();
        if(temp == NULL) {
            ans.push_back(v);
            if(q.size() == 1)
                break;
            q.push(NULL);
            v.clear();
            q.pop();
            continue;
        }
        else
            v.push_back(temp->val);
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return ans;
}

// 2nd method - counting nodes in queue at a time
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root)
        return ans;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    while(q.empty() == 0) {
        int n = q.size();
        vector<int> v;
        for(int i=0; i<n; i++) {
            temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        ans.push_back(v);
        v.clear();
    }
    return ans;
}


// Size of Binary Tree
// https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1
int getSize(Node* root)
{
    if(!root)
        return 0;
    return getSize(root->left) + 1 + getSize(root->right);
}

// Max and min element in Binary Tree
// https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1
int findMax(Node *root)
{
    if(!root)
            return INT_MIN;
    return max(root->data, max(findMax(root->left), findMax(root->right)));
}
int findMin(Node *root)
{
    if(!root)
            return INT_MAX;
    return min(root->data, min(findMin(root->left), findMin(root->right)));
}

//  Check for Balanced Tree 


//  Left View of Binary Tree 


//  Right View of Binary Tree 


// Binary Tree to DLL
// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
void inorder(Node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    if(prev == NULL) {
        head = root;
        root->left = prev;
        prev = root;
    }
    else {
        prev->right = root;
        root->left = prev;
        prev = root;
    }
    inorder(root->right);
}

Node* bToDLL(Node *root)
{
    inorder(root);
    return head;
}


// Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
// 1st method - using level order traversal
vector<int> rightSideView(TreeNode* root) {
    vector<int> v;
    if(!root) {
        return v;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(q.empty() == 0) {
        int n = q.size();
        TreeNode *temp;
        for(int i=0; i<n; i++) {
            temp = q.front();
            q.pop();
            if(i == n-1)
                v.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return v;
}

// 2nd method - using recursion and maxLevel variable
int maxLevel = 0;
vector<int> v;
void rightSide(TreeNode* root, int level) {
    if(!root) {
        return;
    }
    if(maxLevel < level) {
        v.push_back(root->val);
        maxLevel = level;
    }
    rightSide(root->right, level+1);
    rightSide(root->left, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    rightSide(root, 1);
    return v;
}

// Vertical Width of a Binary Tree
// https://practice.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1
// Trick - https://youtu.be/uo9Nf2nyvVw?t=393
int val = 0;

void vWidth(Node *root, int val, unordered_set<int> &us) {
    if(!root)
        return;
    us.insert(val);
    vWidth(root->left, val-1, us);
    vWidth(root->right, val+1, us);
}

int verticalWidth(Node* root)
{
    unordered_set<int> us;
    vWidth(root, 0, us);
    return us.size();
}


// Mirror Tree
// https://practice.geeksforgeeks.org/problems/mirror-tree/1
void mirror(Node* root) {
    if(!root)
        return;
    mirror(root->left);
    mirror(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}


// Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
// 1st - Using recursion
bool isSymm(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2)
        return true;
    else if(!root1 || !root2)
        return false;
    if(root1->val != root2->val)
        return false;
    return((root1->val == root2->val) && isSymm(root1->left, root2->right) && isSymm(root1->right, root2->left));
}

bool isSymmetric(TreeNode* root) {
    return isSymm(root->left, root->right);
}

// 2nd - Using level order traversal - queue
void mirror(Node* root)
{
    if (root == NULL)
        return;
  
    queue<Node*> q;
    q.push(root);
  
    // Do BFS. While doing BFS, keep swapping
    // left and right children
    while (!q.empty())
    {
        // pop top node from queue
        Node* curr = q.front();
        q.pop();
  
        // swap left child with right child
        swap(curr->left, curr->right);
  
        // push left and right children
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
