#include <stdio.h>
#include <stdlib.h>
#define abs(a) (a>=0? a : -(a))

struct tnode {
	int val;
	int row; int col;
	struct tnode *left; struct tnode *right;
};

struct tnode * newNode(int val,int row,int col);
void insertTree(struct tnode *root,int val, int row, int col);
void printSortedTree(struct tnode *root);
void findTree(struct tnode *root,int val,struct tnode * closest);
void freeTree(struct tnode *root);

int main(int argc, char **argv) {
	int mat[3][5]={{31,45,12,16,44},{98,75,13,42,11},{6,14,50,10,81}};

	if (argc!=2) {
		printf("Invoke as %s <value>\n",argv[0]);
		return 0;
	}
	struct tnode *root=newNode(mat[0][0],0,0);
	int row;
	for(row=0;row<3;row++) {
		int col;
		for(col=0;col<5;col++) {
			insertTree(root,mat[row][col],row,col);
		}
	}
	printSortedTree(root);
	int lost=atoi(argv[1]);
	findTree(root,lost,NULL);
	freeTree(root);
	return 0;
}

struct tnode * newNode(int val,int row,int col) {
	struct tnode * new = (struct tnode *)malloc(sizeof(struct tnode));
	new->val=val;
	new->row=row; new->col=col;
	new->left=NULL; new->right=NULL;
	return new;
}

void insertTree(struct tnode *root,int val, int row, int col) {
	if (val==root->val) return; // Don't insert a value that's already there
	if (val < root->val) {
		if (root->left==NULL) root->left=newNode(val,row,col);
		else insertTree(root->left,val,row,col);
	} else { // must be val>root->val
		if (root->right==NULL) root->right=newNode(val,row,col);
		else insertTree(root->right,val,row,col);
	}
}

void printSortedTree(struct tnode *root) {
	if (root->left) printSortedTree(root->left);
	printf("  mat[%d][%d] = %3d\n",root->row,root->col,root->val);
	if (root->right) printSortedTree(root->right);
}

void findTree(struct tnode *root,int val,struct tnode * closest) {
	if (closest==NULL) closest=root;
	if (val==root->val) {
		printf("Value %d is in mat[%d][%d]\n",val,root->row,root->col);
		return;
	}
	if (abs(val-root->val)<abs(val-closest->val)) {
		closest=root;
	}
	if (val<root->val) {
		if (root->left==NULL) {
			printf("Closest value to %d is in mat[%d][%d]=%d\n",
				val,closest->row,closest->col,closest->val);
			return;
		}
		findTree(root->left,val,closest);
	} else {
		if (root->right==NULL) {
			printf("Closest value to %d is in mat[%d][%d]=%d\n",
				val,closest->row,closest->col,closest->val);
			return;
		}
		findTree(root->right,val,closest);
	}
}

void freeTree(struct tnode *root) {
	if (root->left) freeTree(root->left);
	if (root->right) freeTree(root->right);
	free(root);
}