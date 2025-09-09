# CPP Module 01

## 🎯 Obiettivo del Modulo

Il modulo CPP01 approfondisce la gestione della memoria in C++ introducendo i concetti di allocazione dinamica, puntatori, reference e gestione delle risorse. Si concentra sulla differenza tra stack e heap, la gestione corretta della memoria e l'uso appropriato di puntatori vs reference.

## 📋 Concetti Introdotti

- **Gestione della memoria**: Stack vs Heap, allocazione dinamica (new/delete)
- **Puntatori**: Sintassi, dereferenziazione, gestione della memoria
- **Reference**: Alternative ai puntatori, sintassi e vantaggi
- **RAII avanzato**: Distruttori e cleanup automatico delle risorse
- **Puntatori a funzioni membro**: Chiamate indirette ai metodi
- **File I/O**: Gestione dei file con stream C++

---

### Exercise 00: BraiiiiiiinnnzzzZ
**Richieste dell'esercizio**: Classe `Zombie` con attributo `name` privato e metodo `announce()`. Implementare `newZombie()` (heap allocation) e `randomChump()` (stack allocation). Determinare quando usare stack vs heap.

**Concetti teorici**:
- **Stack vs Heap**: Stack per variabili locali (distruzione automatica), Heap per oggetti che sopravvivono al scope
- **new/delete**: Allocazione dinamica della memoria, responsabilità del programmer
- **Distruttori**: Cleanup automatico, debugging della distruzione degli oggetti
- **Scope e lifetime**: Quando gli oggetti vengono creati/distrutti

**Esempio di output**:
```bash
Foo: BraiiiiiiinnnzzzZ...
Bar: BraiiiiiiinnnzzzZ...
Bar destroyed  # Distruttore automatico (stack)
Foo destroyed  # Distruttore manuale (heap)
```

---

### Exercise 01: Moar brainz!
**Richieste dell'esercizio**: Implementare `zombieHorde(int N, std::string name)` che alloca N zombi in un'unica allocazione. Inizializzare tutti gli zombi con lo stesso nome e testare con `announce()`.

**Concetti teorici**:
- **Array dinamici**: Allocazione contigua di memoria per array di oggetti
- **Single allocation**: `new[]` per allocare multipli oggetti in una volta
- **Inizializzazione di array**: Costruttori chiamati per ogni elemento
- **delete[]**: Deallocazione corretta di array dinamici

**Esempio di output**:
```bash
Zombie0: BraiiiiiiinnnzzzZ...
Zombie1: BraiiiiiiinnnzzzZ...
Zombie2: BraiiiiiiinnnzzzZ...
Zombie2 destroyed
Zombie1 destroyed
Zombie0 destroyed
```

---

### Exercise 02: HI THIS IS BRAIN
**Richieste dell'esercizio**: Programma che dimostra la differenza tra variabile, puntatore e reference alla stessa stringa. Stampa indirizzi di memoria e valori.

**Concetti teorici**:
- **Reference**: Alias per variabili esistenti, devono essere inizializzate
- **Puntatori vs Reference**: Puntatori possono essere null/reassegnati, reference no
- **Indirizzi di memoria**: `&` operator per ottenere l'indirizzo
- **Dereferenziazione**: `*` operator per accedere al valore puntato

**Esempio di output**:
```bash
Memory address of string: 0x7fff5fbff710
Memory address of stringPTR: 0x7fff5fbff710
Memory address of stringREF: 0x7fff5fbff710
Value of string: HI THIS IS BRAIN
Value of stringPTR: HI THIS IS BRAIN
Value of stringREF: HI THIS IS BRAIN
```

---

### Exercise 03: Unnecessary violence
**Richieste dell'esercizio**: Classe `Weapon` con `type`, `getType()`, `setType()`. Classi `HumanA` (sempre armato, Weapon nel costruttore) e `HumanB` (può essere disarmato, `setWeapon()`). Metodo `attack()` per entrambi.

