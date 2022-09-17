#include <iostream>

using namespace std;
  
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
  
    if (left < n && arr[left] < arr[smallest])
      smallest = left;
  
    if (right < n && arr[right] < arr[smallest])
      smallest = right;
  
    if (smallest != i) {
      swap(arr[i], arr[smallest]);
      heapify(arr, n, smallest);
    }
}
  
  
void printArray(int arr[], int n) {
    for (int i = 1; i <= n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
}

void MinHeap(int arr[], int n)
{
  for(int i= n/2; i>0; i--)
  {
    heapify(arr, n, i);
  }
}

int Heap_Minimum(int arr[], int n)
{
    return arr[1];
}

int Heap_extract_min(int arr[], int n)
{
  int tmp = arr[1];

  for(int i=1; i<n; i++)
  {
    arr[i] = arr[i+1];
  }

  arr[n] = -1;
  return tmp;
}

void MinHeap_insert(int val, int arr[], int n)
{
  arr[n+1] = val;
  MinHeap(arr, n+2);
}
  
int main() {
    int n;
    int a[1000];
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>a[i];

    cout<<endl<<endl;
    MinHeap(a, n);
    printArray(a, n);

    cout<<endl<<endl;
    cout<<Heap_extract_min(a, n);
    n--;

    cout<<endl;
    printArray(a, n);

    cout<<endl;
    MinHeap_insert(45, a, n);
    n++;

    cout<<endl;
    printArray(a, n);
  }