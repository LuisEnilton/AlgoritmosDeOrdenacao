#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Algoritmos
{
private:
    // Função para imprimir um vetor
    void print_vector(const vector<int> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Função para trocar dois elementos
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void bubblesort(vector<int> &arr)
    {
        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void insertionsort(vector<int> &arr)
    {
        int size = arr.size();
        int j;
        for (int i = 0; i < size; i++)
        {
            int place = arr[i];
            for (j = i - 1; j >= 0; j--)
            {
                if (arr[j] > place)
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j + 1] = place;
        }
    }

    void quicksort_rec(vector<int> &arr, int begin, int end)
    {
        if (end - begin < 2)
        {
            return;
        }

        // PARTICIONA
        bool right = true;
        int pl = begin;
        int pr = end - 1;
        int pivot = arr[begin];

        while (pl < pr)
        {
            if (right)
            {
                if (arr[pr] < pivot)
                {
                    arr[pl] = arr[pr];
                    pl++;
                    arr[pr] = pivot;
                    right = !right;
                }
                else
                {
                    pr--;
                }
            }
            else
            {
                if (arr[pl] > pivot)
                {
                    arr[pr] = arr[pl];
                    pr--;
                    arr[pl] = pivot;
                    right = !right;
                }
                else
                {
                    pl++;
                }
            }
        }

        // RECURSA
        quicksort_rec(arr, begin, pl);
        quicksort_rec(arr, pl + 1, end);
    }

    void quicksort(vector<int> &arr)
    {
        quicksort_rec(arr, 0, arr.size());
    }

    void merge(vector<int> &a, int begin, int mid, int end)
    {
        int pb = begin;
        int pm = mid;
        vector<int> temp(end - begin + 1);
        int index = 0;

        while (pb < mid && pm < end)
        {
            if (a[pb] < a[pm])
            {
                temp[index] = a[pb];
                index++;
                pb++;
            }
            else
            {
                temp[index] = a[pm];
                index++;
                pm++;
            }
        }

        while (pb < mid)
        {
            temp[index] = a[pb];
            index++;
            pb++;
        }

        while (pm < end)
        {
            temp[index] = a[pm];
            index++;
            pm++;
        }

        index = 0;

        for (int i = begin; i < end; i++)
        {
            a[i] = temp[index];
            index++;
        }
    }

    void mergesort_rec(vector<int> &arr, int begin, int end)
    {
        if (end - begin < 2)
        {
            return;
        }

        int mid = begin + (end - begin) / 2;
        mergesort_rec(arr, begin, mid);
        mergesort_rec(arr, mid, end);
        merge(arr, begin, mid, end);
    }

    void mergesort(vector<int> &arr)
    {
        mergesort_rec(arr, 0, arr.size());
    }

    void heapify(vector<int> &arr, int index, int size)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(arr, largest, size);
        }
    }

    void build_heap(vector<int> &arr, int size)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            heapify(arr, i, size);
        }
    }

    void heapsort(vector<int> &arr)
    {
        int size = arr.size();
        build_heap(arr, size);
        for (int i = 0; i < size; i++)
        {
            swap(arr[0], arr[size - 1 - i]);
            heapify(arr, 0, size - 1 - i);
        }
    }
};
