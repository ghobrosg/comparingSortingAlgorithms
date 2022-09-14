#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
const int maxNum = 1000;
void bubbleSort(vector<int> arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(vector<int> arr, int n)
{
    int i, j, min_idx;


    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(vector<int> arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    ofstream File_;
    File_.open("numbers.txt", ios::app);

    vector<int> BestCase;
    for (int i = 0; i < maxNum; i++) {
        BestCase[i] = i + 1;
    }
    int n = sizeof(BestCase) / sizeof(BestCase[0]);
    auto startBubbleBest = chrono::steady_clock::now();
    bubbleSort(BestCase, n);
    auto endBubbleBest = chrono::steady_clock::now();
    auto diffBubbleBest = endBubbleBest - startBubbleBest;
    File_ << "Tri a bulles, meilleur cas: " << chrono::duration<double, milli>(diffBubbleBest).count() << " ms" << endl;

    auto startSelectionBest = chrono::steady_clock::now();
    selectionSort(BestCase, n);
    auto endSelectionBest = chrono::steady_clock::now();
    auto diffSelectionBest = endSelectionBest - startSelectionBest;
    File_ << "Tri selectif, meilleur cas: " << chrono::duration<double, milli>(diffSelectionBest).count() << " ms" << endl;

    auto startInsertionBest = chrono::steady_clock::now();
    insertionSort(BestCase, n);
    auto endInsertionBest = chrono::steady_clock::now();
    auto diffInsertionBest = endInsertionBest - startInsertionBest;
    File_ << "Tri par insertion, meilleur cas: " << chrono::duration<double, milli>(diffInsertionBest).count() << " ms" << endl;

    unsigned seed = time(0);
    srand(seed);
    ofstream File;
    File.open("data.txt");
    const int x = maxNum;
    for (int i = 0; i < x; i++) {
        int a = rand() % maxNum + 1;
        File << a << endl;
    }
    ifstream file;
    file.open("data.txt");
    int numbers;
    vector<int> arr;
    int i = -1;

    if (file.is_open()) {
        while (file >> numbers) {
            i = i + 1;
            arr[i] = numbers;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        auto startBubbleRand = chrono::steady_clock::now();
        bubbleSort(arr, n);
        auto endBubbleRand = chrono::steady_clock::now();
        auto diffBubbleRand = endBubbleRand - startBubbleRand;
        File_ << "Tri a bulles, cas moyen: " << chrono::duration<double, milli>(diffBubbleRand).count() << " ms" << endl;

        auto startSelectionRand = chrono::steady_clock::now();
        selectionSort(arr, n);
        auto endSelectionRand = chrono::steady_clock::now();
        auto diffSelectionRand = endSelectionRand - startSelectionRand;
        File_ << "Tri selectif, cas moyen: " << chrono::duration<double, milli>(diffSelectionRand).count() << " ms" << endl;

        auto startInsertionRand = chrono::steady_clock::now();
        insertionSort(arr, n);
        auto endInsertionRand = chrono::steady_clock::now();
        auto diffInsertionRand = endInsertionRand - startInsertionRand;
        File_ << "Tri par insertion, cas moyen: " << chrono::duration<double, milli>(diffInsertionRand).count() << " ms" << endl;
    }
    vector<int> WorstCase;
    for (int i = maxNum; i > 0; i--) {
        WorstCase[maxNum - i] = i;
    }
    auto startBubbleWorst = chrono::steady_clock::now();
    bubbleSort(WorstCase, n);
    auto endBubbleWorst = chrono::steady_clock::now();
    auto diffBubbleWorst = endBubbleWorst - startBubbleWorst;
    File_ << "Tri a bulles, pire cas: " << chrono::duration<double, milli>(diffBubbleWorst).count() << " ms" << endl;

    auto startSelectionWorst = chrono::steady_clock::now();
    selectionSort(WorstCase, n);
    auto endSelectionWorst = chrono::steady_clock::now();
    auto diffSelectionWorst = endSelectionWorst - startSelectionWorst;
    File_ << "Tri selectif, pire cas: " << chrono::duration<double, milli>(diffSelectionWorst).count() << " ms" << endl;

    auto startInsertionWorst = chrono::steady_clock::now();
    insertionSort(WorstCase, n);
    auto endInsertionWorst = chrono::steady_clock::now();
    auto diffInsertionWorst = endInsertionWorst - startInsertionWorst;
    File_ << "Tri par insertion, pire cas: " << chrono::duration<double, milli>(diffInsertionWorst).count() << " ms" << endl << endl;
    return 0;
}