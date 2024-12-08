void heapify(int arr[], int N, int i){
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] < arr[smallest])
        smallest = l;
    if (r < N && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, N, smallest);
    }
}

void heapsort(int arr[] , int N){
    for (int i = N /2 -1 ; i >= 0 ; i--){
        heapify(arr , N , i );
    }
    for (int i = N-1 ; i > 0 ; i --){
        swap (arr[0],arr [i]);
        heapify(arr , i  , 0);
    }
}