/*
题目大意：
已知树的先序遍历和中序遍历，要求按层序遍历输出
*/#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=31;
int pre[maxn],in[maxn],post[maxn];
struct node{
	int data;
	node* lchild,*rchild;
};
int n;

node* Create(int postl,int postr,int inl,int inr){
	if(postl>postr)
		return NULL;
	node* root=new node;
	root->data=post[postr];
	int k;
	for(int i=inl;i<=inr;i++){
		if(post[postr]==in[i]){
			k=i;
			break;
		}
	}
	int numl=k-inl-1;
	root->lchild=Create(postl,postl+numl,inl,k-1);
	root->rchild=Create(postl+numl+1,postr-1,k+1,inr);
	return root;
}
/*
先序遍历 
void preorder(node* root){
	if(root==NULL)
		return;
	printf("%d",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}*/
int num=0;
void levelorder(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		printf("%d",top->data);
		num++; 
		if(num<n)
			printf(" ");
		if(top->lchild!=NULL)
			q.push(top->lchild);
		if(top->rchild!=NULL)
			q.push(top->rchild);
	}	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node* root=new node;
	root=Create(0,n-1,0,n-1);
	//preorder(root);
	levelorder(root); 
	return 0;
}
