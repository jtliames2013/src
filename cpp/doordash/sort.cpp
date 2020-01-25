#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int partition(vector<int>& a, int low, int high) {
    // Lomuto partition
    int pivot=rand()%(high-low+1)+low, i=low, end=low;
    swap(a[high], a[pivot]);
    for (; i<high; ++i) {
        if (a[i]<a[high]) {
            if (end!=i) swap(a[end], a[i]);
            end++;
        }
    }
    swap(a[end], a[high]);
    return end;
}

void quicksort(vector<int>& a, int low,int high) {
    if (low>=high) return;    
    int pivot=partition(a, low, high);
    quicksort(a, low, pivot-1);
    quicksort(a, pivot+1, high);
}

void quicksort(vector<int>& a) {
    int n=a.size();
    quicksort(a, 0, n-1);
}

void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> tmp(high-low+1);
    int i=low, j=mid+1, k=0;
    while (i<=mid || j<=high) {
        if (i>mid) tmp[k++]=a[j++];
        else if (j>high) tmp[k++]=a[i++];
        else {
            if (a[i]<a[j]) tmp[k++]=a[i++];
            else tmp[k++]=a[j++];
        }
    }
    for (int i=low; i<=high; ++i) a[i]=tmp[i-low];
}

void mergesort(vector<int>& a, int low, int high) {
    if (low>=high) return;
    int mid=(low+high)/2;
    mergesort(a, low, mid);
    mergesort(a, mid+1, high);
    merge(a, low, mid, high);
}

void mergesort(vector<int>& a) {
    int n=a.size();
    mergesort(a, 0, n-1);
}

void bubblesort(vector<int>& a) {
    int n=a.size();
    for (int i=n-1; i>0; --i) {
        for (int j=0; j<i; ++j) {
            if (a[j]>a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void insertionsort(vector<int>& a) {
    int n=a.size();
    for (int i=1; i<n; ++i) {
        int tmp=a[i], j;
        for (j=i-1; j>=0 && a[j]>tmp; --j) {
            a[j+1]=a[j];
        }
        a[j+1]=tmp;
    }
}

void bucketsort(vector<int>& a, int numBucket) {
    vector<vector<int>> bucket(numBucket);
    int maxVal=*max_element(a.begin(), a.end())+1;
    for (int i=0; i<a.size(); ++i) {
        bucket[a[i]*numBucket/maxVal].push_back(a[i]);
    }

    for (int i=0; i<numBucket; ++i) sort(bucket[i].begin(), bucket[i].end());

    int idx=0;
    for (int i=0; i<numBucket; ++i) {
        for (int j=0; j<bucket[i].size(); ++j) a[idx++]=bucket[i][j];
    }
}

int main(int argc, char** argv) {
    //vector<int> orig={19, 8, 27, 0, 10, 6, 4, 5, 10, 19, 20, 1, 88, 60, 55, 78};
    vector<int> orig={4, 64, 200, 42, 56, 22, 1, 64, 0, 161, 200, 0, 42, 4, 64, 200, 42, 56, 22, 1, 64, 0, 161, 200, 0, 42};
    vector<int> a;

    cout << "quick sort" << endl;
    a=orig;
    quicksort(a);
    for (auto& i:a) cout << i << " ";
    cout << endl;

    cout << "merge sort" << endl;    
    a=orig;
    mergesort(a);
    for (auto& i:a) cout << i << " ";
    cout << endl;

    cout << "bubble sort" << endl;    
    a=orig;
    bubblesort(a);
    for (auto& i:a) cout << i << " ";
    cout << endl;

    cout << "insertion sort" << endl;    
    a=orig;
    insertionsort(a);
    for (auto& i:a) cout << i << " ";
    cout << endl;

    cout << "bucket sort" << endl;    
    a=orig;
    bucketsort(a, 5);
    for (auto& i:a) cout << i << " ";
    cout << endl;

    return 0;
}