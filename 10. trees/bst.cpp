/*
    Binary trees:

     1. DFS: (Preorder, Postorder, Inorder(gives sorted data))

     2. BFS or Levelorder Traversal
         -> Levelorder

    degree: number of child nodes
    level: count nodes : 1
    height: count edges : 0    O(logn) to O(n) (skew)

    degree(0) = degree(2)+1

    for n node: ((2*n)C(n))/(n+1) number of trees are possible : catalan number
                : 2^(n-1) trees with maximum height
    (for label nodes multiply n! to above formulas)

    height(h) :h+1 <= n(no. of nodes) <= 2^(h+1) - 1

    nodes(n)  :log2(n+1) -1 <= h(height) <= n-1

    Array Representation: store level wise
                        : i node, 2*i lchild, 2*i+1 rchild, floor(i/2) parent

    Perfect Binary Tree: each node has 2 child and all leaf nodes at same level

    Full/Strict/Proper Binary Tree      : 0 or 2 children only
                                        : 2*h+1 <= n(no. of nodes) <= 2^(h+1) - 1
                                        : external nodes = internal nodes +1

    Complete/Almost-Complete Binary Tree: tree with height(h), completely filled upto height h-1
                        : at height h, nodes are placed to the left so that their is no space btw elements if stored in an array
                        : In a complete binary tree number of nodes at depth d is 2d.

    Balanced Tree: abs(left_height - right_height) =1 or 0 : for each node : AVL trees

    Degenarate or skew tree

    create tree from: pre,in  -> start from left in pre
                    : post,in -> start from right in post
                    : post and pre -> can construct Full Binary Tree and not normal binary tree jenny: see photos
                        (inorder can be calculated explicitly as inorder of BST is sorted array)

    BST:
        no duplicates
        inorder traversal gives sorted data
        for n nodes: ((2*n)C(n))/(n+1)  (bst is always labelled, n! will not be multipled as it would also give non-bst trees)
        creation : O(nlogn)
        insertion: keep a tail pointer that is a slow pointer that inserts node at the end
                : O(logn) to O(n)(for skew tree)    (for single node)
                : O(nlogn) to O(n^2)(for skew tree) (for n nodes)
        deletion: replace the deleted node with either of the two:
                1. inorder predecessor (left then goto extreme right)
                2. inorder successor (right then goto extreme left)
                (if the chosen node has child then apply 1. or 2. on that inorder predecessor/successor as well)
                : O(logn) to O(n)(for skew tree)    (for single node)
                : O(nlogn) to O(n^2)(for skew tree) (for n nodes)
        search time: O(logn) to O(n)(for skew tree)   -> depends on height
        Drawback: no control over height: O(logn) to O(n), depends on order of insertion
                : to overcome this thing we use self balancing trees: that maintain their height: AVL trees

    AVL:

        height(h) (start from 1)
        min nodes: 0(for h=0), 1(for h=1), else N(h-1)+N(h-2)+1 (create a table to calculate)
        max nodes: 2^(h)-1

        nodes(n) -> seetable <= height <= 1.44logn

        height balanced bst
        balance factor = abs(left_height - right_height) =1 or 0
        we perform rotation to balance a tree : LL,LR(first L then R),RL(first R then L),RR
        (rotation is done only on 3 nodes of a bst always, root of these three nodes is the one which first become imbalance)
        insertion: like normal bst: to balance tree after insertion we use rotation
        deletion:
                1. Deletion on right of a node: left tree in imbalanced
                                                L1 rotation (if balance factor of left node is 1) -> R rotation is performed
                                                L-1 rotation (if balance factor of left node is -1)-> LR
                                                L0 rotation (if balance factor of left node is 0) -> R or LR
                2. Deletion on left of a node: right tree in imbalanced
                                                R1 rotation (if balance factor of right node is 1) -> L rotation is performed
                                                R-1 rotation (if balance factor of right node is -1)-> RL
                                                R0 rotation (if balance factor of right node is 0) -> L or RL

    Multiway Trees: M-way:
        : AVL trees with 2-3 trees
        : B tree 2-3 tree: 2 key and 3 child
        : all leaf node at same level, all nodes must have keys/2 number of child
        : insertion: split and insertion
        : deletion: borrow,merge,delete
        height : min log3(n)
                : max log2(n)
        : B- tree: values stored in complete tree
        : B+ tree: values stored in leaf nodes only

    Red Black Tree:
        : AVL trees with color
        : every node is either red or Black
        : root and null-nodes are Black
        : alternate red-black color is present
        : number of black nodes from parent to leaf is same
        : new inserted node must be red
        : logn <= height <= 2logn
        : insertion: like bst
                : inserted node must be red
                : if parent is also red then:
                    1. if uncle of inserted node is also red: recolor all nodes
                    2. if uncle of inserted node is black(null is also black) then perform rotation
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left = NULL, *right = NULL;

    node()
    {
    }
    node(int data)
    {
        this->data = data;
    }
} *root = NULL;

class Tree
{
public:
    /* TREE formation
      void create_tree()
      {
         /*
           create a node root give it's data and left and right child point to null
           take the value for left child if not -1 then create a node and store the value and address in queue
           similarly for right child

         cout << endl;
         node *p, *t;
         int x;
         Queue q;
         cout << "Enter root value : ";
         cin >> x;
         root = new node;
         root->data = x;
         root->left = 0;
         root->right = 0;
         q.enqueue(root);

         while (q.empty() != 0)
         {
             p = q.dequeue();

             cout << "Enter Left Child of " << p->data << ": ";
             cin >> x;
             if (x != -1) // we have to add left child
             {
                 t = new node;
                 t->data = x;
                 t->left = 0;
                 t->right = 0;

                 p->left = t;
                 q.enqueue(t);
             }

             cout << "Enter Right Child of " << p->data << ": ";
             cin >> x;
             if (x != -1) // we have to add right child
             {
                 t = new node;
                 t->data = x;
                 t->left = 0;
                 t->right = 0;

                 p->right = t;
                 q.enqueue(t);
             }
         }
      }
     */

                                                                                        // only for complete tree
     //count nodes for complete tree : Method 1(normal count (count_node() function)), Method 2(when lh=rh then return 2^h +1)
    int leftHeight(node *p)
    {
        if (p == 0)
            return 0;
        return 1 + leftHeight(p->left);
    }
    int rightHeight(node *p)
    {
        if (p == 0)
            return 0;
        return 1 + rightHeight(p->right);
    }
    int countNodesCompleteBinaryTree(node *root)
    {
        if (root == 0)
            return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if (lh == rh)
            return (int)(pow(2, lh) - 1);
        return countNodesCompleteBinaryTree(root->left) + countNodesCompleteBinaryTree(root->right) + 1;
    }

    // number of nodes in tree
    int count_nodes(node *root)
    {
        // O(n) time
        // θ(h+1) == θ(h) space
        if (root == 0)
            return 0;
        return count_nodes(root->left) + count_nodes(root->right) + 1;
    }

    int count_nodes_with_degree0_leaf_nodes(node *p)
    {
        if (p == 0)
            return 0;
        if (p->left == 0 && p->right == 0)
            return count_nodes(p->left) + count_nodes(p->right) + 1;
        else
            return count_nodes(p->left) + count_nodes(p->right);
    }

    int count_nodes_with_degree1(node *p)
    {
        if (p == 0)
            return 0;
        if ((p->left == 0 && p->right != 0) || (p->left != 0 && p->right == 0))
            // as above expression is exclusive or so using exclusive or
            // if (p->left != 0 ^ p->right != 0)
            return count_nodes(p->left) + count_nodes(p->right) + 1;
        else
            return count_nodes(p->left) + count_nodes(p->right);
        ;
    }

    int count_nodes_with_degree2(node *p)
    {
        if (p == 0)
            return 0;
        if (p->left != 0 && p->right != 0)
            return count_nodes(p->left) + count_nodes(p->right) + 1;
        else
            return count_nodes(p->left) + count_nodes(p->right);
    }

    int count_nodes_with_degree1_and_2_both(node *p)
    {
        // all internal nodes
        if (p == 0)
            return 0;
        if (p->left != 0 || p->right != 0)
            return count_nodes(p->left) + count_nodes(p->right) + 1;
        else
            return count_nodes(p->left) + count_nodes(p->right);
        ;
    }

    int sum_of_all_values_in_nodes(node *p)
    {
        if (p == 0)
            return 0;
        return count_nodes(p->left) + count_nodes(p->right) + p->data;
    }

    int findMax(node *p)
    {
        if (root == 0)
            return INT_MIN;
        return max(root->data, max(findMax(root->left), findMax(root->right)));
    }

    void addChild()
    {
        int val;
        cout << "\n-> Enter value to insert: ";
        cin >> val;
        if (root == nullptr)
        {
            root = new node(val);
            return;
        }
        node *it = root, *late = root;

        node *child = new node(val);
        while (it)
        {
            late = it;
            if (it->data == child->data)
            {
                cout << "\n---DUPLICATE VALUE CAN'T INSERT---\n";
                return;
            }
            else if (it->data > child->data)
            {
                it = it->left;
            }
            else if (it->data < child->data)
            {
                it = it->right;
            }
        }
        if ((late->left == 0 && late->right == 0) || (late->left == 0 && late->right != 0))
        {
            late->left = child;
            return;
        }
        else if (late->left != 0 && late->right == 0)
        {
            late->right = child;
            return;
        }
    }

    // Recursion works better for perfect tree
    //  Depth First Traversal
    void recursiveInorder(node *p)
    {
        // for n nodes theie are 2*n+1 calls
        // Time Complexity: θ(n) (exact)       or upper bound  O(n)
        // Aux Space: θ(h) (exact)             or upper boundO(h)     // size of stack : level+1 == height+1
        if (p)
        {
            recursiveInorder(p->left);
            cout << p->data << " ";
            recursiveInorder(p->right);
        }
    }

    //  Depth First Traversal
    void recursivePreorder(node *p)
    {
        // for n nodes their are 2*n+1 calls
        // Time Complexity: θ(n) (exact)       or upper bound  O(n)
        // Aux Space: θ(h) (exact)             or upper bound  O(h)     // size of stack : level+1 == height+1
        if (p)
        {
            cout << p->data << " ";
            recursivePreorder(p->left);
            recursivePreorder(p->right);
        }
    }

    //  Depth First Traversal
    void recursivePostorder(node *p)
    {
        // O(n)
        if (p)
        {
            recursivePostorder(p->left);
            recursivePostorder(p->right);
            cout << p->data << " ";
        }
    }

    // Iterative soln works better for skewed tree as width of tree is least in this and requires less queue space
    // Breadth First Traversal or Levelorder Traversal
    void iterativeLevelOrder()
    {
        if (root == 0)
            return;
        queue<node *> store;
        node *it = root;
        cout << it->data << " ";
        store.push(it);
        while (!store.empty())
        {
            it = store.front();
            store.pop();
            if (it->left)
            {
                cout << it->left->data << " ";
                store.push(it->left);
            }
            if (it->right)
            {
                cout << it->right->data << " ";
                store.push(it->right);
            }
        }
        cout << endl;
    }

    void iterativeReverseLevelOrder()
    {
        if (root == 0)
            return;
        queue<node *> store;
        node *it = root;
        store.push(it);

        stack<int> st;
        st.push(it->data);
        while (!store.empty())
        {
            it = store.front();
            store.pop();
            if (it->left)
            {
                st.push(it->left->data);
                store.push(it->left);
            }
            if (it->right)
            {
                st.push(it->right->data);
                store.push(it->right);
            }
        }
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

    void iterativeInorder(node *p)
    {
        stack<node *> st;
        if (p == nullptr)
            return;
        while (!st.empty() || p)
        {
            if (p)
            {
                st.push(p);
                p = p->left;
            }
            else if (p == nullptr)
            {
                p = st.top();
                st.pop();
                cout << p->data << " ";
                p = p->right;
            }
        }
        cout << endl;
    }

    void iterativePreorder(node *p)
    {
        stack<node *> st;
        if (p == nullptr)
            return;
        while (!st.empty() || p)
        {
            if (p)
            {
                st.push(p);
                cout << p->data << " ";
                p = p->left;
            }
            else if (p == nullptr)
            {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        cout << endl;
    }

    // using two stacks
    void iterativePostorder(node *p)
    {
        if (p == nullptr)
            return;
        stack<node *> st1, st2;
        st1.push(p);
        while (p || !st1.empty())
        {
            node *temp = st1.top();
            st1.pop();
            st2.push(temp);
            if (temp->left)
            {
                st1.push(temp->left);
            }
            if (temp->right)
            {
                st1.push(temp->right);
            }
        }
        while (!st2.empty())
        {
            cout << st2.top()->data << " ";
            st2.pop();
        }
        cout << endl;
    }

    // vertical order traversal
    void verticalTraversal(node *p)
    {
        // x iine concept
        vector<int> ans;
        if (p == 0)
            return;

        // map to store x,y,nodeData_in_sorted_order
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> mp;
        queue<pair<int, pair<int, node *>>> q;
        pair<int, node *> q1 = make_pair(0, p);
        pair<int, pair<int, node *>> q2 = make_pair(0, q1);
        q.push(q2);

        while (!q.empty())
        {
            pair<int, pair<int, node *>> temp1 = q.front();
            q.pop();
            if (temp1.second.second->left)
            {
                pair<int, node *> tempP1 = make_pair(temp1.second.first + 1, temp1.second.second->left);
                pair<int, pair<int, node *>> tempP2 = make_pair(temp1.first - 1, tempP1);
                q.push(tempP2);
            }
            if (temp1.second.second->right)
            {
                pair<int, node *> tempP1 = make_pair(temp1.second.first + 1, temp1.second.second->right);
                pair<int, pair<int, node *>> tempP2 = make_pair(temp1.first + 1, tempP1);
                q.push(tempP2);
            }

            if (mp.find(temp1.first) == mp.end())
            {
                pair<int, int> tempP3 = make_pair(temp1.second.first, temp1.second.second->data);
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
                pq2.push(tempP3);
                mp[temp1.first] = pq2;
            }
            else
            {
                pair<int, int> tempP3 = make_pair(temp1.second.first, temp1.second.second->data);
                mp[temp1.first].push(tempP3);
            }
        }
        for (auto i : mp)
        {
            while (!(i.second.empty()))
            {
                ans.push_back(i.second.top().second);
                i.second.pop();
            }
        }
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // top view
    void topView(node *p)
    {
        // x iine concept
        if (p == 0)
            return;
        map<int, int> mp;
        queue<pair<int, node *>> q;
        q.push({0, p});
        while (!q.empty())
        {
            pair<int, node *> temp1 = q.front();
            q.pop();
            if (temp1.second->left)
            {
                pair<int, node *> p2 = make_pair(temp1.first - 1, temp1.second->left);
                q.push(p2);
            }
            if (temp1.second->right)
            {
                pair<int, node *> p2 = make_pair(temp1.first + 1, temp1.second->right);
                q.push(p2);
            }

            if (mp.find(temp1.first) == mp.end())
            {
                mp[temp1.first] = temp1.second->data;
            }
        }
        for (auto i : mp)
        {
            cout << i.second << " ";
        }
        cout << endl;
    }

    // bottom view
    void bottomView(node *p)
    {
        // x iine concept
        if (p == 0)
            return;
        map<int, int> mp;
        queue<pair<int, node *>> q;
        q.push({0, p});
        while (!q.empty())
        {
            pair<int, node *> temp1 = q.front();
            q.pop();
            if (temp1.second->left)
            {
                pair<int, node *> p2 = make_pair(temp1.first - 1, temp1.second->left);
                q.push(p2);
            }
            if (temp1.second->right)
            {
                pair<int, node *> p2 = make_pair(temp1.first + 1, temp1.second->right);
                q.push(p2);
            }

            // updating all value: last value in linr will be seen from bottom
            mp[temp1.first] = temp1.second->data;
        }
        for (auto i : mp)
        {
            cout << i.second << " ";
        }
        cout << endl;
    }

    // left view
    void solveLeft(node *p, vector<int> &ans, int &maxlevel, int level)
    {
        if (p == 0)
            return;
        if (maxlevel < level)
        {
            ans.push_back(p->data);
            maxlevel = level;
        }
        solveLeft(p->left, ans, maxlevel, level + 1);
        solveLeft(p->right, ans, maxlevel, level + 1);
    }
    void leftView(node *root)
    {
        vector<int> ans;
        int maxlevel = -1;
        solveLeft(root, ans, maxlevel, 0);
        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }

    // right view
    void solveRight(node *p, vector<int> &ans, int &maxlevel, int level)
    {
        if (p == 0)
            return;
        if (maxlevel < level)
        {
            ans.push_back(p->data);
            maxlevel = level;
        }
        solveRight(p->right, ans, maxlevel, level + 1);
        solveRight(p->left, ans, maxlevel, level + 1);
    }
    void rightView(node *root)
    {
        vector<int> ans;
        int maxlevel = -1;
        solveRight(root, ans, maxlevel, 0);
        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }

    vector<int> zigZagLevelorderTraversal(node *root)
    {
        vector<int> ans;
        if (root == 0)
            return ans;
        bool change = false;
        queue<node *> q;
        stack<int> st;
        q.push(root);
        q.push(0);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp == 0)
            {
                if (change)
                {
                    while (!st.empty())
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
                change = !change;
                if (!q.empty())
                    q.push(0);
            }
            else
            {
                if (change)
                {
                    st.push(temp->data);
                }
                else
                {
                    ans.push_back(temp->data);
                }
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }

    // Boundary nodes : left+leaf+right nodes
    /*iterative leftNodes and iterative rightNodes
     void leftNodes(Node* root, vector<int>&v){
        while(root){
         if(root->left || root->right)  v.push_back(root->data); //not leaf
         if(root->left) root=root->left;
         else root=root->right;
        }
     }
     void rightNodes(Node* root,vector<int>& v){
        vector<int>temp;
         while(root){
          if(root->left || root->right)  temp.push_back(root->data); //not leaf
          if(root->right) root=root->right;
          else root=root->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            v.push_back(temp[i]);
        }
     }
    */
    void leftNodes(node *root, vector<int> &v)
    {
        if (root == 0)
            return;
        if (!root->left && !root->right)
            return;
        if (root->left)
        {
            v.push_back(root->data);
            leftNodes(root->left, v);
        }
        else if (root->right)
        {
            v.push_back(root->data);
            leftNodes(root->right, v);
        }
    }
    void leafNodes(node *root, vector<int> &v)
    {
        if (root == 0)
            return;
        if (root->left == 0 && root->right == 0)
            v.push_back(root->data);
        leafNodes(root->left, v);
        leafNodes(root->right, v);
    }
    void rightNodes(node *root, vector<int> &v)
    {
        if (root == 0)
            return;
        if (!root->left && !root->right)
            return;
        if (root->right)
        {
            rightNodes(root->right, v);
            v.push_back(root->data);
        }
        else if (root->left)
        {
            rightNodes(root->left, v);
            v.push_back(root->data);
        }
    }
    void boundary(node *root)
    {
        vector<int> ans;
        if (root == 0)
            cout << "EMPTY";
        ans.push_back(root->data);
        if (!root->left && !root->right)
            cout << ans[0];
        leftNodes(root->left, ans); // to avoide rooot node
        leafNodes(root, ans);
        rightNodes(root->right, ans); // to avoide rooot node
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // check if two nodes are siblings or not in bst with unique node values
    bool isCousins(node *root, int x, int y)
    {
        // nodes at same level with different parents are called cousins, nodes at same level with same parents are called sibling
        queue<pair<node *, int>> q;
        q.push({root, 0});
        unordered_map<int, pair<node *, int>> mp; // value_of_child_node,{parent_node,level_of_child_node}
        mp[root->data] = make_pair(root, 0);
        while (!q.empty())
        {
            node *temp = q.front().first;
            if (temp->left)
            {
                mp[temp->left->data] = make_pair(temp, q.front().second + 1);
                q.push({temp->left, q.front().second + 1});
            }
            if (temp->right)
            {
                mp[temp->right->data] = make_pair(temp, q.front().second + 1);
                q.push({temp->right, q.front().second + 1});
            }
            q.pop();
        }
        if (mp.find(x) != mp.end() && mp.find(y) != mp.end() && mp[x].first != mp[y].first && mp[x].second == mp[y].second)
            return true;
        return false;
    }

    // root to all leaf paths
    void solvePath(node *p, vector<int> sample, vector<vector<int>> &ans)
    {
        if (p == 0)
            return;
        sample.push_back(p->data);
        if (p->left == 0 && p->right == 0)
        {
            ans.push_back(sample);
            return;
        }
        solvePath(p->left, sample, ans);
        solvePath(p->right, sample, ans);
    }
    vector<string> binaryTreePaths(node *root)
    {
        vector<string> ans2;
        vector<vector<int>> ans1;
        vector<int> sample;
        solvePath(root, sample, ans1);
        string x = "";
        for (vector<int> i : ans1)
        {
            for (int j = 0; j < i.size(); j++)
            {
                if (i[j] < 0)
                    x += "-", i[j] = abs(i[j]);
                string y = "";
                while (i[j])
                {
                    y += (i[j] % 10 + 48);
                    i[j] /= 10;
                }
                reverse(y.begin(), y.end());
                x += y;
                if (j != i.size() - 1)
                {
                    x += "->";
                }
            }
            ans2.push_back(x);
            x = "";
        }
        return ans2;
    }

    // ceil value of 'input'
    int findCeil(node *root, int input)
    {
        int ans = -1;
        while (root)
        {
            if (input == root->data)
                return input;
            if (input > root->data)
            {
                root = root->right; // searching for bigger valur than "input" valur
            }
            else if (input < root->data)
            {
                ans = root->data;
                root = root->left; // searching for lower value than input->data
            }
        }
        return ans;
    }

    // floor value of 'input'
    int findFloor(node *root, int input)
    {
        int ans = -1;
        while (root)
        {
            if (input == root->data)
                return input;
            if (input > root->data)
            {
                ans = root->data;
                root = root->right; // searching for bigger valur than "input" valur
            }
            else if (input < root->data)
            {
                root = root->left; // searching for lower value than input->data
            }
        }
        return ans;
    }

    // search for a key in bst
    bool search(int key)
    {
        node *it = root;
        while (it)
        {
            if (it->data == key)
                return true;
            else if (it->data > key)
                it = it->left;
            else if (it->data < key)
                it = it->right;
        }
        return false;
    }

    int height(node *p)
    {
        // A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
        //  for n nodes theie are 2*n+1 calls
        //  Time Complexity: θ(n) (exact)       or upper bound  O(n)
        //  Aux Space: θ(h) (exact)             or upper boundO(h)     // size of stack : level+1 == height+1

        int x = 0, y = 0;
        if (p == 0)
            return 0; // considering height as max no. of nodes from root to leaf

        x = height(p->left);  // returns height of left subtree
        y = height(p->right); // returns height of right subtree

        int h = max(x, y); // getting max height from left and right subtree
        return h + 1;      // adding current node to the the max height
    }

    // check for balanced tree
    int check(node *root, bool &ans)
    {
        if (root == 0)
            return 0;
        int x = check(root->left, ans);
        int y = check(root->right, ans);
        if (abs(x - y) > 1)
            ans = false;
        return max(x, y) + 1;
    }
    void isBalanced(node *root)
    {
        bool ans = true;
        check(root, ans);
        if (ans)
            cout << "-> Balanced!!!\n";
        else
            cout << "-> Not Balanced!!!\n";
    }

    // Diameter of tree: max number of nodes between longest path of two leaf nodes
    int diameteHeight(node *root, int &diameter)
    {
        if (root == 0)
            return 0;
        int x = diameteHeight(root->left, diameter);
        int y = diameteHeight(root->right, diameter);
        // diameter is left-height+ right-height+1(of root node) of a root node -> x+y+1
        diameter = max(diameter, x + y + 1);
        return max(x, y) + 1;
    }
    void diameterOfBinaryTree(node *root)
    {
        int diameter = 0;
        diameteHeight(root, diameter);
        cout << "-> Diameter is: " << diameter << endl;
    }

    // Width of a binary tree is max no. of nodes at a particular level

    // maxPathSum
    int solveSum(node *root, int &ans)
    {
        if (root == 0)
            return 0;
        int x = max(0, solveSum(root->left, ans)); // max(0,...) to counter negative values
        int y = max(0, solveSum(root->right, ans));
        ans = max(ans, x + y + root->data);
        return max(x, y) + root->data;
    }
    int maxPathSum(node *root)
    {
        int ans = INT_MIN;
        solveSum(root, ans);
        return ans;
    }

    // Least Common Ancestor
    node *lowestCommonAncestor(node *root, node *p, node *q)
    {
        if (root == 0 || root == p || root == q)
            return root;
        node *l = lowestCommonAncestor(root->left, p, q);
        node *r = lowestCommonAncestor(root->right, p, q);
        if (l == 0)
            return r;
        else if (r == 0)
            return l;
        else if (l != 0 && r != 0)
            return root; // both left and right have some value: root is the LCA
    }

    // width of tree: distance between tow nodes at extreme positions on same level
    int widthOfBinaryTree(node *root)
    {
        if (!root)
            return 0;
        long long width = 0;
        queue<pair<node *, long long>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            long long mmin = q.front().second;
            long long first, last;
            for (int i = 0; i < size; i++)
            {
                long long curr_id = q.front().second - mmin;
                node *p = q.front().first;
                q.pop();

                if (p->left)
                    q.push({p->left, (2 * curr_id) + 1});
                if (p->right)
                    q.push({p->right, (2 * curr_id) + 2});

                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;
            }
            width = max(width, last - first + 1);
        }
        return width;
    }

    // check symmetry (mirror image in tree)
    void solveLeft(node *p, vector<int> &v)
    {
        if (p == 0)
        {
            v.push_back(INT_MIN); // to handel null nodes
            return;
        }
        v.push_back(p->data);
        solveLeft(p->left, v);
        solveLeft(p->right, v);
    }
    void solveRight(node *p, vector<int> &v)
    {
        if (p == 0)
        {
            v.push_back(INT_MIN); // to handel null nodes
            return;
        }
        v.push_back(p->data);
        solveRight(p->right, v);
        solveRight(p->left, v);
    }
    void isSymmetric(node *root)
    {
        vector<int> leftV;
        vector<int> rightV;
        solveLeft(root->left, leftV);
        solveRight(root->right, rightV);
        if (leftV.size() != rightV.size())
        {
            cout << "Mirror Image Does Not Exits!!\n";
            return;
        }
        for (int i = 0; i < leftV.size(); i++)
        {
            if (leftV[i] != rightV[i])
            {
                cout << "Mirror Image Does Not Exits!!\n";
                return;
            }
        }
        cout << "Mirror Image Exits!!\n";
    }
    // check if two tree are same
    bool isSameTree(node *p, node *q)
    {
        if (p == 0 && q == 0)
            return true;
        if (p == 0)
            return false;
        if (q == 0)
            return false;
        bool value = (p->data == q->data);
        bool leftTree = isSameTree(p->left, q->left);
        bool rightTree = isSameTree(p->right, q->right);
        return value && leftTree && rightTree;
    }

    // root->data==(root->left->data+root->right->data)
    int isSumProperty(node *root)
    {
        if (root == 0)
            return true;
        if (root->left == 0 && root->right == 0)
            return true;
        int sum = 0;
        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;
        return (root->data == sum) && isSumProperty(root->left) && isSumProperty(root->right);
    }

    // form tree such that for each node: (node->data==node->left->data+node->left->data) : have the option to increase each node by any value any number of times but no decrement allowed
    void childrenSumProperty(node *root)
    {
        if (root == 0)
            return;
        int child = 0;
        if (root->left)
            child += root->left->data;
        if (root->right)
            child += root->right->data;
        if (child >= root->data)
            root->data = child;
        else
        {
            if (root->left)
                root->left->data = child;
            if (root->right)
                root->right->data = child;
        }
        childrenSumProperty(root->left);
        childrenSumProperty(root->right);
        int sumForRoot = 0;
        if (root->left)
            sumForRoot += root->left->data;
        if (root->right)
            sumForRoot += root->right->data;
        if (root->right || root->left)
            root->data = sumForRoot;
    }

    // all nodes at k distance from target node
    queue<node *> q;
    unordered_map<node *, node *> parentTrack;
    unordered_map<node *, bool> visited;
    node *targetNode = NULL;
    void parent(node *root)
    {
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root->left)
            {
                q.push(root->left);
                parentTrack[root->left] = root;
            }
            if (root->right)
            {
                q.push(root->right);
                parentTrack[root->right] = root;
            }
        }
    }
    void getTargetNode(node *root, int target)
    {
        if (root == NULL)
            return;
        if (target == root->data)
        {
            targetNode = root;
            return;
        }
        getTargetNode(root->left, target);
        getTargetNode(root->right, target);
    }
    vector<int> KDistanceNodes(node *root, int target, int k)
    {
        // return the sorted vector of all nodes at k dist
        int curr_level = 0;

        // target node
        getTargetNode(root, target);

        // we got the parent track
        parent(root);

        q.push(targetNode);
        while (!q.empty())
        {
            int n = q.size();
            if (k == curr_level)
                break;
            for (int i = 0; i < n; ++i)
            {
                node *curr = q.front();
                q.pop();
                visited[curr] = true;

                // left
                if (curr->left && visited[curr->left] == false)
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // right
                if (curr->right && visited[curr->right] == false)
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // parent
                if (parentTrack[curr] && visited[parentTrack[curr]] == false)
                {
                    visited[parentTrack[curr]] = true;
                    q.push(parentTrack[curr]);
                }
            }
            curr_level++;
        }

        vector<int> ans;
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            ans.push_back(root->data);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // burn tree
    void get_parent(node *root, unordered_map<node *, node *> &parent, queue<node *> q)
    {
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    void getTargetNode(node *root, int target, node *targetNode)
    {
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *x = q.front();
            q.pop();
            if (x->data == target)
            {
                targetNode = x;
                break;
            };
            if (x->left)
            {
                q.push(x->left);
            }
            if (x->right)
            {
                q.push(x->right);
            }
        }
    }
    int minTime(node *root, int target)
    {
        int ans = 0;
        unordered_map<node *, node *> parent;
        queue<node *> q;
        get_parent(root, parent, q);
        node *targetNode = NULL;
        getTargetNode(root, target, targetNode);
        unordered_map<node *, bool> visited;
        // target-node node is set to fire // time==0
        visited[targetNode] = true;
        q.push(targetNode);

        while (!q.empty())
        {
            int size = q.size();
            bool burnedAnyOne = false;
            for (int i = 0; i < size; i++)
            {
                node *temp = q.front();
                q.pop();

                // can burn parent
                if (parent.find(temp) != parent.end() && !visited[parent[temp]])
                {
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                    burnedAnyOne = true;
                }

                // can burn left child
                if (temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                    burnedAnyOne = true;
                }

                // can burn right child
                if (temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                    burnedAnyOne = true;
                }
            }
            if (burnedAnyOne == true)
                ans++;
        }
        return ans;
    }

    // inorder and preorder tree
    node *constructTreePre(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        node *root = new node(preorder[preStart]);
        int elem = mp[root->data];
        int nElem = elem - inStart;

        root->left = constructTreePre(preorder, preStart + 1, preStart + nElem, inorder,
                                      inStart, elem - 1, mp);
        root->right = constructTreePre(preorder, preStart + nElem + 1, preEnd, inorder,
                                       elem + 1, inEnd, mp);

        return root;
    }
    node *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        map<int, int> mp;
        for (int i = 0; i < preorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return constructTreePre(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }

    // inorder and postorder tree
    node *constructTreePost(vector<int> in, int inStart, int inEnd, vector<int> post, int postStart, int postEnd, map<int, int> &inMap)
    {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        node *root = new node(post[postEnd]);
        int inRoot = inMap[root->data];
        int inLeft = inRoot - inStart;

        root->left = constructTreePost(in, inStart, inRoot - 1, post, postStart, postStart + inLeft - 1, inMap);
        root->right = constructTreePost(in, inRoot + 1, inEnd, post, postStart + inLeft, postEnd - 1, inMap);
        return root;
    }
    node *buildTreePost(vector<int> in, vector<int> post)
    {
        map<int, int> inMap;

        for (int i = 0; i < in.size(); i++)
        {
            inMap[in[i]] = i;
        }

        node *root = constructTreePost(in, 0, in.size() - 1, post, 0, post.size() - 1, inMap);
        return root;
    }

    // serialize and deserialize tree
    string serialize(node *root)
    {
        if (!root)
            return "";

        string s = "";
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *curNode = q.front();
            q.pop();
            if (curNode == NULL)
                s.append("#,");
            else
                s.append(to_string(curNode->val) + ',');
            if (curNode != NULL)
            {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    node *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        node *root = new node(stoi(str));
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {

            node *node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                node *leftNode = new node(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                node *rightNode = new node(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
    // in bst
    // flatten tree to form linked list
    node *prev = NULL;
    void flatten(node *root)
    {
        if (root == 0)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
        // root is head of linked list formed   //right skewed tree formed
    }

    // insert into bst
    node *insertIntoBST(node *root, int val)
    {
        node *temp = new node(val);
        if (root == 0)
            return temp;
        node *p = root;
        while (root)
        {
            if (root->data > val)
            {
                if (root->left == 0)
                {
                    root->left = temp;
                    return p;
                }
                else
                    root = root->left;
            }
            else
            {
                if (root->right == 0)
                {
                    root->right = temp;
                    return p;
                }
                else
                    root = root->right;
            }
        }
        return p;
    }

    // kth largest:   inorder of bst gives sorted list
    void solve1(node *root, int &k)
    {
        if (root == NULL)
            return;
        solve1(root->right, k);
        k--;
        if (k == 0)
        {
            ans = root;
            return;
        }
        solve1(root->left, k);
    }
    int kthLargest(node *root, int k)
    {
        if (root == 0)
            return -1;
        solve1(root, k);
        return ans->data;
    }

    // kth smallest:   inorder of bst gives sorted list
    node *ans;
    void solve2(node *root, int &k)
    {
        if (root == NULL)
            return;
        solve2(root->left, k);
        k--;
        if (k == 0)
        {
            ans = root;
            return;
        }
        solve2(root->right, k);
    }
    int kthSmallest(node *root, int k)
    {
        if (root == 0)
            return -1;
        solve2(root, k);
        return ans->data;
    }

    // delete node in bst
    node *findLastRight(node *root)
    {
        if (root->right == 0)
            return root;
        return findLastRight(root->right);
    }
    node *helper(node *root)
    {
        if (root->left == 0)
            return root->right;
        else if (root->right == 0)
            return root->left;
        node *rightChild = root->right;
        node *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    node *deleteNode(node *root, int key)
    {
        if (root == 0)
            return root;
        if (root->data == key)
            return helper(root); // delete root node

        node *temp = root;
        while (temp != NULL)
        {
            if (temp->data > key)
            {
                if (temp->left && temp->left->data == key)
                {
                    temp->left = helper(temp->left);
                    break;
                }
                else
                    temp = temp->left;
            }
            else if (temp->data <= key)
            {
                if (temp->right && temp->right->data == key)
                {
                    temp->right = helper(temp->right);
                    break;
                }
                else
                    temp = temp->right;
            }
        }
        return root;
    }
};

int main()
{
    Tree obj;

    int choice;
    while (1)
    {
        cout << "\nEnter 0(To Add Child), 1(Recursive-Inorder), 2(Recursive-Preorder), 3(Recursive-Postorder), 4(Iterative Levelorder), , 5(Iterative Inorder), 6(Iterative Preorder), 7(Iterative Postorder) ,8(Search), 9(Height or Depth), 100(exit): ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            obj.addChild();
            break;
        case 1:
            cout << "\n-> Recursive Inorder Traversal: ";
            obj.recursiveInorder(root);
            cout << endl;
            break;
        case 2:
            cout << "\n-> Recursive Preorder Order Traversal: ";
            obj.recursivePreorder(root);
            cout << endl;
            break;
        case 3:
            cout << "\n-> Recursive Postorder Order Traversal: ";
            obj.recursivePostorder(root);
            cout << endl;
            break;
        case 4:
            cout << "\n-> Iterative Level Order Traversal: ";
            obj.iterativeLevelOrder();
            break;
        case 5:
            cout << "\n-> Iterative Reverse Level Order Traversal: ";
            obj.iterativeReverseLevelOrder();
            break;
        case 6:
            cout << "\n-> Iterative Inorder Traversal: ";
            obj.iterativeInorder(root);
            break;
        case 7:
            cout << "\n-> Iterative Preorder Traversal: ";
            obj.iterativePreorder(root);
            break;
        case 8:
            cout << "\n-> Iterative Postorder Traversal: ";
            obj.iterativePostorder(root);
            break;
        case 9:
            cout << "\n-> Enter key to search: ";
            int key;
            cin >> key;
            if (obj.search(key))
                cout << "   FOUND!!!\n";
            else
                cout << "   NOT FOUND!!!\n";
            break;
        case 10:
            cout << "\n-> Height or Depth of Binary tree: ";
            obj.height(root);
            break;
        case 11:
            cout << "\n-> Balanced Tree or Not: ";
            obj.isBalanced(root);
            break;
        case 12:
            cout << "\n-> Diameter or Width: ";
            obj.diameterOfBinaryTree(root);
            break;
        case 13:
            cout << "\n-> Max Path Sum: ";
            obj.maxPathSum(root);
            break;
        case 14:
            cout << "\n-> ZigZag Levelorder Traversal: ";
            obj.zigZagLevelorderTraversal(root);
            break;
        case 15:
            cout << "\n-> Boundary Traversal: ";
            obj.boundary(root);
            break;
        case 16:
            cout << "\n-> Vertical Order Traversal: ";
            obj.verticalTraversal(root);
            break;
        case 17:
            cout << "\n-> Top View: ";
            obj.topView(root);
            break;
        case 18:
            cout << "\n-> Top View: ";
            obj.bottomView(root);
            break;
        case 19:
            cout << "\n-> Left View: ";
            obj.leftView(root);
            break;
        case 20:
            cout << "\n-> Right View: ";
            obj.rightView(root);
            break;
        case 21:
            cout << "\n-> Is Tree Symetric: ";
            obj.isSymmetric(root);
            break;
        case 22:
            int x, y;
            cout << "\n-> Enter first node value: ";
            cin >> x;
            cout << "\n-> Enter second node value: ";
            cin >> y;
            cout
                << "\n-> Is Tree Symetric: ";
            cout << obj.isCousins(root, x, y) << endl;
            break;
        case 100:
            exit(0);
        }
    }
    return 0;
}
y