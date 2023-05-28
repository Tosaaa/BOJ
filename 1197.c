#include <stdio.h>
#include <stdlib.h>

int *uf_init(int n) {
    int *root = malloc(sizeof *root * n); // root[i][0]은 root, root[i][1]은 height(rank)
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }
    return (int *)root;
}

int uf_find(int *root, int x) {
    if (root[x] == x) return x;
    return (root[x] = uf_find(root, root[x])); // Path Compression
}

void uf_unite(int *root, int x, int y) {
    x = uf_find(root, x);
    y = uf_find(root, y);

    if (x == y) return;
    root[x] = y;
    return;    
}

int uf_same(int *root, int x, int y) {
    return (uf_find(root, x) == uf_find(root, y));
}

void uf_del(int *root) {
    free(root);
    return;
}

void swap(int *arr, int *idx, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    temp = idx[a];
    idx[a] = idx[b];
    idx[b] = temp;
    return;
}

int partition(int *arr, int *idx, int left, int right) {
    int mid = left + (right-left)/2; // to prevent O(n^2) when arr is already sorted in descending order.
    swap(arr, idx, left, mid);
    int pivot = left;
    int low = left+1;
    int high = right;

    while (1) {
        while (low <= right && arr[low] <= arr[pivot])
            low++;
        while (high >= left+1 && arr[high] > arr[pivot])
            high--;
        if (low > high) // already sorted
            break;
        swap(arr, idx, low, high);
    }
    
    swap(arr, idx, pivot, high);
    return high; //index of pivot
}

void qqsort(int *arr, int *idx, int left, int right) {
    if (left >= right) return;
    int pivot = partition(arr, idx, left, right);
    qqsort(arr, idx, left, pivot-1);
    qqsort(arr, idx, pivot+1, right);
    return;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int a, b, c;
    int (*edges)[2] = malloc(sizeof *edges * E);
    int *weight = malloc(sizeof *weight * E);
    int *idx = malloc(sizeof *idx * E);
    for (int i = 0 ; i < E; i++)
        idx[i] = i;
   
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges[i][0] = a-1;
        edges[i][1] = b-1;
        weight[i] = c;
    }

    qqsort(weight, idx, 0, E-1);

    // printf("---\n");
    // for (int i = 0; i < E; i++) {
  
    //     printf("%d %d %d\n", edges[idx[i]][0], edges[idx[i]][1], weight[i]);
    // }
    // printf("---\n");

    int *root = uf_init(V);
    int result = 0;
    for (int i = 0; i < E; i++) {
        if (!uf_same(root, edges[idx[i]][0], edges[idx[i]][1])) {
            uf_unite(root, edges[idx[i]][0], edges[idx[i]][1]);
            //printf("%d %d %d\n", edges[idx[i]][0], edges[idx[i]][1], weight[i]);
            result += weight[i];
        }
    }
   
    printf("%d\n", result);
    free(edges);
    free(weight);
    free(idx);
    uf_del(root);
    return 0;
}