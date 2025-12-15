#include <stdio.h>

int Cap[3];        // Lista Principala (capetele)
int Valori[10];    // Datele din listele secundare
int Legaturi[10];  // Cursorii (cine urmeaza dupa cine)
int liber = 0;     // Urmatoarea pozitie goala in vectori

// Initializam capetele cu -1 (NULL)
void init() {
    for(int i = 0; i < 3; i++) Cap[i] = -1;
}

// Adaugare la inceputul listei
void adauga(int cat, int val) {
    if (liber >= 10) return; // Memorie plina

    Valori[liber] = val;        // 1. Scriem valoarea pe pozitia libera
    Legaturi[liber] = Cap[cat]; // 2. Noul element arata spre vechiul cap
    Cap[cat] = liber;           // 3. Capul categoriei devine noul element
    liber++;                    // 4. Trecem la urmatoarea pozitie libera
}

void afisare() {
    for(int i = 0; i < 3; i++) {
        printf("Cat %d: ", i);
        int curent = Cap[i]; // Pornim de la capul categoriei
        
        while(curent != -1) {
            printf("%d -> ", Valori[curent]);
            curent = Legaturi[curent]; // Mergem la urmatorul
        }
        printf("NULL\n");
    }
}

int main() {
    init();

    // Adaugam elemente
    adauga(0, 10);
    adauga(0, 20); // Va fi primul la Cat 0
    adauga(1, 99); // Cat 1
    
    afisare();
    return 0;
}