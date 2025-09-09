# CPP Module 00

## 🎯 Obiettivo del Modulo

Il modulo CPP00 introduce i concetti fondamentali del C++ e della programmazione orientata agli oggetti (OOP). È il primo modulo della serie C++ di 42 e si concentra sull'apprendimento della sintassi base del C++, l'uso delle classi e la gestione dell'input/output.

## 📋 Contenuti del Modulo

### Standard Utilizzato
- **C++98**: Tutti i progetti devono essere compatibili con lo standard C++98
- **Compilatore**: `c++` con flag `-Wall -Wextra -Werror -std=c++98`

### Concetti Introdotti
- Sintassi base del C++
- Namespace e libreria standard
- Classi e oggetti
- Input/output con iostream
- Gestione della memoria
- Array di oggetti
- Metodi pubblici e privati


### Exercise 00: Megaphone - Transizione da C a C++
**Obiettivo**: Familiarizzare con la sintassi C++ di base e i namespace.

**Concetti teorici fondamentali**:

#### **Namespace std**
Il C++ introduce il concetto di namespace per evitare conflitti di nomi. La libreria standard è contenuta nel namespace `std`, da cui `std::cout` invece del `printf()` del C.

#### **Stream di I/O**
- **std::cout**: Stream di output che sostituisce `printf()`
- **std::endl**: Manipolatore che inserisce un newline e forza il flush del buffer
- Approccio type-safe rispetto alle funzioni C

---

### Exercise 01: My Awesome PhoneBook - Introduzione alle Classi
**Obiettivo**: Comprendere i principi base della Programmazione Orientata agli Oggetti.

**Concetti teorici fondamentali**:

#### **Classi e Oggetti**
Una **classe** è un template che definisce le proprietà e i comportamenti di un oggetto. Un **oggetto** è un'istanza specifica di una classe.

#### **Incapsulamento**
- **Membri privati**: Dati nascosti all'esterno della classe (data hiding)
- **Membri pubblici**: Interfaccia accessibile dall'esterno
- **Principio**: Separare l'interfaccia dall'implementazione

#### **Costruttori**
Metodi speciali chiamati automaticamente alla creazione di un oggetto per inizializzare lo stato interno.

#### **Composizione**
La classe PhoneBook "contiene" oggetti Contact, dimostrando la relazione "has-a" tra classi.

#### **Array di Oggetti**
Gestione di collezioni di oggetti con limitazioni di dimensione fissa (tipico del C++98).

---

### Exercise 02: The Job Of Your Dreams - Membri Statici e Gestione dello Stato
**Obiettivo**: Comprendere la differenza tra stato dell'istanza e stato della classe.

**Concetti teorici fondamentali**:

#### **Membri Statici**
- **Variabili statiche**: Condivise tra tutte le istanze della classe
- **Metodi statici**: Operano sui dati statici, non su istanze specifiche
- **Uso**: Mantenere informazioni globali sulla classe (contatori, totali)

#### **Costruttori e Distruttori**
- **Costruttore**: Inizializza lo stato dell'oggetto, può aggiornare contatori statici
- **Distruttore**: Cleanup automatico quando l'oggetto esce dallo scope

#### **RAII (Resource Acquisition Is Initialization)**
Concetto fondamentale del C++: le risorse vengono acquisite nel costruttore e rilasciate nel distruttore.

#### **Stato Globale vs Stato Locale**
Distinzione tra:
- Dati dell'istanza (saldo del singolo conto)
- Dati della classe (totale di tutti i conti)

#### **Const Correctness**
Metodi `const` che garantiscono di non modificare lo stato dell'oggetto.

---

## 🎯 Progressione dell'Apprendimento

### **Dal Procedurale all'Object-Oriented**
1. **Ex00**: Sintassi C++ base, abbandono delle funzioni C
2. **Ex01**: Prima classe, incapsulamento, composizione
3. **Ex02**: Membri statici, gestione avanzata dello stato

### **Principi OOP Introdotti**
- **Incapsulamento**: Nascondere i dettagli implementativi
- **Astrazione**: Fornire interfacce semplici per operazioni complesse
- **Composizione**: Costruire oggetti complessi da oggetti più semplici

## 🛠️ Come Compilare ed Eseguire

### Prerequisiti
- Compilatore C++ compatibile con lo standard C++98
- Make utility
- Sistema Unix/Linux o macOS

### Compilazione Generale

Ogni esercizio include un **Makefile** con regole standardizzate. Per compilare qualsiasi esercizio:

#### Regole del Makefile
```bash
# Compila il programma
make
# oppure
make all

# Rimuove i file oggetto generati
make clean

# Ricompila completamente da zero (equivale a: make clean + make)
make re
```

#### Flag di Compilazione Utilizzati
```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

**Spiegazione dei flag**:
- `-Wall`: Abilita la maggior parte dei warning
- `-Wextra`: Abilita warning aggiuntivi
- `-Werror`: Tratta i warning come errori (compilazione fallisce)
- `-std=c++98`: Forza l'uso dello standard C++98

### Istruzioni Specifiche per Esercizio

#### Exercise 00: Megaphone
```bash
cd ex00/
make
./megaphone "hello world"
# Output: HELLO WORLD

# Test senza argomenti
./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

#### Exercise 01: PhoneBook
```bash
cd ex01/
make
./phonebook

# Nel programma, usa questi comandi:
# ADD    - per aggiungere un contatto
# SEARCH - per cercare contatti
# EXIT   - per uscire
```

**Esempio di sessione**:
```
Enter command (ADD, SEARCH, EXIT): ADD
Enter first name: Marco
Enter last name: Rossi
Enter nickname: MarcoR
Enter phone number: 1234567890
Enter darkest secret: Ama i gatti

Enter command (ADD, SEARCH, EXIT): SEARCH
     Index|First Name| Last Name|  Nickname
         0|     Marco|     Rossi|    MarcoR
Enter index to display: 0
First Name: Marco
Last Name: Rossi
Nickname: MarcoR
Phone Number: 1234567890
Darkest Secret: Ama i gatti
```

#### Exercise 02: Account
```bash
cd ex02/
make
./account

# Il programma eseguirà automaticamente i test predefiniti
# L'output deve corrispondere al file 19920104_091532.log
```

## 🎯 Preparazione ai Moduli Successivi

Questo modulo costituisce la base per:
- **cpp01**: Gestione della memoria, puntatori e referenze
- **cpp02**: Overloading degli operatori e forme canoniche ortodosse  
- **cpp03**: Ereditarietà e relazioni tra classi
- **cpp04**: Polimorfismo e classi astratte

La padronanza dei concetti di cpp00 è **essenziale** per affrontare con successo i moduli successivi, dove questi principi verranno estesi e approfonditi.
