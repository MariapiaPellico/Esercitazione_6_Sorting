#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <numeric> // Per usare iota
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;

double TempiMerge(vector<int>& vector_merge);
double TempiBubble(vector<int>& vector_bubble);

int main(int argc, char **argv)
{
    // Controllo se è stato fornito un argomento dalla riga di comando
    if (argc != 2)
    {
        cerr << "No command line argument provided" << endl;
        return 1;
    }

    // Converto l'argomento in un numero intero
    int size = stoi(argv[1]);

    // Controllo se la conversione ha avuto successo
    if (size <= 0)
    {
        cerr << "Invalid size. Please provide a positive integer." << endl;
        return 1;
    }

    // Altrimenti, la dimensione è valida, procedo con il programma
    cout << "Size of the array: " << size << endl;

    // Creazione di un vettore ordinato
    int n = 0;
    vector<int> vector_1(size);
    iota(vector_1.begin(), vector_1.end(), n); // Riempie il vettore con valori crescenti

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> vector_1_merge = vector_1;
    vector<int> vector_1_bubble = vector_1;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average1_merge = TempiMerge(vector_1_merge);
    double average1_bubble = TempiBubble(vector_1_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "Media dei tempi per l'algoritmo MERGE di un vettore completamente ordinato: " << average1_merge << " microsecondi" << endl;
    cout << "Media dei tempi per l'algoritmo BUBBLE di un vettore completamente ordinato: " << average1_bubble << " microsecondi" << endl;

    // Creazione di un vettore randomico
    vector<int> vector_2(size);
    srand(1);
    for (int i = 0; i < size; i++)
    {
        vector_2[i] = rand() % 1000; // Numeri casuali nell'intervallo [0, 999]
    }

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> vector_2_merge = vector_2;
    vector<int> vector_2_bubble = vector_2;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average2_merge = TempiMerge(vector_2_merge);
    double average2_bubble = TempiBubble(vector_2_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "Media dei tempi per l'algoritmo MERGE per un vettore randomico: " << average2_merge << " microsecondi" << endl;
    cout << "Media dei tempi per l'algoritmo BUBBLE per un vettore randomico: " << average2_bubble << " microsecondi" << endl;

    // Creazione di un vettore ordinato da perturbare
    vector<int> vector_3(size);
    iota(vector_3.begin(), vector_3.end(), n);
    // Perturbazione del vettore ordinato
    vector<int> vector_3_perturbed = vector_3;
    for (int i = 0; i < size; i++)
    {
        vector_3_perturbed[i] += double(rand() % 10);
    }

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> vector_3_merge = vector_3_perturbed;
    vector<int> vector_3_bubble = vector_3_perturbed;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average3_merge = TempiMerge(vector_3_merge);
    double average3_bubble = TempiBubble(vector_3_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "Media dei tempi per l'algoritmo MERGE per un vettore leggermnente randomico: " << average3_merge << " microsecondi" << endl;
    cout << "Media dei tempi per l'algoritmo BUBBLE per un vettore leggermente randomico: " << average3_bubble << " microsecondi" << endl;

    return 0;
}

double TempiMerge(vector<int>& vector_merge)
{
    vector<unsigned int> tempi_merge;
    unsigned int numIterazioni = 10;

    for (unsigned int i = 0; i < numIterazioni; i++)
    {
        // Misurazione del tempo per l'algoritmo Merge Sort
        steady_clock::time_point start_merge = steady_clock::now();
        MergeSort(vector_merge, 0, vector_merge.size() - 1);
        steady_clock::time_point stop_merge = steady_clock::now();
        double duration_merge = duration_cast<microseconds>(stop_merge - start_merge).count();
        tempi_merge.push_back(duration_merge);
    }

    double sum_merge = 0;
    for (auto value : tempi_merge)
    {
        sum_merge += value;
    }
    return sum_merge / tempi_merge.size();
}

double TempiBubble(vector<int>& vector_bubble) {

    vector<unsigned int> tempi_bubble;
    unsigned int numIterazioni = 10;

    for (unsigned int i = 0; i < numIterazioni; i++)
    {
        // Misurazione del tempo per l'algoritmo Bubble Sort
        steady_clock::time_point start_bubble = steady_clock::now();
        BubbleSort(vector_bubble);
        steady_clock::time_point stop_bubble = steady_clock::now();
        double duration_bubble = duration_cast<microseconds>(stop_bubble - start_bubble).count();
        tempi_bubble.push_back(duration_bubble);
    }

    double sum_bubble = 0;
    for (auto value : tempi_bubble)
    {
        sum_bubble += value;
    }
    return sum_bubble / tempi_bubble.size();
}


