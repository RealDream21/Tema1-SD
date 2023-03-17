#include <iostream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("testcase0");
//ofstream fout("");

const long long VMAX = 1e7;
const long long maxnr = 2147483647;
int n;

int *vcheck;

///sortari:
void radixSort(int * const, const int);///baza de fapt merge pana la base - 1
void heapSort(int * const);
void shellSort(int * const);
void introSort(int * const, const int, const int, const int); ///!!!!
void insertionSort(int * const);
void mergeSort(int * const);
void quickSort(int * const, const int, const int);
void insertionSortParams(int * const, const int, const int);
void heapSortParams(int * const, const int, const int);
///functii de ajutor
void merge_sort(int * const, const int, const int);
void buildHeap(int * const);
void buildHeapParams(int * const, int * const, const int, const int);
void rearrangeHeapParams(int * const, const int, const int, const int);
void heapify(int * const, const int); ///compar cu copiii si schimb cu cel mai mic/cel mai mare in functie de maxHeap sau minHeap
void pushToHeap(int * const, const int, const int);
void rearrangeHeap(int * const v, const int);
void merge_function(int * const, const int, const int, const int);
int median3(int * const, const int, const int, const int);
int partitionPoint(int * const, const int, const int);
int tryPartition(int * const, const int, const int);
///testare, copiere, chestii
bool check_sort(int*); ///1 daca e sortat bine, 0 daca nu e
void copyv(int * const, const int * const);
void show(const int * const);
void introSortCall(int * const);


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
    teste: 1, 2, 3 + numere crescatoare, numere toate identice, numere descrescatoare

    MY INTROSORT BEATS C++ INTROSORT IN SOME CASES!!!!!!
*/

int main()
{
    fin >> n;
    if(n > VMAX){
        cout << "Sortare esuata, vector prea mare " << endl;
        return -1;
    }
    int *v1, *v2, *v3, *v4, *v5;
    v1 = new int[n]; //radix sort
    v2 = new int[n]; //merge sort
    v3 = new int[n]; //shell sort
    v4 = new int[n]; //sort extra 1
    v5 = new int[n]; //sort extra 2
    vcheck = new int[n]; //sortarea standard c++

    long long x;
    for(int i = 0; i < n; i++){
        fin >> x;
        if(x > maxnr){
            cout << "Numarul " << x << " nu incape in int";
            return -1;
        }
        else{
            vcheck[i] = x;
        }
    }

    copyv(v1, vcheck);

    long double time_elapsed_ms;
    clock_t c_start, c_end;

    c_start = clock();
    sort(vcheck, vcheck + n);
    c_end = clock();
    time_elapsed_ms = 1000*(c_end-c_start) / CLOCKS_PER_SEC;
    cout << time_elapsed_ms/1000 << "<--c++ sort" << endl;

    c_start = clock();
    cout << endl;

    c_end = clock();
    time_elapsed_ms = 1000*(c_end-c_start) / CLOCKS_PER_SEC;
    cout << endl;
    cout << time_elapsed_ms/1000 << "<--mysort" << endl;


    cout << check_sort(v1) << endl;


    return 0;
}

void mergeSort(int * const v){
    merge_sort(v, 0, n - 1);
}

