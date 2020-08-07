/*
    print Nodes at K distance
    leetcode : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

    reference :
        BFS approach : https://www.youtube.com/watch?v=nPtARJ2cYrg&feature=youtu.be
        DFS approach : https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};


// ========================================= BFS Approach =========================== //
// tc : O(n+m), nodes + edges
// sc : )(n), nodes
vector<int> nodesAtKthDistanceII(TreeNode *target, int k, unordered_map<TreeNode *, TreeNode *> &np ){
    int lvl = 0;

    unordered_map<TreeNode *, bool> visited;
    vector<int> result;
    queue<TreeNode *> q;

    q.push(target);

    while(!q.empty()){
        if(lvl == k){
            while(!q.empty()){
                if(q.front())
                    result.push_back((q.front())->val);
                q.pop();
            }

            break;
        }

        queue<TreeNode *> temp;
        while(!q.empty()){
            TreeNode *t = q.front();
            if(t){
               visited[t] = true;

                if(t->left != nullptr && !visited.count(t->left)){
                    temp.push(t->left);
                }
                if(t->right != nullptr && !visited.count(t->right)){
                    temp.push(t->right);
                }
                if(!visited.count(np[t])){
                    temp.push(np[t]);
                    visited[np[t]] = true;
                }
            }

            q.pop();
        }

        q = temp;
        lvl++;
    }

    return result;
}

void findParent(TreeNode *root, TreeNode *parent, unordered_map<TreeNode *, TreeNode *> &nodesParents){
    if(!root)   return ;

    nodesParents[root] = parent;        // assings parent to each node

    findParent(root->left, root, nodesParents);
    findParent(root->right, root, nodesParents);
}

vector<int> distanceKII(TreeNode* root, TreeNode* target, int K) {
    unordered_map<TreeNode *, TreeNode *> nodesParents;
    findParent(root, nullptr, nodesParents);
    return nodesAtKthDistanceII(target, K, nodesParents);
}


//===============================  DFS Approach ====================== //
// tc : O(n), nodes
// sc : O(1)
void nodesAtKthDistanceDown(TreeNode *root, int k, vector<int> &result){
    if(root == nullptr || k < 0)    return ;

    if(k == 0)
        result.push_back(root->val);

    nodesAtKthDistanceDown(root->left, k-1, result);
    nodesAtKthDistanceDown(root->right, k-1, result);
}

int nodesAtKthDistance(TreeNode *root, TreeNode *target, int k, vector<int> &result){
    if(root == nullptr)    return -1;

    if(root == target){
        nodesAtKthDistanceDown(root, k, result);
        return 0;
    }

    int leftDistance = nodesAtKthDistance(root->left, target, k, result);

    if(leftDistance != -1){
        if(leftDistance + 1 == k)
            result.push_back(root->val);
        else
            nodesAtKthDistanceDown(root->right, k-leftDistance-2, result);


        return (leftDistance+1);
    }

    int rightDistance = nodesAtKthDistance(root->right, target, k, result);
    if(rightDistance != -1){
        if(rightDistance + 1 == k)
            result.push_back(root->val);
        else
            nodesAtKthDistanceDown(root->left, k-rightDistance-2, result);

        return (rightDistance+1);
    }

    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
    vector<int> result;
    nodesAtKthDistance(root, target, K, result);
    return result;
}

// Driver function
int main(){
    TreeNode * root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    // Node *root = new Node(0);
    // root->left = new Node(1);
    // root->right = new Node(3);
    // root->left->right = new Node(2);
    // root->right->right->left = new Node(4);

    // inorderTraversal(root);
    // cout << "\n\n";

    TreeNode * target = root->left->right;
    int K = 2;

    for(auto i:distanceK(root, target, K))
        cout << i << " ";
    cout << endl;

    return 0;
}
