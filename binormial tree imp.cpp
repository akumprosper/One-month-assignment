#include<iostream>
using namespace std;
 struct node{
 	int degree;
 	int data;
 	 node*parent;
 	 node*child;
 	 node*sibling;
 	 
 	 node(int val){
 	 	data=val;
 	 	degree=0;
 	 	parent=NULL;
 	 	child=NULL;
 	 	sibling=NULL;
	  }
 };
 node*mergebinomialtree(node*b1,node*b2){
 	if (b1->data > (*b2).data){
 		swap(b1,b2);
	 }
	 (*b2).parent=b1;
	 (*b2).sibling=(*b1).child;
	 (*b1).child=b2;
	 (*b1).degree++;
	 return b1;
 }
 
 void printtree(node*root){
 	if(root==NULL){
 		return;
	 }
	 cout<<(*root).data<<" ";
	 printtree((*root).child);
	 printtree((*root).sibling);
 }
int main(){
	node*tree1= new node(10);
	node*tree2=new node(20);
	node*merge=mergebinomialtree(tree1,tree2);
	cout<<"merge tree ;";
	printtree(merge);
	return 0;
}