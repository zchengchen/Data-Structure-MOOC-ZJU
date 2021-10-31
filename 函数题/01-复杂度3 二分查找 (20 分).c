Position BinarySearch( List L, ElementType X )
{
    Position r = L->Last;
    Position l = 1;
    Position mid = (l+r)/2;
    while(l <= r){
        if(X < L->Data[mid]){
            r = mid-1;
        }else if(X > L->Data[mid]){
            l = mid+1;
        }else{
            return mid;
        }
        mid = (l+r)/2;
    }
    return NotFound;
}
