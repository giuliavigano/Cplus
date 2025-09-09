# CPP Module 04

## 🎯 Obiettivo del Modulo

Il modulo CPP04 introduce il **polimorfismo** e le **classi astratte**, completando i pilastri fondamentali dell'OOP. Si concentra su virtual functions, late binding, abstract classes e il concetto di interfacce in C++. È il culmine dell'apprendimento dell'ereditarietà e prepara per design patterns avanzati.

## 📋 Concetti Introdotti

- **Polimorfismo subtype**: Virtual functions e late binding (runtime polymorphism)
- **Virtual destructors**: Distruzione corretta in gerarchie polimorfiche
- **Abstract classes**: Classi con virtual functions pure (non istanziabili)
- **Interfaces**: Pure abstract classes come contratti di comportamento
- **Deep copy**: Gestione corretta della copia in gerarchie complesse
- **Memory management**: Gestione sicura di oggetti polimorfici

## 🏗️ Polimorfismo e Orthodox Canonical Form

**L'OCF si evolve per supportare il polimorfismo**:

- **Virtual destructor**: Obbligatorio nelle classi base polimorfiche
- **Deep copy**: Copy constructor e assignment operator devono gestire polimorfismo
- **Clone pattern**: Spesso necessario per copiare oggetti polimorfici
- **Protected members**: Accesso controllato per classi derivate

---

### Exercise 00: Polymorphism
**Richieste dell'esercizio**: Classe base `Animal` con attributo `type` protetto. Classi derivate `Dog` e `Cat` con `makeSound()` virtuale. Implementare anche `WrongAnimal`/`WrongCat` per dimostrare il comportamento senza virtual functions.

**Concetti teorici**:
- **Virtual functions**: `virtual makeSound()` per polimorfismo runtime
- **Late binding**: Risoluzione del metodo a runtime basata sul tipo effettivo
- **Protected members**: Accessibili dalle classi derivate ma non dall'esterno  
- **Virtual vs non-virtual**: Differenza nel comportamento con puntatori base

**Esempio di output**:
```bash
// Con virtual functions (comportamento corretto)
Animal* dog = new Dog();
dog->makeSound(); // "Woof!" (Dog::makeSound)

// Senza virtual functions (comportamento statico)
WrongAnimal* wrongCat = new WrongCat();
wrongCat->makeSound(); // Animal sound (WrongAnimal::makeSound)
```

---

### Exercise 01: I don't want to set the world on fire
**Richieste dell'esercizio**: Aggiungere classe `Brain` con array di 100 stringhe `ideas`. `Dog` e `Cat` hanno `Brain*` privato. Gestire array di `Animal*`, testare deep copy e virtual destructor per evitare memory leak.

**Concetti teorici**:
- **Virtual destructor**: `virtual ~Animal()` necessario per distruzione corretta
- **Deep copy**: Copy constructor deve copiare il `Brain`, non solo il puntatore
- **Polymorphic array**: Array di puntatori base che contengono oggetti derivati
- **Memory management**: new/delete corretti in gerarchie polimorfiche

**Esempio di output**:
```bash
Dog constructor called
Brain constructor called
// Deep copy test
Dog copy constructor called  // Nuovo Brain allocato
Brain constructor called
// Destructor chain
Dog destructor called
Brain destructor called      // Brain correttamente deallocato
Animal destructor called
```

---

### Exercise 02: Abstract class  
**Richieste dell'esercizio**: Rendere `Animal` non istanziabile (classe astratta) mantenendo il comportamento precedente. Possibile rinominare in `AAnimal`.

**Concetti teorici**:
- **Pure virtual functions**: `virtual makeSound() = 0` rende la classe astratta
- **Abstract classes**: Non possono essere istanziate direttamente
- **Concrete classes**: Classi derivate devono implementare tutte le funzioni pure
- **Interface contract**: La classe astratta definisce il contratto per le derivate

**Esempio di output**:
```bash
// Animal animal; // ERRORE: classe astratta non istanziabile
Animal* dog = new Dog(); // OK: Dog è concreta
dog->makeSound(); // "Woof!" - implementazione obbligatoria
```

---

### Exercise 03: Interface & recap
**Richieste dell'esercizio**: Sistema complesso con interfacce pure: `AMateria` (astratta), `Ice`/`Cure` (concrete), `ICharacter` (interfaccia), `Character` (implementazione), `IMateriaSource` (interfaccia), `MateriaSource` (implementazione). Inventory system con deep copy. **Non obbligatorio**.

**Concetti teorici**:
- **Pure interfaces**: Classi con solo virtual functions pure (simulano interfacce)
- **Multiple abstraction levels**: Interfacce, classi astratte, classi concrete
- **Clone pattern**: `virtual clone()` per copia polimorfica
- **Complex memory management**: Gestione di inventory con ownership semantics
- **Composition with interfaces**: Character usa IMateria, MateriaSource usa template

**Esempio di output**:
```bash
// Polimorfismo attraverso interfacce
IMateriaSource* src = new MateriaSource();
AMateria* ice = src->createMateria("ice");
ICharacter* character = new Character("hero");
character->equip(ice);
character->use(0, *target); 
// Output: "* shoots an ice bolt at target *"
```

---

## 🎯 Progressione dell'Apprendimento

1. **Ex00**: Virtual functions → Polimorfismo base e late binding
2. **Ex01**: Virtual destructor + Deep copy → Gestione sicura memoria polimorfica
3. **Ex02**: Abstract classes → Contratti e non-istanziabilità
4. **Ex03**: Interfaces complete → Sistema complesso con multiple astrazioni

**Dal polimorfismo semplice ai design patterns**: Costruzione di architetture software flessibili e maintainable.

---

## 🛠️ Come Compilare ed Eseguire

**Semplice**: Ogni cartella ha un Makefile. Esegui:
```bash
cd ex00/  # o ex01/ o ex02/ o ex03/
make
./polymorphism  # o nome appropriato
```

**Flag utilizzati**: `-Wall -Wextra -Werror -std=c++98`  
**Importante**: Testare memory leak con valgrind per esercizi con polimorfismo

---

## 🎯 Preparazione ai Moduli Successivi

- **cpp05-09**: Exception handling, template, STL, design patterns avanzati
- **Design patterns**: Strategy, Factory, Observer basati su polimorfismo
- **Modern C++**: Smart pointers, RAII avanzato, type erasure

**Il polimorfismo è la chiave**: Base per template metaprogramming, type erasure, e tutti i pattern architetturali moderni. La comprensione delle virtual functions è essenziale per C++ avanzato.
