/*
Problema: Yodaness Level
Categorias:
	adhoc > sorting
Dificuldade: medio
Descricao: 
Dica: https://www.geeksforgeeks.org/counting-inversions/
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
 
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
 
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 
int main(){
    int t, n, i;
    cin >> t;
    while(t--){
        string s;
        map<string, int> val;
        int vet[30000];

        cin >> n;
        for(i = 0; i < n; i++){
            cin >> s;
            val[s] = i;
        }
        for(i = 0; i < n; i++){
            cin >> s;
            vet[i] = val[s];
        }
        
        cout << mergeSort(vet, n) << endl;
    }
}