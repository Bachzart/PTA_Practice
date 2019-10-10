#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 35
int n, pre[maxn], in[maxn];
struct SNode{
	int data;
	struct SNode *next;
};
typedef struct SNode* PtrToSNode;
typedef struct SNode* Stack;
Stack Createstack() {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->next = NULL;
	return S; 
}
void Push(Stack S, int X) {
	PtrToSNode t = (PtrToSNode)malloc(sizeof(struct SNode));
	t->data = X;
	t->next = S->next;
	S->next = t;
}
int Pop(Stack S) {
	if(S->next == NULL) return 0;
	else {
		PtrToSNode top = S->next;
		S->next = top->next;
		int topdata = top->data;
		free(top);
		return topdata;
	} 
}
struct TNode{
	int data;
	struct TNode *left, *right;
};
typedef struct TNode* Tree;
typedef struct TNode* PtrToTNode;
Tree buildtree(int preL, int preR, int inL, int inR) {
	if(preL > preR) return NULL;
	PtrToTNode root = (PtrToTNode)malloc(sizeof(struct TNode));
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;
	root->left = buildtree(preL + 1, preL + numLeft, inL, k - 1);
	root->right = buildtree(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int num = 0;
void postorder(Tree root) {
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d", root->data);
	if(num < n - 1) printf(" ");
	num++;
}
int main() {
	Stack S = Createstack();
	scanf("%d", &n);
	int i, num, precnt = 0, incnt = 0;
	char ope[10];
	for(i = 0; i < 2 * n; i++) {
		scanf("%s", ope);
		if(!strcmp(ope, "Push")) {
			scanf("%d", &num);
			pre[precnt++] = num;
			Push(S, num);
		} else {
			num = Pop(S);
			in[incnt++] = num;
		}
	}
	Tree T = buildtree(0, n - 1, 0, n - 1);
	postorder(T);
	return 0;
}
