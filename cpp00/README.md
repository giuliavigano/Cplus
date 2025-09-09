# CPP Module 00

## 🎯 Obiettivo del Modulo

Il modulo CPP00 introduce i concetti fondamentali del C++ e della programmazione orientata agli oggetti (OOP). È il primo modulo della serie C++ di 42 e si concentra sull'apprendimento della sintassi base del C++, l'uso delle classi e la gestione dell'input/output.

## 📋 Concetti Introdotti

- **Transizione da C a C++**: Sintassi base, namespace, stream I/O
- **Programmazione Orientata agli Oggetti**: Classi, oggetti, incapsulamento
- **Gestione dello stato**: Membri privati/pubblici, membri statici
- **RAII**: Resource Acquisition Is Initialization
- **Composizione**: Relazioni "has-a" tra classi
- **Standard C++98**: Limitazioni e best practices

---

### Exercise 00: Megaphone
**Richieste dell'esercizio**: Programma che converte argomenti in maiuscolo. Senza argomenti stampa `* LOUD AND UNBEARABLE FEEDBACK NOISE *`. File: `Makefile`, `megaphone.cpp`.

**Concetti teorici**: 
- **Namespace std**: Organizzazione della libreria standard (`std::cout` vs `printf()`)
- **Stream I/O**: Type-safe input/output con operatori `<<` 
- **Differenze C/C++**: Header senza `.h`, gestione stringhe migliorata

**Esempio di output**:
```bash
./megaphone "hello world" "test"
HELLO WORLDTEST

./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

### Exercise 01: My Awesome PhoneBook
**Richieste dell'esercizio**: Rubrica con classi `PhoneBook` (max 8 contatti, sostituzione circolare) e `Contact` (5 campi obbligatori). Comandi: ADD, SEARCH (visualizzazione tabellare 10 caratteri), EXIT.

**Concetti teorici**:
- **Classi e Oggetti**: Template (classe) vs istanza (oggetto)
- **Incapsulamento**: Membri privati (data hiding) vs interfaccia pubblica
- **Composizione**: PhoneBook "contiene" array di Contact (relazione "has-a")
- **Costruttori**: Inizializzazione automatica dello stato interno

**Esempio di output**:
```bash
Enter command (ADD, SEARCH, EXIT): SEARCH
     Index|First Name| Last Name|  Nickname
         0|     Marco|     Rossi|    MarcoR
         1|     Lunga...|    Cognome|      Test
```

---

### Exercise 02: The Job Of Your Dreams
**Richieste dell'esercizio**: Ricreare `Account.cpp` basandosi su header, test e log forniti. Output deve matchare perfettamente il file di log (eccetto timestamp). **Non obbligatorio**.

**Concetti teorici**:
- **Membri statici**: Variabili/metodi condivisi tra tutte le istanze (contatori globali)
- **Stato globale vs locale**: Dati della classe vs dati dell'istanza singola
- **Costruttori/Distruttori**: Gestione automatica del ciclo di vita degli oggetti
- **Const correctness**: Metodi che garantiscono immutabilità dello stato

**Esempio di output**:
```bash
[19920104_091532] index:0;amount:42;created
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
```

---

## 🎯 Progressione dell'Apprendimento

1. **Ex00**: Abbandono del C procedurale → Sintassi C++ base
2. **Ex01**: Primo approccio OOP → Classi, incapsulamento, composizione  
3. **Ex02**: Gestione avanzata → Membri statici, stato condiviso, RAII

**Dal Procedurale all'Object-Oriented**: Ogni esercizio costruisce sui concetti precedenti, introducendo gradualmente i principi fondamentali dell'OOP.

---

## 🛠️ Come Compilare ed Eseguire

**Semplice**: Ogni cartella ha un Makefile. Esegui:
```bash
cd ex00/  # o ex01/ o ex02/
make
./nome_programma
```

**Flag utilizzati**: `-Wall -Wextra -Werror -std=c++98`  
**Comandi Makefile**: `make` (compila), `make clean` (pulisce), `make re` (ricompila)

---

## 🎯 Preparazione ai Moduli Successivi

- **cpp01**: Gestione memoria, puntatori, reference
- **cpp02**: Overloading operatori, forme canoniche
- **cpp03**: Ereditarietà, relazioni tra classi
- **cpp04**: Polimorfismo, classi astratte

**La padronanza di cpp00 è essenziale**: I concetti di classe, incapsulamento e RAII sono i fondamenti per tutti i moduli successivi.
