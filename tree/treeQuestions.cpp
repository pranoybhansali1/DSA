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
class Solution {
    int balance(TreeNode *root) {
        if(!root)
            return 0;
        int lh = balance(root->left);
        if(lh == -1)    return -1;
        int rh = balance(root->right);
        if(rh == -1)    return -1;
        if(abs(lh-rh) > 1)
            return -1;
        else
            return (max(lh, rh) + 1);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        if(balance(root) == -1)
            return 0;
        return 1;
    }
};


// Left View of Binary Tree 
// NB

// Right View of Binary Tree 


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

// Iterative in BFS:
// 1st
public boolean isSymmetric(TreeNode root) {
  if (root == null) {
    return true;
  }
  Queue<TreeNode> queue = new LinkedList<>();
  queue.offer(root.left);
  queue.offer(root.right);

  while (queue.size() > 0) {
    TreeNode t1 = queue.poll();
    TreeNode t2 = queue.poll();
    // check
    if (t1 == null && t2 == null) continue;
    if (t1 == null || t2 == null) return false;
    if (t1.val != t2.val) return false;
    // offer children
    queue.offer(t1.left);
    queue.offer(t2.right);

    queue.offer(t1.right);
    queue.offer(t2.left);
  }
  return true;
}

//2nd
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    queue<nodepair> q;
    q.push(make_pair(root->left, root->right));
    while(!q.empty()){
        nodepair p = q.front();
        q.pop();
        if(!p.first && !p.second) continue;
        if(!p.first || !p.second) return false;
        if(p.first->val != p.second->val) return false;
        q.push(make_pair(p.first->left, p.second->right));
        q.push(make_pair(p.first->right, p.second->left));
    }
    return true;
}

// Iterative in DFS:
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    stack<TreeNode*> sl, sr;
    sl.push(root);
    sr.push(root);
    TreeNode * lp = root->left, *rp = root->right;
    while(lp || ! sl.empty() || rp || !sl.empty()){
        if((!lp && rp) || (lp && !rp)) return false;
        if(lp && rp){
            if(lp->val != rp->val) return false;
            sl.push(lp);
            sr.push(rp);
            lp = lp->left;
            rp = rp->right;
        }else{
            lp = sl.top()->right;
            rp = sr.top()->left;
            sl.pop();
            sr.pop();
        }
    }
    return true;
}


//  Make Binary Tree From Linked List 
// https://practice.geeksforgeeks.org/problems/make-binary-tree/1
void convert(Node *head, TreeNode *&root) {
    root = new TreeNode(head->data);
    TreeNode *curr = root;
    head = head->next;
    queue<TreeNode*> q;
    q.push(curr);
    while(head) {
        curr = q.front();
        q.pop();
        curr->left = new TreeNode(head->data);
        head = head->next;
        if(!head)
            return;
        curr->right = new TreeNode(head->data);
        q.push(curr->left);
        q.push(curr->right);
        head = head->next;
    }
}


// Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
int idx = 0;
TreeNode* tree(vector<int>& pre, vector<int>& in, int is, int ie) {
    if(is > ie)
        return NULL;

    TreeNode *root = new TreeNode(pre[idx++]);
    int inIdx = 0;
    for(int i=is; i<=ie; i++) {
        if(root->val == in[i]) {
            inIdx = i;
            break;
        }
    }
    root->left = tree(pre,in,is,inIdx-1);
    root->right = tree(pre,in,inIdx+1,ie);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    return tree(preorder, inorder, 0, n-1);
}


// Level order traversal in spiral form
// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/
/* Solution - https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/ */
