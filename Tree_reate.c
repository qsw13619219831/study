
//从前序与中序遍历序列构造二叉树
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if (preorderSize <= 0){
		return NULL;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = *preorder;
	int i = 0;
	for (; i<inorderSize; i++){
		if (inorder[i] == root->val){
			break;
		}
	}

	int leftSize = i;
	root->left = buildTree(preorder + 1, leftSize, inorder, leftSize);
	root->right = buildTree(preorder + leftSize + 1, preorderSize - leftSize - 1, inorder + leftSize + 1,
		preorderSize - leftSize - 1);
	return root;

}
//从中序与后序遍历序列构造二叉树
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	if (postorderSize <= 0){
		return NULL;
	}
	struct TreeNode*root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = postorder[postorderSize - 1];
	int i = 0;
	for (; i<inorderSize; i++){
		if (inorder[i] == root->val){
			break;
		}
	}
	int leftSize = i;
	root->left = buildTree(inorder, inorderSize, postorder, leftSize);
	root->right = buildTree(inorder + leftSize + 1, inorderSize - leftSize - 1, postorder + leftSize, postorderSize - leftSize - 1);

	return root;
}