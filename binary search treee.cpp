#include<iostream>
using namespace std;

struct node{
	int data;
	node*leftchild;
	node*rightchild;
	 
	 node(int val){
	 	data=val;
	 	leftchild=NULL;
	 	rightchild=NULL;
	 }
};
// insert a node into bst
node*insert(node* root, int val){
	//create a new node if the tree is emty
	if( root==NULL){
		return new node(val);
	}
	//inserting into the left subtree
    if(val<(*root).data){
    	(*root).leftchild=insert((*root).leftchild,val);
	}
	//inserting to the rightchild or subtree
	else{
	(*root).rightchild=insert((*root).rightchild,val);	
	}
	return root;
}
int searchtree(node*root,int p){
	if((*root).data==p){
		return p ;
	}else if (p<(*root).data){
		return searchtree(root->leftchild,p);
	}else
	return searchtree(root->rightchild,p);
}
int main(){
	int n,p;
	cout<<"enter the search key p";
	cin>>p;
	node*root=NULL;
	cout<< "enter the valus :"<<endl;
	cin>>n;
	root=insert(root,n);
	cin>>n;
	insert(root,n);
	cin>>n;
	insert(root,n);
	cin>>n;
	insert(root,n);
	cin>>n;
	insert(root,n);
	cin>>n;
	insert(root,n);
	cin>>n;
	insert(root,n);
	if(searchtree(root,p)){
		cout<<p<<" search key found";
		
	}else{
		cout<<"search key not found";
	}
	return 0;
}