void merge_function(int * const v, const int st, const int mij, const int dr){
    int *aux;
    aux = new int[dr - st + 1];
    int c = 0;
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
    delete [] aux;
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
        if (v[fiu_st] >= v[fiu_dr] && v[fiu_st] > v[i]){
            swap(v[i], v[fiu_st]);
            i = fiu_st;
        }
        else if(v[fiu_dr] > v[fiu_st] && v[fiu_dr] > v[i]){
            swap(v[i], v[fiu_dr]);
            i = fiu_dr;
        }
        else {
            break;
        }
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
    while(sfarsit != 0){
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

void shellSort(int * v){
    int gap = 2;
    while(n/gap){
        int gap_size = n/gap;
        for(int i = 0; i + gap_size < n; i++)
            if(v[i] > v[i + gap_size])
                swap(v[i], v[i + gap_size]);
        gap *= 2;
    }
}



void quickSort(int * const v, const int st, const int dr){
    if(st < dr){
        int m = (dr - st)/2 + st;
        int pivot = median3(v, st, m, dr);
        swap(v[pivot], v[st]);
        pivot = st;
        int i = st, j = dr;
        while(i <= j){
            while(v[i] < v[pivot]) i++;
            while(v[j] > v[pivot]) j--;
            if(i <= j){
                swap(v[i], v[j]);
                i++;
                j--;
            }
        }
        quickSort(v, st, j);
        quickSort(v, i, dr);
    }
}

inline int median3(int * const v, const int pos1, const int pos2, const int pos3){
    if(pos3 - pos1 + 1 < 3) return pos1;
    if(v[pos1] < v[pos2] && v[pos2] < v[pos3])
        return pos2;
    else if(v[pos1] < v[pos3] && v[pos1] > v[pos2])
        return pos1;
    else
        return pos3;
}
int partitionPoint(int * const v, const int st, const int dr){
    if(st < dr){
        int m = (dr - st)/2 + st;
        int pivot = median3(v, st, m, dr);
        swap(v[pivot], v[st]);
        pivot = st;
        int i = st, j = dr;
        while(i <= j){
            while(v[i] < v[pivot]) i++;
            while(v[j] > v[pivot]) j--;
            if(i <= j){
                swap(v[i], v[j]);
                i++;
                j--;
            }
        }
        return st;
    }
}

int tryPartition(int * const v, const int st, const int dr){
    if(st < dr){
        int m = (dr - st)/2 + st;
        int pivot = median3(v, st, m, dr);
        swap(v[m], v[pivot]);
        int i = st, j = dr, d = 0;
        while (i < j){
            if(v[i] > v[j])
                swap(v[i], v[j]);
            i += d;
            j -= 1 - d;
        }
        return i;
    }
}

void introSortCall(int * const v){
    int depthLimit = floor(log(n))/256;
    introSort(v, depthLimit, 0, n - 1);
}

void insertionSortParams(int * const v, const int st, const int dr){
    int key, j;

    for(int i = st + 1; i < dr + 1; i++){
        j = i - 1;
        key = v[i];
        while(j >= 0 && key < v[j]){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void heapSortParams(int * const v, const int st, const int dr){
    int * aux;
    aux = new int[dr - st + 1];
    for(int i = 0; i < dr - st + 1; i++)
        aux[i] = v[st + i];
    buildHeapParams(aux, v, st, dr);
    int sfarsit = dr - st;
    while(sfarsit > 0){
        swap(aux[0], aux[sfarsit--]);
        rearrangeHeap(aux, sfarsit);
    }
    if(aux[0] > aux[1])
        swap(aux[0], aux[1]);
    for(int i = 0; i < dr - st + 1; i++)
        v[st + i] = aux[i];
}

void buildHeapParams(int * const v, int * const vref, const int st, const int dr){
    for(int i = 0; i < dr - st + 1; i++)
        pushToHeap(v, vref[st + i], i);
}

void rearrangeHeapParams(int * const v, const int st, const int dr, const int sfarsit){
    int i = 0;
    while(i * 2 + 2 < sfarsit){
        int fiu_st = i * 2 + 1;
        int fiu_dr = i * 2 + 2;
        if (v[fiu_st] >= v[fiu_dr] && v[fiu_st] > v[i]){
            swap(v[i], v[fiu_st]);
            i = fiu_st;
        }
        else if(v[fiu_dr] > v[fiu_st] && v[fiu_dr] > v[i]){
            swap(v[i], v[fiu_dr]);
            i = fiu_dr;
        }
        else {
            break;
        }
    }
}

void introSort(int * const v, int depthLimit, const int st, const int dr){
    int dimension = dr - st + 1;
    if (dimension < 16){
        insertionSortParams(v, st, dr);
    }
    else if (depthLimit == 0){
        heapSortParams(v, st, dr);
    }
    else{
        int p = tryPartition(v, st, dr);
        introSort(v, depthLimit - 1, 0, p - 1);
        introSort(v, depthLimit - 1, p + 1, n - 1);
    }
}
