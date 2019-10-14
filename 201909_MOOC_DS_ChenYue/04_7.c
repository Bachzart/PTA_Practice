#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT );
void InorderTraversal( BinTree BT );

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
void PreorderTraversal( BinTree BT ) {
	if(!BT) return;
	printf("%d ", BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}
void InorderTraversal( BinTree BT ) {
	if(!BT) return;
	InorderTraversal(BT->Left);
	printf("%d ", BT->Data);
	InorderTraversal(BT->Right);
}
BinTree Insert( BinTree BST, ElementType X ) {
	/* method 1: use recursion 
	
	if(!BST) {
		BST = (struct TNode*)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else {
		if(X < BST->Data) BST->Left = Insert(BST->Left, X);
		else if(X > BST->Data) BST->Right = Insert(BST->Right, X);
	}
	return BST;
	*/
	/* method 2: use loop */
	if(!BST) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else {
		Position pre, t;
		t = BST; 
		while(t) {
			pre = t;
			if(X > t->Data) t = t->Right;
			else if(X < t->Data) t = t->Left;
		}
		struct TNode *tmpnode = (struct TNode*)malloc(sizeof(struct TNode));
		tmpnode->Data = X;
		tmpnode->Left = tmpnode->Right = NULL;
		if(X < pre->Data) {
			pre->Left = tmpnode;
		} else if(X > pre->Data) {
			pre->Right = tmpnode;
		}
	}
	return BST;
}
BinTree Delete( BinTree BST, ElementType X ) {
	Position tmp;
	if(!BST) printf("Not Found\n");
	else if(X < BST->Data) BST->Left = Delete(BST->Left, X);
	else if(X > BST->Data) BST->Right = Delete(BST->Right, X);
	else {
		if(BST->Left && BST->Right) {
			/* method 1: use the minium node of right subtree
			
			tmp = FindMin(BST->Right);
			BST->Data = tmp->Data;
			BST->Right = Delete(BST->Right, BST->Data); 
			
			*/
			/* method 2: use the maximum node of left subtree */
			tmp = FindMax(BST->Left);
			BST->Data = tmp->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		} else {
			tmp = BST;
			if(!BST->Left) BST = BST->Right;
			else BST = BST->Left;
			free(tmp); 
		}
	}
	return BST;
}
Position Find( BinTree BST, ElementType X ) {
	/* method 1: use recursion
	
	if(!BST) return NULL;
	if(X > BST->Data) return Find(BST->Right, X);
	else if(X < BST->Data) return Find(BST->Left, X);
	else return BST;
	
	*/
	/* method 2: use loop*/
	while(BST) {
		if(X > BST->Data) BST = BST->Right;
		else if(X < BST->Data) BST = BST->Left;
		else break;
	}
	return BST;
}
Position FindMin( BinTree BST ) {
	/* method 1: use recursion
	
	if(!BST) return NULL;
	else if(!BST->Left) return BST;
	else return FindMin(BST->Left);
	
	*/
	/* method 2: use loop, but need use if to avoid segmentation fault */
	if(BST)	while(BST->Left) BST = BST->Left;
	return BST;
}
Position FindMax( BinTree BST ) {
	/* method 1: use recursion
	
	if(!BST) return NULL;
	else if(!BST->Right) return BST;
	else return FindMax(BST->Right);
	
	*/
	/* method 2: use loop, but need use if to avoid segmentation fault */
	if(BST) while(BST->Right) BST = BST->Right;
	return BST;
}

/*
samples:
in:
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3

out:
Preorder: 5 2 1 0 4 8 6 7 10 9
6 is found
3 is not found
10 is found
10 is the largest key
0 is found
0 is the smallest key
5 is found
Not Found
Inorder: 1 2 4 6 8 9
*/
