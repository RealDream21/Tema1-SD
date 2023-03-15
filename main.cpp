#include <iostream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const long long VMAX = 1e7;
int n;

int *vcheck;
//https://www.youtube.com/watch?v=2DmK_H7IdTo
//https://www.geeksforgeeks.org/introsort-or-introspective-sort/
void merge_sort(int* const, const int, const int);
void merge_function(int* const, const int, const int, const int);
bool check_sort(int*); ///1 daca e sortat bine, 0 daca nu e
void radixSort(int* const, const int);///baza de fapt merge pana la base - 1
void heapSort(int * const);
void buildHeap(int * const, const int);
void heapify(int * const); ///compar cu copiii si schimb cu cel mai mic/cel mai mare in functie de maxHeap sau minHeap
void introSort(int * const); ///!!!!
void insertionSort(int * const);
void copyv(int * const, const int * const);
void show(const int * const v);



/*
clock_t c_start = clock();
clock_t c_end = clock();
long double time_elapsed_ms = 1000*(c_end-c_start) / CLOCKS_PER_SEC;
    cout << time_elapsed_ms/1000;
---- timpul in secunde.ms
*/

/*cazuri particulare si observatii:
    la radix sort nu merge in toate bazele!!!
    idee de pus la proiect: pentru fiecare test input care este best case pt radix sort!!(adica iau o gramada de baze si vad care baza imi da timpul cel mai bun)

*/

int main()
{
    cin >> n;
    int *v1, *v2, *v3, *v4, *v5;
    v1 = new int[VMAX]; //radix sort
    v2 = new int[VMAX]; //merge sort
    v3 = new int[VMAX]; //shell sort
    v4 = new int[VMAX]; //sort extra 1
    v5 = new int[VMAX]; //sort extra 2
    vcheck = new int[VMAX]; //sortarea standard c++

    for(int i = 0; i < n; i++)
        cin >> vcheck[i];
    copyv(v1, vcheck);
    sort(vcheck, vcheck + n);
    insertionSort(v1);
    show(v1);


    return 0;
}

void merge_function(int * const v, const int st, const int mij, const int dr){
    int aux[dr + 1], c = 0;
    int i = st;
    int j = mij + 1;
    while(i <= mij && j <= dr){
        if(v[i] > v[j])
            aux[c++] = v[j++];
        else aux[c++] = v[i++];
    }
    while(i <= mij){
        aux[c++] = v[i];
        i++;
    }
    while(j <= dr){
        aux[c++] = v[j];
        j++;
    }
    c = 0;
    for(int i = st; i <= dr; i++){
        v[i] = aux[c++];
    }
}


void merge_sort(int * const v, const int st, const int dr){
    if(st < dr){
        int mij = (st + dr)/2;
        merge_sort(v, st, mij);
        merge_sort(v, mij + 1, dr);
        merge_function(v, st, mij, dr);
    }
    else return;
}

bool check_sort(int * const v){
    for(int i = 0; i < n; i++)
        if(vcheck[i] != v[i]) return false;
    return true;
}
void copyv(int * const v, const int * const aux){
    for(int i = 0 ;i < n; i++)
        v[i] = aux[i];
}

void radixSort(int * const v, const int base){
    vector<vector<int>> buckets(base);
    int p = 1;
    while(buckets[0].size() != n){
        for(int i = 0; i < base; i++)
            buckets[i].clear();

        for(int i = 0; i < n; i++)
            buckets[v[i]/p%base].push_back(v[i]);

        int k = 0;
        for(int i = 0; i < base; i++){
            for(int j = 0; j < buckets[i].size(); j++)
                v[k++] = buckets[i][j];
        }
        p *= base;
    }
    return;
}

void insertionSort(int * const v){
    int key, j;

    for(int i = 1; i < n; i++)
    {
        j = i - 1;
        key = v[i];
        while(j >= 0 && key < v[j])
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

}

void show(const int * const v){
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
}
