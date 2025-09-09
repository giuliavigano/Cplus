# CPP Projects - 42 School

## 🎯 Panoramica Generale

Questa repository contiene i progetti C++ del curriculum di 42 School, dal modulo **cpp00** al **cpp04**. Ogni modulo introduce progressivamente i concetti fondamentali del C++ e della programmazione orientata agli oggetti (OOP), costruendo una base solida per lo sviluppo software professionale.

## 📚 Progressione dell'Apprendimento C++

### Dal C Procedurale al C++ Object-Oriented

I moduli seguono una **progressione pedagogica precisa**, dove ogni concetto si basa sui precedenti:

1. **Sintassi e Transizione** (cpp00) → Abbandono del C, introduzione OOP base
2. **Memory Management** (cpp01) → Gestione dinamica della memoria  
3. **Operator Overloading** (cpp02) → Creazione di tipi user-defined
4. **Inheritance** (cpp03) → Gerarchie di classi e specializzazione
5. **Polymorphism** (cpp04) → Polimorfismo e classi astratte

---

## 📁 Moduli e Concetti Teorici

### [CPP Module 00](./cpp00/) - **Foundations: Namespaces, Classes & Basic I/O**
**Obiettivo**: Comprendere i fondamenti teorici dell'Object-Oriented Programming e la filosofia dietro la progettazione del C++.

**Per un approfondimento teorico completo sui concetti acquisiti**, consultare il README presente nella cartella dell'esercizio.

---

### [CPP Module 01](./cpp01/) - **Memory Management: Pointers, References & RAII**  
**Obiettivo**: Sviluppare una comprensione profonda della gestione delle risorse e della memoria, concetti centrali per lo sviluppo C++ professionale.

**Per un approfondimento teorico completo sui concetti acquisiti**, consultare il README presente nella cartella dell'esercizio.

---

### [CPP Module 02](./cpp02/) - **Ad-hoc Polymorphism & Orthodox Canonical Form**
**Obiettivo**: Creare tipi definiti dall'utente che si integrano perfettamente nel sistema di tipi del C++, comportandosi come tipi nativi del linguaggio.

**Per un approfondimento teorico completo sui concetti acquisiti**, consultare il README presente nella cartella dell'esercizio.

---

### [CPP Module 03](./cpp03/) - **Inheritance & Object Hierarchies**
**Obiettivo**: Comprendere come costruire e organizzare gerarchie di classi complesse, modellando relazioni del mondo reale attraverso specializzazione e generalizzazione.

**Per un approfondimento teorico completo sui concetti acquisiti**, consultare il README presente nella cartella dell'esercizio.

---

### [CPP Module 04](./cpp04/) - **Subtype Polymorphism & Abstract Classes**
**Obiettivo**: Padroneggiare il polimorfismo completo e i design pattern fondamentali, raggiungendo la piena comprensione dell'Object-Oriented Programming in C++.

**Per un approfondimento teorico completo sui concetti acquisiti**, consultare il README presente nella cartella dell'esercizio.

---

## 🎯 Competenze Teoriche Acquisite

### **Pilastri dell'Object-Oriented Programming Padroneggiati**

1. **🏗️ Incapsulamento (Encapsulation)**
   - **Data Hiding**: Principio fondamentale che nasconde i dettagli implementativi di una classe attraverso membri privati. I dati interni sono accessibili solo attraverso metodi pubblici controllati, prevenendo modifiche accidentali e mantenendo l'integrità dello stato interno.
   - **Interfacce controllate**: Le classi espongono solo i metodi necessari per l'interazione esterna, creando una barriera tra l'implementazione interna e il codice client. Questo permette modifiche interne senza impattare il codice che utilizza la classe.
   - **Separazione implementazione e interfaccia**: Distinzione netta tra cosa fa una classe (interfaccia pubblica) e come lo fa (implementazione privata). Questa separazione facilita manutenzione, testing e evoluzione del software.

2. **🧬 Ereditarietà (Inheritance)**
   - **Specializzazione e generalizzazione**: Processo di creazione di classi più specifiche da classi generali attraverso ereditarietà, permettendo di catturare relazioni gerarchiche naturali del dominio. Le classi derivate specializzano il comportamento generale della classe base.
   - **Riuso del codice**: Meccanismo per evitare duplicazione implementando funzionalità comuni nella classe base e specializzando solo ciò che differisce nelle classi derivate. Promuove maintainability e consistency.
   - **Catena costruttori e distruttori**: Sistema automatico che garantisce inizializzazione corretta dalle classi base alle derivate durante costruzione, e cleanup nell'ordine opposto durante distruzione, assicurando gestione corretta delle dipendenze.

3. **🎭 Polimorfismo (Polymorphism)**
   - **Ad-hoc attraverso operator overloading**: Capacità di un operatore di comportarsi diversamente basandosi sui tipi degli operandi. La risoluzione avviene a compile-time permettendo ai tipi definiti dall'utente di utilizzare sintassi naturale degli operatori built-in.
   - **Subtype attraverso virtual functions**: Meccanismo che permette a metodi di comportarsi diversamente basandosi sul tipo runtime dell'oggetto. Utilizza late binding per risolvere dinamicamente quale implementazione chiamare, permettendo comportamento polimorfico attraverso gerarchie di classi.
   - **Late binding e dynamic dispatch**: Sistema runtime che determina quale metodo chiamare basandosi sul tipo effettivo dell'oggetto, non sul tipo del puntatore o reference utilizzato per accedervi. Fondamentale per framework e librerie estensibili.

