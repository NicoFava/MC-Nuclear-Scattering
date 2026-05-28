#ifndef __FUNZIONI_H__
#define __FUNZIONI_H__
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// Funzione per calcolare la media degli elementi di un vettore
double calcolaMedia(const vector<double>& vettore) {
	 double somma = 0.0;
	 for (double elemento : vettore) {
		  somma += elemento;
	 }
	 return somma / vettore.size();
}

// Funzione per calcolare la radice quadrata della media dei quadrati degli elementi (RMS)
double calcolaDeviazioneStandard(const vector<double>& vettore) {
	 double media = calcolaMedia(vettore);
	 double sommaScartiQuadrati = 0.0;
	 for (double elemento : vettore) {
		  double scarto = elemento - media;
		  sommaScartiQuadrati += scarto * scarto;
	 }
	 double varianza = sommaScartiQuadrati / vettore.size();
	 return sqrt(varianza);
}

#endif