#include<stdio.h>
#include<malloc.h>

//Keypoints while thinking algo :-
//1. At every step, think if the current node pointer exists, i.ee it is not NULL
//2. take node by node, like think if n==1 , then  n==2 formulate all cases
//   then n==3, formulate all cases, this way help you design the algorithm yourself. 
//3. take pen and paper and write on paper. 

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
//initialising color as red, as when we inserting a new node
//we are assigning it as "RED", 

struct treenode* createNode(int num) {
	struct treenode *ptr;
	ptr = (struct treenode *)malloc(sizeof(struct treenode));
	ptr->data = num;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->parent = NULL;
	
	ptr->color = 'red';
	
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

//Algorithm Insertion:- 
//1. make the Root as black
//2. if current node is red and its parent is also red then we have double red problem   

struct treenode* makeRedBlackTree(struct treenode *root, struct treenode *ptr){        
	struct treenode *parent_ptr, *grandparent_ptr, *uncle_ptr;
	
	//1. step
	root->color = "black";

	while(1){
		//if current pointer is root, we have reached the root so break form loop
		//or if ptr is NOT root then both ptr and ptr->parent exists
		
		if( (ptr == root) || ptr->color != 'red' || ptr->parent->color != 'red'){
			break;
		}        
		
		parent_ptr = ptr->parent;
		grandparent_ptr = parent->ptr;
		//if uncle is red , only re-coloring is required
		//let's find the uncle pointer.
		if(parent_ptr == grandparent_ptr->left){
			uncle_ptr = grandparent_ptr->right;
		}
		else if(parent_ptr == grandparent_ptr->right){
			uncle_ptr = grandparent_ptr->left;
		}
		
		//if uncle pointer is red, only re-coloring is required 
		//if it i NULL, it is considered as black;
		if(uncle_ptr !=NULL && uncle_ptr->color == 'red'){
			parent_ptr->color = uncle_ptr->color = 'black';
			grandparent_ptr->color = 'red';
			ptr = grandparent_ptr;
		}
		
		else if(uncle_ptr == NULL || uncle_ptr->color == 'black'){
			//Now we need to handle four cases of rotations
			
			//1. If ptr is left sub-child of grandparent 
			if(ptr->parent == grandparent->left){
				
			}
			
			
			//2. If ptr is right sub-child of grandparent
			else if(ptr->parent == grandparent->right){
				
			}
		}
					
	}
	return ;
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