4. **🎨 Astrazione (Abstraction)**
   - **Classi astratte**: Classi che modellano concetti generali senza essere istanziabili direttamente. Contengono funzioni pure virtual che devono essere implementate dalle classi derivate, forzando un contratto comune mentre permettendo implementazioni specifiche.
   - **Modellazione concetti complessi**: Capacità di rappresentare entità del mondo reale attraverso gerarchie di classi, catturando sia attributi comuni che comportamenti specializzati. Permette di lavorare a livelli di astrazione appropriati.
   - **Separazione contratto e implementazione**: Distinzione tra cosa deve essere fatto (contratto definito da interfacce) e come viene fatto (implementazione nelle classi concrete), permettendo flessibilità e intercambiabilità delle implementazioni.

### **Gestione Avanzata delle Risorse**

- **Resource Acquisition Is Initialization**: Idioma fondamentale del C++ dove l'acquisizione di risorse avviene nei costruttori e il rilascio nei distruttori. Questo garantisce gestione automatica e sicura delle risorse, legando il loro ciclo di vita al ciclo di vita degli oggetti. Anche in presenza di eccezioni, le risorse vengono automaticamente rilasciate quando gli oggetti escono dallo scope.

- **Memory Safety**: Insieme di pratiche e principi per prevenire errori comuni nella gestione della memoria come memory leak (memoria allocata ma mai deallocata), dangling pointer (puntatori che riferiscono memoria già deallocata), e double delete (tentativo di deallocare la stessa memoria più volte). Richiede disciplina nell'ownership e matching di new/delete.

- **Exception Safety**: Garanzie sul comportamento del programma quando si verificano eccezioni. Include basic guarantee (nessun memory leak), strong guarantee (stato del programma invariato se l'operazione fallisce), e nothrow guarantee (l'operazione non può fallire). Preparazione essenziale per gestione robusta degli errori nei moduli avanzati.

- **Ownership Semantics**: Principi che definiscono chiaramente quale parte del codice è responsabile della gestione (creazione e distruzione) di una risorsa. Include single ownership (un solo proprietario), shared ownership (proprietari multipli con reference counting), e transfer of ownership (passaggio di responsabilità). Fondamentale per architetture complesse e design patterns.

### **Design Patterns Foundation**

- **Orthodox Canonical Form**: Pattern fondamentale che definisce la forma standard per qualsiasi classe C++ sicura e utilizzabile. Garantisce che gli oggetti possano essere creati, copiati, assegnati e distrutti correttamente. È la base per tutti gli altri pattern e assicura comportamento prevedibile in qualsiasi contesto, dalle collezioni standard ai framework complessi.

- **Clone Pattern**: Pattern che risolve il problema della copia polimorfica, permettendo di duplicare oggetti senza conoscere il loro tipo concreto. Utilizza una funzione virtual che ogni classe derivata implementa per creare copie di se stessa, essenziale quando si lavora con collezioni di oggetti polimorfici o quando serve copia profonda in gerarchie complesse.

- **Template Method attraverso virtual functions**: Pattern strutturale che definisce lo scheletro di un algoritmo in una classe base, delegando l'implementazione di passi specifici alle classi derivate attraverso funzioni virtual. Permette di riusare la struttura algoritmica comune variando solo i dettagli implementativi.

- **Strategy Pattern attraverso interfacce e polimorfismo**: Pattern comportamentale che definisce una famiglia di algoritmi intercambiabili attraverso interfacce comuni. Gli algoritmi possono essere selezionati e cambiati a runtime, promuovendo flessibilità e testabilità. Utilizza polimorfismo per disaccoppiare l'utilizzo dell'algoritmo dalla sua implementazione specifica.

---

## 🛠️ Come Utilizzare Questa Repository

### **Navigazione**
Ogni modulo ha il proprio README dettagliato con:
- Obiettivi specifici del modulo
- Concetti teorici spiegati
- Esempi pratici di output
- Istruzioni di compilazione

### **Compilazione Universale**
```bash
cd cppXX/exYY/  # Qualsiasi modulo/esercizio
make            # Compila il progetto
./executable    # Esegue il programma
```

### **Studio Consigliato**
1. **Sequenziale**: cpp00 → cpp01 → cpp02 → cpp03 → cpp04
2. **Ogni modulo costruisce sui precedenti**
3. **Praticare gli esercizi prima di passare al successivo**
4. **Focus sui concetti teorici, non solo implementazione**

---

## 🎓 Preparazione per C++ Avanzato

Questi moduli costituiscono la **base essenziale** per:
- **Template Metaprogramming**
- **STL (Standard Template Library)**  
- **Modern C++ (C++11/14/17/20)**
- **Design Patterns Avanzati**
- **Architetture Software Enterprise**
	- che affronteremo dei moduli 05-09