**Concetti teorici**:
- **Reference vs Pointer design**: Quando usare reference (sempre valido) vs puntatori (può essere null)
- **Const reference**: `const std::string&` per evitare copie inutili
- **Composition**: Oggetti che contengono altri oggetti
- **Optional relationships**: HumanB può esistere senza Weapon

**Esempio di output**:
```bash
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```

---

### Exercise 04: Sed is for losers
**Richieste dell'esercizio**: Programma che prende filename, s1, s2 e crea `<filename>.replace` sostituendo ogni occorrenza di s1 con s2. Vietato `std::string::replace`.

**Concetti teorici**:
- **File I/O streams**: `std::ifstream`, `std::ofstream` per leggere/scrivere file
- **String manipulation**: `find()`, `substr()`, `append()` per elaborazione testo
- **Error handling**: Gestione di file non trovati, permessi, etc.
- **Resource management**: Chiusura automatica dei file con RAII

**Esempio di output**:
```bash
./replace file.txt "hello" "hi"
# Crea file.txt.replace con "hello" sostituito da "hi"
```

---

### Exercise 05: Harl 2.0
**Richieste dell'esercizio**: Classe `Harl` con metodi privati `debug()`, `info()`, `warning()`, `error()` e metodo pubblico `complain(std::string level)`. Usare puntatori a funzioni membro, non if/else.

**Concetti teorici**:
- **Puntatori a funzioni membro**: Sintassi `void (Class::*ptr)()` per puntare a metodi
- **Array di puntatori**: Organizzazione di multiple funzioni in array
- **Indirection**: Chiamate indirette tramite puntatori a funzione
- **Design patterns**: Evitare cascate di if/else con lookup table

**Esempio di output**:
```bash
harl.complain("DEBUG");
// Output: I love having extra bacon for my 7XL-double-cheese...
```

---

### Exercise 06: Harl filter
**Richieste dell'esercizio**: Filtrare i messaggi di Harl mostrando solo il livello specificato e superiori. Usare statement `switch`. **Non obbligatorio**.

**Concetti teorici**:
- **Switch statement**: Control flow alternativo a if/else chains
- **Fall-through**: Comportamento di switch senza break
- **Enumerazioni**: Mappare stringhe a valori numerici
- **Filtering**: Logica per determinare quali messaggi mostrare

**Esempio di output**:
```bash
./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free...
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

---

## 🎯 Progressione dell'Apprendimento

1. **Ex00-01**: Stack vs Heap → Gestione base della memoria dinamica
2. **Ex02**: Puntatori vs Reference → Comprensione delle differenze fondamentali
3. **Ex03**: Design choices → Quando usare reference vs puntatori
4. **Ex04**: File I/O → Gestione risorse esterne con RAII
5. **Ex05-06**: Function pointers → Programmazione funzionale e control flow

**Dalla gestione base alla gestione avanzata**: Focus sulla corretta gestione delle risorse e scelte di design appropriate.

---

## 🛠️ Come Compilare ed Eseguire

**Semplice**: Ogni cartella ha un Makefile. Esegui:
```bash
cd ex00/  # o ex01/ o ex02/ etc.
make
./nome_programma [argomenti]
```

**Flag utilizzati**: `-Wall -Wextra -Werror -std=c++98`  
**Comandi Makefile**: `make` (compila), `make clean` (pulisce), `make re` (ricompila)

**Importante**: Controllare memory leak con valgrind per esercizi con allocazione dinamica.

---

## 🎯 Preparazione ai Moduli Successivi

- **cpp02**: Overloading operatori, copia profonda vs superficiale
- **cpp03**: Ereditarietà, virtual functions
- **cpp04**: Polimorfismo, classi astratte
- **Moduli avanzati**: Smart pointers, gestione automatica memoria

**La gestione corretta della memoria è cruciale**: I concetti di RAII, new/delete e resource management sono fondamentali per tutto il C++ moderno.
