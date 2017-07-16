#include<stdio.h>
#include<malloc.h>

//this is the structure for our tree node of red black tree
//data is value of tree node.
//leftchild and rightchild are pointers to their children.
//color stores either red or black.
struct treenode {
	
	int data;
	char *color;
	struct treenode *left;
	struct treenode *right;
	struct treenode *parent; 
};


//this function creates a new node which takes the input value "num" as parameter
//it return *treenode pointer;
//data is asisgned value "num"
//both leftchild and rightchild are assigned NULL;
//initialising color as black, we can assign with red also
//as color of each node is handled while inserting or deleting, 
//so it doesn't matter initial value as red/black.

struct treenode* createNode(int num) {
	struct treenode *ptr;
	ptr = (struct treenode *)malloc(sizeof(struct treenode));
	ptr->data = num;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->parent = NULL;
	
	ptr->color = 'black';
	
	return ptr;
}

struct treenode* binarySearchTreeInsert(struct treenode *root, struct treenode *ptr){
	if(root == NULL){
		return ptr;
	}
	if(ptr->data < root->data){
		root->left = binarySearchTreeInsert(root->left, ptr);
		root->left->parent = root;
	}
	else if(ptr->data > root->data){
		root->right = binarySearchTreeInsert(root->right, ptr);
		root->right->parent = root;
	}
	return root;
}

struct treenode* makeRedBlackTree(struct treenode *root, struct treenode *ptr){
	
}

int main(){
	struct treenode *root = NULL, *ptr;
	int i,j,k,val;
	
	for(i=1;i<=10;i++){
	
		scanf("%d",&val);
		ptr = createNode(val);
		binarySearchTreeInsert(root, ptr);
		makeRedBlackTree(root, ptr);
				
	}
	return ;
}


