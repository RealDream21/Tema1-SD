#include <iostream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("testcase0");
//ofstream fout("");

const long long VMAX = 1e7;
int n;

int *vcheck;

///sortari:
void merge_sort(int * const, const int, const int);
void shellsort(const int * v);
void radixSort(int * const, const int);///baza de fapt merge pana la base - 1
void heapSort(int * const);
void shellSort(int * const, const int);
void introSort(int * const); ///!!!!
void insertionSort(int * const);
///functii de ajutor
void buildHeap(int * const);
void heapify(int * const, const int); ///compar cu copiii si schimb cu cel mai mic/cel mai mare in functie de maxHeap sau minHeap
void pushToHeap(int * const, const int, const int);
void rearrangeHeap(int * const v, const int);
void merge_function(int * const, const int, const int, const int);
///testare, copiere, chestii
bool check_sort(int*); ///1 daca e sortat bine, 0 daca nu e
void copyv(int * const, const int * const);
void show(const int * const);



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
    fin >> n;
    int *v1, *v2, *v3, *v4, *v5;
    v1 = new int[n]; //radix sort
    v2 = new int[n]; //merge sort
    v3 = new int[n]; //shell sort
    v4 = new int[n]; //sort extra 1
    v5 = new int[n]; //sort extra 2
    vcheck = new int[n]; //sortarea standard c++

    for(int i = 0; i < n; i++)
        fin >> vcheck[i];

    copyv(v1, vcheck);
    sort(vcheck, vcheck + n);
    clock_t c_start = clock();
    radixSort(v1, 1024);
    clock_t c_end = clock();
    long double time_elapsed_ms = 1000*(c_end-c_start) / CLOCKS_PER_SEC;
    cout << time_elapsed_ms/1000;


    cout << check_sort(vcheck) << endl;


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
    long long p = 1;
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
    insertionSort(v);
    return;
}


void insertionSort(int * const v){
    int key, j;

    for(int i = 1; i < n; i++){
        j = i - 1;
        key = v[i];
        while(j >= 0 && key < v[j]){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

}

void heapify(int * const v, int i){
    while(i){
        int tata = (i - 1)/2;
        if(v[tata] < v[i]){
            swap(v[tata], v[i]);
            i = tata;
        }
        else break;
    }
}

void rearrangeHeap(int * const v, const int sfarsit){
    int i = 0;
    while(i * 2 + 2 <= sfarsit){
        int fiu_st = i * 2 + 1;
        int fiu_dr = i * 2 + 2;
        if (v[fiu_st] > v[fiu_dr]){
            swap(v[i], v[fiu_st]);
            i = fiu_st;
        }
        else if(v[fiu_dr] > v[fiu_st]){
            swap(v[i], v[fiu_dr]);
            i = fiu_dr;
        }
        else break;
    }
}

void buildHeap(int * const v){
    int* aux;
    aux = new int[n];
    for(int i = 0; i < n; i++)
        pushToHeap(aux, v[i], i);
    copyv(v, aux);
    delete[] aux;
}

void pushToHeap(int * const v, const int x, int curentIndex){
    v[curentIndex] = x;
    heapify(v, curentIndex);
}

void heapSort(int * const v){
    buildHeap(v);
    int sfarsit = n - 1;
    while(sfarsit > 0){
        swap(v[0], v[sfarsit--]);
        rearrangeHeap(v, sfarsit);
    }
    if(v[0] > v[1])
        swap(v[0], v[1]);
}

void show(const int * const v){
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
}

void shellsort(int * v){
    int gap = 2;
    while(n/gap){
        int gap_size = n/gap;
        for(int i = 0; i + gap_size < n; i++)
            if(v[i] > v[i + gap_size])
                swap(v[i], v[i + gap_size]);
        gap *= 2;
    }
}
