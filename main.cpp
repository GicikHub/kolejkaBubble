#include <iostream>
#include <fstream>

using namespace std;


// Element kolejki
struct kolejka
{
    int a;
    kolejka* next;
};


// Klasa do obslugi kolejki
class Sortowanie
{
private:
    kolejka* head;

public:

    // Konstruktor
    Sortowanie()
    {
        head = NULL;
    }


    // Destruktor
    ~Sortowanie()
    {
        while (head != NULL)
        {
            kolejka* temp = head;
            head = head->next;
            delete temp;
        }
    }


    // Dodawanie elementu na koniec kolejki
    void dodaj(int x)
    {
        kolejka* nowy = new kolejka;

        nowy->a = x;
        nowy->next = NULL;

        if (head == NULL)
        {
            head = nowy;
        }
        else
        {
            kolejka* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = nowy;
        }
    }


    // Wczytywanie danych z pliku
    void wczytajZPliku()
    {
        ifstream plik("liczby.txt");

        if (!plik.is_open())
        {
            cout << "Nie mozna otworzyc pliku!" << endl;
            return;
        }

        int x;

        // Czytamy do konca pliku
        while (plik >> x)
        {
            dodaj(x);
        }

        plik.close();

        cout << "Dane zostaly wczytane." << endl;
    }


    // Wypisywanie kolejki
    void wypisz()
    {
        if (head == NULL)
        {
            cout << "Kolejka jest pusta." << endl;
            return;
        }

        kolejka* temp = head;

        while (temp != NULL)
        {
            cout << temp->a << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    // Bubble Sort przez przepinanie wskaznikow
    void bubbleSort()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Za malo elementow do sortowania." << endl;
            return;
        }

        bool zamiana;

        do
        {
            zamiana = false;

            kolejka** pp = &head;

            while ((*pp) != NULL && (*pp)->next != NULL)
            {
                kolejka* pierwszy = *pp;
                kolejka* drugi = pierwszy->next;

                // Jezeli elementy sa w zlej kolejnosci
                if (pierwszy->a > drugi->a)
                {
                    // Przepinamy wskazniki

                    pierwszy->next = drugi->next;
                    drugi->next = pierwszy;
                    *pp = drugi;

                    zamiana = true;

                    pp = &(pierwszy->next);
                }
                else
                {
                    pp = &(pierwszy->next);
                }
            }

        } while (zamiana);

        cout << "Kolejka zostala posortowana." << endl;
    }


    // Zapisywanie do pliku
    void zapiszDoPliku()
    {
        ofstream plik("wyjscie.txt");

        if (!plik.is_open())
        {
            cout << "Nie mozna utworzyc pliku!" << endl;
            return;
        }

        kolejka* temp = head;

        while (temp != NULL)
        {
            plik << temp->a << " ";
            temp = temp->next;
        }

        plik.close();

        cout << "Dane zostaly zapisane do pliku." << endl;
    }
};


// Funkcja main
int main()
{
    Sortowanie kolejka;

    int wybor;

    do
    {
        cout << endl;
        cout << "==============================" << endl;
        cout << "            MENU" << endl;
        cout << "==============================" << endl;
        cout << "1. Wczytaj z pliku" << endl;
        cout << "2. Wypisz kolejke" << endl;
        cout << "3. Posortuj" << endl;
        cout << "4. Zapisz do pliku" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "==============================" << endl;

        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            kolejka.wczytajZPliku();
            break;

        case 2:
            cout << "Kolejka: ";
            kolejka.wypisz();
            break;

        case 3:
            kolejka.bubbleSort();
            break;

        case 4:
            kolejka.zapiszDoPliku();
            break;

        case 0:
            cout << "Koniec programu." << endl;
            break;

        default:
            cout << "Nieprawidlowa opcja!" << endl;
        }

    } while (wybor != 0);

    return 0;
}

