void mergesort(int a[], int l, int r){
    if(l >= r)  return;
    int mid = l + r >> 1;
    mergesort(a, l, mid), mergesort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1, tmp[r - l + 1];
    while(i <= mid && j <= r){
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r)   tmp[k++] = a[j++];
    for(k = 0, i = l; i <= r; ++i, ++k)
        a[i] = tmp[k];
}
