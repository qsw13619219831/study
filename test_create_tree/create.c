#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	struct Node*left;
	struct Node*right;
	char val;
} Node;


Node* creattree(char*preorder, int *used, int size){
	
	if (size == 0){
		return NULL;
	}
	if (*preorder == '#'){
		*used = 1;
		return  NULL;
	}
	Node*root = (Node*)malloc(sizeof(Node));
	root->val = *preorder;
	int leftused;
	root->left = creattree(preorder + 1, 
		&leftused, size - 1);
	int rightused;
	root->right = creattree
		(preorder + 1 + leftused,
		&rightused, size - 1 - leftused);

	*used = leftused + rightused + 1;

	return root;

}
char inarr[100] = { 0 }; int inarrsize=0;
void inorder(Node*root){
	if (root == NULL){
		return;
	}
	inorder(root->left);
	inarr[inarrsize++] = root->val;
	inorder(root->right);
}
char postarr[100] = { 0 }; int postarrsize = 0;
void postorders(Node*root){
	if (root == NULL){
		return;
	}
	
	postorders(root->left);
	postorders(root->right);
	postarr[postarrsize++] = root->val;
}
int find(Node*root,char*inarr,int size){
	int i = 0;
	for ( i = 0; i < size; i++){
		
		if (*(inarr + i) == root->val){
			return i;
		}
		
	}
	return -1;
}
Node*creattreeTow(char*prearr, char*inarr, int size){
	if (size == 0){
		return NULL;
	}
	Node*root = (Node*)malloc(sizeof(Node));
	root->val = *prearr;
	int leftsize = find(root, inarr, size);
	root->left = creattreeTow(prearr + 1, inarr, leftsize);
	root->right = creattreeTow(prearr + leftsize + 1, 
		inarr + leftsize + 1, size - leftsize-1);
	return root;
}

Node*creattreeTow2(char*postarr, char*inarr, int size){
	if (size == 0){
		return NULL;
	}
	Node*root = (Node*)malloc(sizeof(Node));
	root->val = *(postarr + (size - 1));
	int leftsize = find(root, inarr, size);
	root->left = creattreeTow2(postarr, inarr, leftsize);
	root->right = creattreeTow2(postarr + leftsize, inarr + leftsize + 1,
		size - leftsize - 1);
	return root;
}
void printpreorder(Node*root){
	if (root == NULL){
		return;
	}
	printf("%c", root->val);
	printpreorder(root->left);
	printpreorder(root->right);
}

int main(){
	char preorder[100]="abd##e##c##";
	int b = 0;
	int a = strlen(preorder);
	Node*aoot = creattree(preorder, &b, a);
	inorder(aoot);
	postorders(aoot);
	printf("%s\n", postarr);
	printf("%s\n", inarr);
	Node*new=creattreeTow2(postarr, inarr, 5);
    printpreorder(new);
	system("pause");
	return 0;
}