
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>a;
		if (root == NULL){
			return a;
		}
		queue<TreeNode*>q;
		stack<vector<int>>p;
		q.push(root);
		while (!q.empty()){
			int lenth = q.size();
			vector<int>mid;
			for (int i = 0; i<lenth; i++){
				TreeNode*tem = q.front();
				q.pop();
				mid.push_back(tem->val);
				if (tem->left != NULL){
					q.push(tem->left);
				}
				if (tem->right != NULL){
					q.push(tem->right);
				}

			}
			p.push(mid);

		}
		while (!p.empty()){
			vector<int>cha = p.top();
			p.pop();
			a.push_back(cha);
		}

		return a;
	}
};