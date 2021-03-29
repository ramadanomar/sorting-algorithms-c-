#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//Variable Globale
int v[1000];
int n;

//Subprograme


void loadingBar()
{

    char a = 177, b = 219; // caractere pt loading bar

    printf("\n\n");
    printf("\n\nSe incarca...\n\n");


    //Bara de loadare 
    for (int i = 0; i < 26; i++)
    {
        Sleep(100);
        printf("%c", a);
    }
    //Setarea cursorului la punctul de initliaziaare

    printf("\r");

    // Printeaza loading bar sectionul
    for (int i = 0; i < 26; i++)
    {
        Sleep(100);
        printf("%c", b);
    }
    Sleep(1000); // 1000 = O sec
}

//Operatii Vector
void citire()
{

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "v[" << i << "] = "; // Citim vectorul
        cin >> v[i];
    }
}

void afisare()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " "; // Afisam vectorul
    }
}

//Selection Sort
void selectionSort()
{
    int i, j, min_idx;

    // Mutam marimea vectorului sortat treptat ( unul cate unuL )  
    for (i = 0; i < n; i++)
    {
        // Gasirea minimului in vectorul nesortat
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[min_idx])
                min_idx = j;

        //Interschimbarea elementelor  
        swap(v[min_idx], v[i]);
    }
}

//Bubble Sort
void bubbleSort()
{
    int i, j;
    for (i = 0; i < n; i++)

        // Ultimele i elemente sunt deja sortate
        for (j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
}

void bubbleSortRec(int n)
{
    // Caz de baza
    if (n == 1)
        return;

    // Dupa prima iteratie
    // Cel mai mare element este mutat catre fata printr-o bula
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1])
            swap(v[i], v[i + 1]);

    // Cel mai mare element este fixat, incepere cu urmatoarele elemente s.a.m.d
    bubbleSortRec(n - 1);
}

