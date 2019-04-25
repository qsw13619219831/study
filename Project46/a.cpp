#include <vector>
#include<iostream>
using namespace std;
#include<stack>
#include<queue>

 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct TreeNode* a;
 struct TreeNode* b;
 struct TreeNode* c;
 struct TreeNode* d;
 struct TreeNode* e;
 struct TreeNode* f;
 struct TreeNode* g;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> fin;
		queue<TreeNode*>q;
		stack<TreeNode*>p;
		q.push(root);
		if (root == NULL){
			return fin;
		}
		int count = 0;
		while (!q.empty()){
			int len = q.size();
			vector<int> mid;
			count++;
			for (int i = 0; i<len; i++){
				TreeNode*tem = q.front();
				q.pop();
				if (count % 2 == 0){
					mid.push_back(tem->val);
				}
				if (count % 2 == 1){
					p.push(tem);
				}
				if (tem->left != NULL){
					q.push(tem->left);
				}
				if (tem->right != NULL){
					q.push(tem->right);
				}
			}
			while (!p.empty()){
				struct TreeNode*tem3 = p.top();
				p.pop();
				mid.push_back(tem3->val);
			}
			fin.push_back(mid);


		}
		return fin;
	}


};
int main(){
	a->val = 3;
	b->val = 9;
	c->val = 20;
	f->val = 15;
	g->val = 7;
	a->left = b;
	a->right = c;
	b->left = NULL;
	b->right = NULL;
	c->left = f;
	c->right = g;
	f->left = NULL;
	f->right = NULL;
	g->left = NULL;
	g->right = NULL;
	Solution sa;
	sa.zigzagLevelOrder(a);

}