#include <cassert>
#include <iostream>
#include <vector>

/*void mergesort(int a[], int len) {
    //create temporary array
    //to be used by the merge
    //code
    int x[] = new int[len];
    msort(a,x,0,len-1);
    delete []x;
 }
 void msort(int a[], int x[], int s, int e) {
    //check for exit from recursion
    if (e - s < 1) return;
    int m = (s + e) / 2;
    msort(left sub array)
    msort(right sub array)
    merge while(i <= m and j <= e)
    if (i <= m)
    //copy remaining values from left subarray
 }
*/
void merge(int a[], int from, int mid, int to) {
    int n = to - from + 1;
    std::vector<int> b(n);
    int i1 = from;
    int i2 = mid + 1;
    int j = 0;

    while (i1 <= mid && i2 <= to) {
        if (a[i1] < a[i2]) {
            b[j] = a[i1];
            i1++;
        }
        else {
            b[j] = a[i2];
            i2++;
        }
        j++;
    }

    while (i1 <= mid) {
        b[j] = a[i1];
        i1++;
        j++;
    }
    while (i2 <= to) {
        b[j] = a[i2];
        i2++;
        j++;
    }
    for (j = 0; j < n; j++)
        a[from + j] = b[j];
}

void merge_sort(int a[], int from, int to) {
    if (from == to) return;
    int mid = (from + to) / 2;
    merge_sort(a, from, mid);
    merge_sort(a, mid + 1, to);
    merge(a, from, mid, to);
}

bool sorted (int a[], int n) {
    for (int i = 0; i < n -1; ++i) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main (int argc, char * args[]) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
    merge_sort(a, 0, 999);
    assert(sorted(a, 1000));
    int b[1001];
    for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
    merge_sort(b, 0, 1000);
    assert(sorted(b, 1001));
    int c[] = { 2 };
    merge_sort(c, 0, 1);
    assert(sorted(c, 1));
    int d[] = { 1, 2, 3, 4, 5 };
    merge_sort(d, 0, 4);
    assert(sorted(d, 5));
    std::cout << "All tests passed." << std::endl;
}