//Insertion Sort
void insertionSort()
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = v[i];
        j = i - 1;

        //Miscam elementele mai in fata
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void insertionSortRecursiv(int n)
{
    // Caz de baza 
    if (n <= 1)
        return;

    // Sortam vectorul
    insertionSortRecursiv(n - 1);

    // Inseram ultimul element in pozitia corecta
    int last = v[n - 1];
    int j = n - 2;

    // Miscam toate elementele care sunt
    //in bula catre o pozitia mai in fata
    while (j >= 0 && v[j] > last)
    {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = last;
}

//Quick Sort
int partition(int low, int high)
{
    int pivot = v[high]; // pivota 
    int i = (low - 1); // Indexeaza pivota dreapta

    for (int j = low; j <= high - 1; j++)
    {
        // Daca elementul curent este mai mic decat pivota folosita de quicksort
        if (v[j] < pivot)
        {
            i++; // Incrementeaza element
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        /* pi partitioneaza  index, arr[p] is now
        at right place */
        int pi = partition(low, high);

        // Sortam separat 
        // Partitia 1 si Partitia 2
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

//Heap Sort
void heapify(int n, int i)
{
    int largest = i; // cel mai mare devine radacina
    int l = 2 * i + 1; // stranga = 2*i + 1
    int r = 2 * i + 2; // dreapta = 2*i + 2

    // Daca copilul stang este mai mare ca radacina se transforma copilul in radacina
    if (l < n && v[l] > v[largest])
        largest = l;

    // Daca copilul drept este mai mare ca radacina se transforma copilul in radacina
    if (r < n && v[r] > v[largest])
        largest = r;

    // Daca cel mai mare nu este radacina
    if (largest != i) {
        swap(v[i], v[largest]);

        // Transformam iar arborii afectati
        heapify(n, largest);
    }
}

void heapSort()
{
    // Construire Arbor
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Extragerea de arbor
    for (int i = n - 1; i > 0; i--) {
        // Mutat catre root
        swap(v[0], v[i]);

        // apelare functie catre heap-ul maxificat
        heapify(i, 0);
    }
}

int main()
{
    //System Settings
    SetConsoleTitle(TEXT("Proiect Atestat Informatica - Algoritmi de Sortare - Ramadan Omar")); // Setam titlul consolei
    system("color 0A");
    //system("color c2");
    MessageBox(nullptr, TEXT("Acest proiect a fost realizat de catre Ramadan Omar, elev al Colegiului National 'I.L. Caragiale' Bucuresti, avand ca profesor coordonator pe 'Iuliana Dumitrescu'.\n Proiectul este despre algoritmii de sortare si a fost realizat pe data de 18.03.2021. \nReproducerea acestui material este strict interzisa."), TEXT("ATENTIE!"), 0);

    char rasp;
    int sel;

    do
    {
        //Introducere
        cout << "\nBun venit la proiectul de Atestat la Informatica al lui Ramadan Omar\n";
        cout << "In acest proiect vom explora algoritmi de sortare oferiti de C++\n\n\n";

        //Optiuni
        cout << "1 - Citire Vector \n";
        cout << "2 - Afisare Vector \n";
        cout << "3 - Selection Sort - Complexitatea Timpului: O(n^2)\n";
        cout << "4 - Bubble Sort - Complexitatea Timpului: O(n^2)\n";
        cout << "5 - Bubble Sort Recursiv - Complexitatea Timpului: O(n^2)\n";
        cout << "6 - Insertion Sort - Complexitatea Timpului: O(n^2)\n";
        cout << "7 - Insertion Sort Recursiv - Complexitatea Timpului: O(n^2)\n";
        cout << "8 - Quick Sort - Complexitatea Timpului: O(n^2)\n";
        cout << "9 - Heap Sort - Complexitatea Timpului: O(nlogn)\n";
        cout << "0 - Clear Console\n";

        cout << "\nIndicati operatia dorita ";

        //Selectie
        cin >> sel;
        switch (sel)
        {
        case 1:
            cout << "\nCat de mare doriti sa fie vector-ul (ATENTIE! Vectorul nu este alocat dinamic) ";
            cin >> n;
            citire();
            break;
        case 2:
            cout << "\nVectorul afisat este: ";
            afisare();
            break;
        case 3:
            cout << "\nSelection Sort - Complexitatea Timpului: O(n^2)";
            loadingBar();
            cout << "\nSortarea a fost facuta cu Succes!\n";
            selectionSort();
            break;
        case 4:
            cout << "\nBubble Sort - Complexitatea Timpului: O(n^2)";
            loadingBar();
            cout << "\nSortarea a fost facuta cu Succes!\n";
            bubbleSort();
            break;
        case 5:
            cout << "\nBubble Sort Recursiv - Complexitatea Timpului: O(n^2)";
            loadingBar();
            cout << "\nSortarea a fost facuta cu Succes!\n";
            bubbleSortRec(n);
            break;
        case 6:
            cout << "\nInsertion Sort - Complexitatea Timpului: O(n^2)";
            loadingBar();
            cout << "\nSortarea a fost facuta cu Succes!\n";
            insertionSort();
            break;
        case 7:
            cout << "\nInsertion Sort Recursiv - Complexitatea Timpului: O(n^2)";
            loadingBar(); 
            cout << "\nSortarea a fost facuta cu Succes!\n";
            insertionSortRecursiv(n);
            break;
        case 8:
            cout << "\nQuick Sort - Complexitatea Timpului: O(n^2)";
            loadingBar(); 
            cout << "\nSortarea a fost facuta cu Succes!\n";
            quickSort(0, n - 1);
            break;
        case 9:
            cout << "\nHeap Sort - Complexitatea Timpului: O(nlogn)\n"; 
            loadingBar(); 
            cout << "\nSortarea a fost facuta cu Succes!\n";
            heapSort();
            break;
        case 0:
            system("CLS"); // clear screen
            break;
        default:
            cout << "Ooops... Nu am recunoscut Selectia. Va rugam sa selectati una din optiunile de mai sus. \n";
        }

        // Continuare/Terminare Executie Program.
        do
        {
            cout << "\n\nDoriti sa mai continuati? d/n \n";
            cin >> rasp;
        } while (rasp != 'n' && rasp != 'd');
    } while (rasp == 'd');

    return 0;
}