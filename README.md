Sortowanie kolejki w C++
Opis projektu

Program w języku C++, który implementuje kolejkę przy pomocy listy jednokierunkowej.

Program umożliwia:

wczytanie liczb z pliku,

wyświetlenie elementów kolejki,

sortowanie liczb algorytmem Bubble Sort,

zapisanie wyników do pliku,

zarządzanie pamięcią za pomocą wskaźników.

Sortowanie odbywa się poprzez przepinanie wskaźników, a nie zamianę wartości znajdujących się w elementach kolejki.

Funkcje programu

Program posiada następujące opcje:

==============================
            MENU
==============================
1. Wczytaj z pliku
2. Wypisz kolejke
3. Posortuj
4. Zapisz do pliku
0. Wyjscie
==============================

1. Wczytaj z pliku

Program odczytuje liczby całkowite z pliku:

liczby.txt


Każda odczytana liczba jest dodawana na koniec kolejki.

Przykładowa zawartość pliku:

8 3 15 1 7 4 10 2

2. Wypisz kolejkę

Wyświetla wszystkie elementy znajdujące się aktualnie w kolejce.

Przykład:

Kolejka: 8 3 15 1 7 4 10 2

3. Posortuj

Sortuje elementy kolejki rosnąco za pomocą algorytmu Bubble Sort.

Przed sortowaniem:

8 3 15 1 7 4 10 2


Po sortowaniu:

1 2 3 4 7 8 10 15


Algorytm sortowania wykorzystuje przepinanie elementów listy za pomocą wskaźników:

pierwszy->next = drugi->next;
drugi->next = pierwszy;
*pp = drugi;

4. Zapisz do pliku

Zawartość kolejki zostaje zapisana do pliku:

wyjscie.txt


Przykład:

1 2 3 4 7 8 10 15

0. Wyjście

Kończy działanie programu.

Struktura danych

Do przechowywania elementów została wykorzystana struktura:

struct kolejka
{
    int a;
    kolejka* next;
};


Każdy element zawiera:

a – wartość liczbową,

next – wskaźnik na kolejny element listy.

Pierwszy element jest przechowywany za pomocą wskaźnika:

kolejka* head;

Klasa Sortowanie

Cała obsługa kolejki znajduje się w klasie Sortowanie.

Najważniejsze metody:

Metoda	Opis
Sortowanie()	Konstruktor inicjalizujący kolejkę
~Sortowanie()	Destruktor zwalniający pamięć
dodaj(int x)	Dodaje element na koniec kolejki
wczytajZPliku()	Wczytuje liczby z liczby.txt
wypisz()	Wyświetla zawartość kolejki
bubbleSort()	Sortuje kolejkę rosnąco
zapiszDoPliku()	Zapisuje kolejkę do wyjscie.txt
Zarządzanie pamięcią

Elementy kolejki są tworzone dynamicznie za pomocą new:

kolejka* nowy = new kolejka;


Pamięć jest zwalniana w destruktorze klasy za pomocą delete:

~Sortowanie()
{
    while (head != NULL)
    {
        kolejka* temp = head;
        head = head->next;
        delete temp;
    }
}


Dzięki temu pamięć zajmowana przez elementy kolejki zostaje zwolniona po zakończeniu działania obiektu.

Wymagania

Do uruchomienia programu potrzebny jest kompilator C++, np.:

GCC / g++

MinGW

Visual Studio

Code::Blocks

Program korzysta ze standardowych bibliotek:

#include <iostream>
#include <fstream>

Kompilacja

Przy użyciu g++:

g++ main.cpp -o program


Uruchomienie w systemie Windows:

program.exe


Linux / macOS:

./program

Pliki projektu
.
├── main.cpp
├── liczby.txt
├── wyjscie.txt
└── README.md

main.cpp

Główny plik programu zawierający implementację kolejki, sortowania oraz menu.

liczby.txt

Plik wejściowy zawierający liczby przeznaczone do wczytania.

Przykład:

12 5 8 1 20 3 7

wyjscie.txt

Plik wynikowy, do którego program zapisuje zawartość kolejki.

Przykładowe działanie

Po uruchomieniu programu:

==============================
            MENU
==============================
1. Wczytaj z pliku
2. Wypisz kolejke
3. Posortuj
4. Zapisz do pliku
0. Wyjscie
==============================
Wybierz opcje: 1

Dane zostaly wczytane.

Wybierz opcje: 2
Kolejka: 12 5 8 1 20 3 7

Wybierz opcje: 3
Kolejka zostala posortowana.

Wybierz opcje: 2
Kolejka: 1 3 5 7 8 12 20

Wybierz opcje: 4
Dane zostaly zapisane do pliku.

Technologie

C++

Lista jednokierunkowa

Wskaźniki

Dynamiczna alokacja pamięci

ifstream / ofstream

Bubble Sort

Programowanie obiektowe

Autor

Projekt wykonany w języku C++ jako implementacja kolejki opartej na liście jednokierunkowej z możliwością sortowania danych.
