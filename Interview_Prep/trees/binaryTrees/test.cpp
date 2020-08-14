// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;

    TreeNode (int x){
        val = x;
        left = right = nullptr;
    }
};

void btToDllUtil(TreeNode *root, TreeNode **head){
    if(!root) return;

    btToDllUtil(root->right, head);

    root->right = (*head);

    if(*head)
        (*head)->left = root;
    (*head) = root;

    btToDllUtil(root->left, head);
}

TreeNode *btToDll(TreeNode *root){
    if(!root)   return nullptr;

    TreeNode *head = nullptr;
    btToDllUtil(root, &head);

    return head;
}


void printList(TreeNode *head){
    while(head){
        cout << head->val << " ";
        head = head->right;
    }
}

/* Driver code*/
int main(){
	// Let us create the tree shown in above diagram
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(12);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(30);
	root->right->left = new TreeNode(36);

	TreeNode *head = btToDll(root);
	printList(head);

	return 0;
}
