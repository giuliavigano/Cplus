# CPP Module 03

## 🎯 Obiettivo del Modulo

Il modulo CPP03 introduce l'**ereditarietà** in C++, uno dei pilastri fondamentali della programmazione orientata agli oggetti. Si concentra sulla creazione di gerarchie di classi, il polimorfismo di base, la catena di costruttori/distruttori e i problemi dell'ereditarietà multipla con il diamond problem.

## 📋 Concetti Introdotti

- **Ereditarietà**: Creazione di classi derivate da classi base (relazione "is-a")
- **Constructor/Destructor chaining**: Ordine di chiamata in gerarchie di classi
- **Overriding**: Ridefinizione di metodi nelle classi derivate  
- **Access specifiers**: public, protected, private inheritance
- **Multiple inheritance**: Ereditarietà da più classi base
- **Diamond problem**: Ambiguità nell'ereditarietà multipla e virtual inheritance

## 🏗️ Inheritance e Orthodox Canonical Form

**Tutte le classi continuano a seguire l'OCF**, ma ora con considerazioni aggiuntive:

- **Base class OCF**: La classe base deve avere destructor virtuale (appreso nei moduli successivi)
- **Derived class OCF**: Le classi derivate ereditano e possono ridefinire l'OCF
- **Constructor chaining**: Costruttore base → costruttore derivato
- **Destructor chaining**: Distruttore derivato → distruttore base (ordine inverso)

---

### Exercise 00: Aaaaand... OPEN!
**Richieste dell'esercizio**: Classe `ClapTrap` in OCF con attributi `name` (parametro), `hit points (10)`, `energy points (10)`, `attack damage (0)`. Metodi: `attack()`, `takeDamage()`, `beRepaired()`. Tutti i metodi stampano messaggi descrittivi.

**Concetti teorici**:
- **Base class design**: Creazione di una classe base robusta per future derivazioni
- **Encapsulation**: Attributi privati con interfaccia pubblica per manipolazione
- **Resource management**: Hit points e energy points come risorse limitate
- **Method messaging**: Output descrittivo per debugging e comprensione del flusso

**Esempio di output**:
```bash
ClapTrap constructor called
ClapTrap Warrior attacks Goblin, causing 0 points of damage!
ClapTrap Warrior takes 5 damage!
ClapTrap Warrior repairs itself for 3 points!
ClapTrap destructor called
```

---

### Exercise 01: Serena, my love!
**Richieste dell'esercizio**: Classe `ScavTrap` che eredita da `ClapTrap`. Valori diversi: `hit points (100)`, `energy points (50)`, `attack damage (20)`. Costruttore, distruttore e `attack()` con messaggi diversi. Capacità speciale: `guardGate()`.

**Concetti teorici**:
- **Inheritance syntax**: `class ScavTrap : public ClapTrap`
- **Constructor chaining**: Costruttore base chiamato prima del derivato
- **Method overriding**: Ridefinizione di `attack()` con comportamento diverso
- **Member initialization**: Inizializzazione degli attributi ereditati con valori diversi

**Esempio di output**:
```bash
ClapTrap constructor called    # Base costructor
ScavTrap constructor called    # Derived constructor
ScavTrap Warrior attacks Goblin, causing 20 points of damage!
ScavTrap Warrior is now in Gate keeper mode.
ScavTrap destructor called     # Derived destructor
ClapTrap destructor called     # Base destructor
```

---

### Exercise 02: Repetitive work
**Richieste dell'esercizio**: Classe `FragTrap` che eredita da `ClapTrap`. Valori: `hit points (100)`, `energy points (100)`, `attack damage (30)`. Messaggi diversi per costruzione/distruzione. Capacità speciale: `highFivesGuys()`.

**Concetti teorici**:
- **Parallel inheritance**: Due classi derivate dalla stessa base
- **Specialization**: Ogni classe derivata ha caratteristiche e comportamenti unici
- **Code reuse**: Funzionalità comune nella base, specializzazioni nelle derivate
- **Polymorphism foundation**: Base per il polimorfismo dei moduli successivi

**Esempio di output**:
```bash
ClapTrap constructor called
FragTrap constructor called
FragTrap Warrior attacks Goblin, causing 30 points of damage!
FragTrap requests positive high fives!
FragTrap destructor called
ClapTrap destructor called
```

---

### Exercise 03: Now it's weird!
**Richieste dell'esercizio**: Classe `DiamondTrap` che eredita da **entrambi** `FragTrap` E `ScavTrap` (ereditarietà multipla). Attributo `name` privato identico a quello di `ClapTrap`. Caratteristiche miste: HP da FragTrap, Energy da ScavTrap, Attack damage da FragTrap, metodo `attack()` da ScavTrap. Metodo speciale: `whoAmI()`. **Non obbligatorio**.

**Concetti teorici**:
- **Multiple inheritance**: `class DiamondTrap : public FragTrap, public ScavTrap`
- **Diamond problem**: Due percorsi verso `ClapTrap` → ambiguità
- **Virtual inheritance**: Soluzione con `virtual` per singola istanza della base
- **Name hiding**: Gestione dei conflitti di nomi tra classi parent

**Esempio di output**:
```bash
ClapTrap constructor called    # Una sola volta (virtual inheritance)
FragTrap constructor called
ScavTrap constructor called  
DiamondTrap constructor called
DiamondTrap Warrior attacks Goblin, causing 30 points of damage! # ScavTrap::attack
My name is Warrior and my ClapTrap name is Warrior_clap_name
DiamondTrap destructor called
ScavTrap destructor called
FragTrap destructor called
ClapTrap destructor called
```

---

## 🎯 Progressione dell'Apprendimento

1. **Ex00**: Base class design → Fondamenta solide per ereditarietà
2. **Ex01**: Single inheritance → Prima derivazione con override
3. **Ex02**: Parallel inheritance → Multiple derivazioni dalla stessa base  
4. **Ex03**: Multiple inheritance → Diamond problem e virtual inheritance

**Dalla classe singola alle gerarchie complesse**: Costruzione progressiva di sistemi di classi sempre più sofisticati.

---

## 🛠️ Come Compilare ed Eseguire

**Semplice**: Ogni cartella ha un Makefile. Esegui:
```bash
cd ex00/  # o ex01/ o ex02/ o ex03/
make
./claptrap  # o nome appropriato
```

**Flag utilizzati**: `-Wall -Wextra -Werror -std=c++98`  
**Flag opzionali**: `-Wshadow` per rilevare name hiding (ex03)

---

## 🎯 Preparazione ai Moduli Successivi

- **cpp04**: Polimorfismo, virtual functions, classi astratte
- **cpp05-09**: Gerarchie complesse, exception handling, advanced inheritance patterns
- **Design patterns**: Template method, Factory, Strategy basati su ereditarietà

**L'ereditarietà è fondamentale**: Base per polimorfismo, design patterns e architetture software complesse. La comprensione della catena costruttori/distruttori è cruciale per il memory management avanzato.
