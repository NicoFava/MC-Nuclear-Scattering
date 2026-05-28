[🇮🇹 Italiano](#italiano) | [🇬🇧 English](#english)

---

<a id="italiano"></a>
## 🇮🇹 Italiano

# Simulazione Monte Carlo: Analisi degli Errori sulla Sezione d'Urto

Questo repository contiene una simulazione Monte Carlo sviluppata in C++ per il Laboratorio di Misure Nucleari. Il codice ha lo scopo di simulare un esperimento di scattering e analizzare la propagazione degli errori nella misurazione della sezione d'urto differenziale (dσ/dΩ) a un angolo di 45°.

### Descrizione del Progetto

La stima dell'errore su una misura complessa come la sezione d'urto è soggetta a diverse fonti di incertezza. Invece di procedere con il calcolo analitico standard della propagazione degli errori, questo programma utilizza un approccio Monte Carlo (100.000 iterazioni) per valutare l'impatto di ogni singola variabile sul risultato finale.

Il programma genera 5 istanze dell'esperimento per confrontare:
1. L'esperimento con **tutte le incertezze** attive.
2. L'impatto della sola incertezza sull'angolo solido (σ_ΔΩ).
3. L'impatto della sola incertezza sullo spessore del bersaglio (σ_x).
4. L'impatto della sola incertezza sui conteggi incidenti (σ_Ni).
5. L'impatto della sola incertezza sui conteggi diffusi (σ_Ns).

### Prerequisiti

Per compilare ed eseguire il codice è necessario avere installato:
* Un compilatore C++ (es. `g++`)
* Il framework [CERN ROOT](https://root.cern/)
* `make` per la gestione della compilazione automatica.

### Struttura del Codice

* `main.cpp`: Esegue il ciclo Monte Carlo, gestisce gli istogrammi (`TH1F`) e disegna i risultati a schermo tramite `TCanvas`.
* `Esperimento.h` / `.cpp`: Contiene la logica dell'esperimento fisico e i metodi per attivare/disattivare le singole sorgenti di errore.
* `RandomGen.h`: Generatore di numeri casuali utilizzato per le estrazioni Monte Carlo.
* `Funzioni.h` / `.cpp`: Funzioni matematiche e fisiche di supporto.
* `Makefile`: Istruzioni per la compilazione del progetto.

### Output

Eseguendo il programma, vengono generati a schermo:
* Un istogramma principale con la distribuzione di dσ/dΩ simulata con tutti gli errori.
* Un canvas diviso in 4 sezioni, da cui si evince graficamente e statisticamente (Media ± RMS) quale parametro contribuisce maggiormente all'allargamento della distribuzione della sezione d'urto. I risultati statistici vengono stampati anche a terminale.

### Compilazione ed Esecuzione

Il progetto include un `Makefile` per semplificare la compilazione. Apri il terminale nella cartella del repository e digita:

`make`

Una volta terminata la compilazione, avvia la simulazione con:

`./main`

Per rimuovere i file oggetto (`.o`) e pulire la cartella di lavoro:

`make clean`

---

<a id="english"></a>
## 🇬🇧 English

# Monte Carlo Simulation: Cross Section Error Analysis

This repository contains a C++ Monte Carlo simulation developed for the Nuclear Measurements Laboratory. The code aims to simulate a scattering experiment and analyze the error propagation in the measurement of the differential cross-section (dσ/dΩ) at a 45° angle.

### Project Description

Estimating the error on a complex measurement like the cross-section is subject to various sources of uncertainty. Instead of proceeding with standard analytical error propagation, this program uses a Monte Carlo approach (100,000 iterations) to evaluate the impact of each individual variable on the final result.

The program generates 5 instances of the experiment to compare:
1. The experiment with **all uncertainties** active.
2. The impact of the solid angle uncertainty alone (σ_ΔΩ).
3. The impact of the target thickness uncertainty alone (σ_x).
4. The impact of the incident counts uncertainty alone (σ_Ni).
5. The impact of the scattered counts uncertainty alone (σ_Ns).

### Prerequisites

To compile and run the code, you need to have the following installed:
* A C++ compiler (e.g., `g++`)
* The [CERN ROOT](https://root.cern/) framework
* `make` for automated build management.

### Code Structure

* `main.cpp`: Executes the Monte Carlo loop, manages histograms (`TH1F`), and plots the results on screen using `TCanvas`.
* `Esperimento.h` / `.cpp`: Contains the logic of the physical experiment and the methods to toggle individual error sources.
* `RandomGen.h`: Random number generator used for the Monte Carlo extractions.
* `Funzioni.h` / `.cpp`: Supporting mathematical and physical functions.
* `Makefile`: Build instructions for the project.

### Output

Running the program generates the following on-screen:
* A main histogram showing the simulated distribution of dσ/dΩ with all errors included.
* A canvas divided into 4 pads, graphically and statistically (Mean ± RMS) showing which parameter contributes most to the broadening of the cross-section distribution. The statistical results are also printed to the terminal.

### Compilation and Execution

The project includes a `Makefile` to simplify compilation. Open a terminal in the repository folder and type:

`make`

Once compiled, run the simulation with:

`./main`

To remove the object files (`.o`) and clean the working directory:

`make clean`
