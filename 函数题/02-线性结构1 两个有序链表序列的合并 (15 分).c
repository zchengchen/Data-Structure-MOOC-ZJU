List Merge( List L1, List L2 )
{
    List h1 = NULL, h2 = NULL, h3 = NULL;
    h1 = L1->Next;
    h2 = L2->Next;
    List L3 = malloc(sizeof(struct Node));
    L3->Next = NULL;
    h3 = L3;
    while(h1 && h2) {
        if(h1->Data <= h2->Data) {
            h3->Next = h1;
            h1 = h1->Next;
        } else {
            h3->Next = h2;
            h2 = h2->Next;
        }
        h3 = h3->Next;
    }
    if(h1) {
        h3->Next = h1;
    } else if (h2) {
        h3->Next = h2;
    } else {
        h3->Next = NULL;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
}
