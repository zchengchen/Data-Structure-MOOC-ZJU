BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST) {
        BinTree node = (BinTree) malloc(sizeof(struct TNode));
        node->Left = node->Right = NULL;
        node->Data = X;
        return node;
    } else {
        if(BST->Data < X) {
            BST->Right = Insert(BST->Right, X);
        } else if (BST->Data > X) {
            BST->Left = Insert(BST->Left, X);
        }
        return BST;
    }
}

BinTree Delete( BinTree BST, ElementType X ){
	if(BST == NULL){   printf("Not Found\n"); return BST;}
    else if(BST->Data == X){
        if(BST->Left != NULL && BST->Right != NULL){
            BinTree p = BST->Left;
			while(p->Right) p = p->Right;
			p->Right = BST->Right;
            p = BST->Left;
            //free(BST);
            return p; 
        }
        else if(BST->Left != NULL && BST->Right == NULL){
            BinTree p = BST->Left;
            //free(BST);
            return p;
        }
        else if(BST->Right  != NULL && BST->Left == NULL){
            BinTree p = BST->Right;
            //free(BST);
            return p;
        }
		else{
			BinTree p = BST;
			//free(p);
			return NULL;
		}
    }
    else if(X < BST->Data) {
        BST->Left = Delete(BST->Left, X);
		return BST;
    }
	else{ BST->Right = Delete(BST->Right, X); return BST;}
}

Position Find( BinTree BST, ElementType X ){
    if(BST == NULL) return 0;
    else if(BST->Data == X) return BST;
    else if(X < BST->Data) Find(BST->Left, X);
    else Find(BST->Right, X);
}

Position FindMin( BinTree BST )
{
    if(!BST) return NULL;
    else if (BST->Left == NULL) return BST;
    else return FindMin(BST->Left);
}

Position FindMax( BinTree BST )
{
    if(!BST) return NULL;
    else if (BST->Right == NULL) return BST;
    else return FindMax(BST->Right);
}
