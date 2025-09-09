# CPP Module 02

## 🎯 Obiettivo del Modulo

Il modulo CPP02 introduce l'overloading degli operatori e la **Orthodox Canonical Form** (OCF). Si concentra sulla creazione di tipi numerici personalizzati, la gestione della copia degli oggetti e l'implementazione di operatori per rendere le classi utilizzabili come tipi nativi del linguaggio.

## 📋 Concetti Introdotti

- **Orthodox Canonical Form**: Standard di design per classi C++98 (Big Three + Default Constructor)
- **Operator overloading**: Ridefinizione degli operatori per classi personalizzate
- **Fixed-point arithmetic**: Numeri a virgola fissa per precisione controllata
- **Ad-hoc polymorphism**: Polimorfismo attraverso overloading di operatori
- **Deep vs Shallow copy**: Gestione corretta della copia degli oggetti
- **Static member functions**: Funzioni di utilità a livello di classe

## 🏗️ Orthodox Canonical Form (OCF)

**D'ora in poi tutte le classi seguiranno la Orthodox Canonical Form**, che include obbligatoriamente:

1. **Default Constructor**: Costruttore senza parametri
2. **Copy Constructor**: Costruttore di copia `Class(const Class& other)`
3. **Copy Assignment Operator**: Operatore di assegnazione `Class& operator=(const Class& other)`
4. **Destructor**: Distruttore per cleanup delle risorse

Questa forma garantisce che gli oggetti possano essere **creati, copiati, assegnati e distrutti** correttamente, fondamentale per la gestione sicura degli oggetti in C++.

---

### Exercise 00: My First Class in Orthodox Canonical Form
**Richieste dell'esercizio**: Classe `Fixed` per numeri a virgola fissa in OCF. Membri privati: `int` per valore, `static const int` per bits frazionari (8). Metodi pubblici: OCF + `getRawBits()`, `setRawBits()`.

**Concetti teorici**:
- **Orthodox Canonical Form**: I "Big Three" + default constructor per gestione sicura oggetti
- **Fixed-point numbers**: Alternative a float per precisione controllata e performance
- **Static const members**: Costanti condivise tra tutte le istanze
- **Raw value storage**: Rappresentazione interna dei numeri fixed-point

**Esempio di output**:
```bash
Default constructor called
Copy constructor called
Copy assignment operator called
0
0
0
Destructor called (×3)
```

---

### Exercise 01: Towards a more useful fixed-point number class
**Richieste dell'esercizio**: Estendere `Fixed` con costruttori `int` e `float`, metodi `toInt()`, `toFloat()` e overload operatore `<<` per output stream.

**Concetti teorici**:
- **Constructor overloading**: Multiple costruttori per diversi tipi di input
- **Type conversion**: Conversione tra fixed-point, int e float
- **Bit shifting**: Operazioni bitwise per aritmetica fixed-point (moltiplicazione/divisione per 2^8)
- **Stream operator overloading**: `operator<<` per integrazione con cout

**Esempio di output**:
```bash
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
```

---

### Exercise 02: Now we're talking
**Richieste dell'esercizio**: Overload completo operatori: 6 di confronto (`>`, `<`, `>=`, `<=`, `==`, `!=`), 4 aritmetici (`+`, `-`, `*`, `/`), 4 di incremento/decremento, funzioni statiche `min/max`.

**Concetti teorici**:
- **Comparison operators**: Implementazione confronti per ordinamento e uguaglianza
- **Arithmetic operators**: Operazioni matematiche mantenendo precisione fixed-point
- **Increment/decrement**: Pre/post incremento con valore ε minimo rappresentabile
- **Static utility functions**: `min()/max()` con overload const/non-const

**Esempio di output**:
```bash
0
0.00390625      // ++a (pre-increment)
0.00390625      // a
0.00390625      // a++ (post-increment)
0.0078125       // a (dopo post-increment)
10.1016         // b (5.05 * 2)
10.1016         // max(a, b)
```

---

### Exercise 03: BSP
**Richieste dell'esercizio**: Classe `Point` in OCF con attributi `Fixed const x, y`. Implementare funzione `bsp()` per determinare se un punto è interno a un triangolo usando Binary Space Partitioning. **Non obbligatorio**.

**Concetti teorici**:
- **Const member attributes**: Attributi immutabili dopo inizializzazione
- **Initialization lists**: Necessarie per membri const nel costruttore
- **Geometric algorithms**: BSP per determinazione punto-in-triangolo
- **Practical application**: Uso di fixed-point per calcoli geometrici precisi

**Esempio di output**:
```bash
Point(1.5, 1.5) inside triangle: true
Point(0, 0) on vertex: false
Point(2, 1) on edge: false
Point(5, 5) outside: false
```

---

## 🎯 Progressione dell'Apprendimento

1. **Ex00**: OCF fundamentals → Gestione sicura ciclo di vita oggetti
2. **Ex01**: Type conversion → Interoperabilità con tipi nativi
3. **Ex02**: Operator overloading completo → Tipo user-defined completamente funzionale
4. **Ex03**: Practical application → Uso in algoritmi reali

**Dalla gestione oggetti agli operatori personalizzati**: Creazione di tipi che si comportano come built-in types del linguaggio.

---

## 🛠️ Come Compilare ed Eseguire

**Semplice**: Ogni cartella ha un Makefile. Esegui:
```bash
cd ex00/  # o ex01/ o ex02/ o ex03/
make
./fixed  # o nome appropriato
```

**Flag utilizzati**: `-Wall -Wextra -Werror -std=c++98`  
**Funzioni consentite**: `roundf` (da `<cmath>`) solo per ex01-03

---

## 🎯 Preparazione ai Moduli Successivi

- **cpp03**: Ereditarietà, classi derivate e Orthodox Canonical Form ereditata
- **cpp04**: Polimorfismo, virtual functions e gestione polimorfica degli oggetti
- **Moduli avanzati**: Template, STL containers che richiedono classi copyable

**OCF è fondamentale**: Tutte le future classi useranno questo pattern per garantire comportamento sicuro e prevedibile degli oggetti.
