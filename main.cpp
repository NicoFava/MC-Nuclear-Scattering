#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "Funzioni.h"
#include "Esperimento.h"
#include "RandomGen.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TPaveStats.h"
#include "TAxis.h"
#include "TH2F.h" 
#include "TF1.h"


using namespace std;

int main() {
	TApplication app("app", 0, 0);
	unsigned int nmax = 100000;
	TH1F secdiff("Sezione d'urto differenziale a 45#circ", "Sezione d'urto differenziale a 45#circ", 100, 100, 100);
	TH1F sigma1("Sezione d'urto differenziale a 45#circ con #sigma_{#Delta#Omega}", "Sezione d'urto differenziale a 45#circ con #sigma_{#Delta#Omega}", 100, 100, 100);
	TH1F sigma2("Sezione d'urto differenziale a 45#circ con #sigma_{x}", "Sezione d'urto differenziale a 45#circ con #sigma_{x}", 100, 100, 100);
	TH1F sigma3("Sezione d'urto differenziale a 45#circ con #sigma_{Ni}", "Sezione d'urto differenziale a 45#circ con #sigma_{Ni}", 100, 100, 100);
	TH1F sigma4("Sezione d'urto differenziale a 45#circ con #sigma_{Ns}", "Sezione d'urto differenziale a 45#circ con #sigma_{Ns}", 100, 100, 100);
	secdiff.StatOverflows(kTRUE);
	sigma1.StatOverflows(kTRUE);
	sigma2.StatOverflows(kTRUE);
	sigma3.StatOverflows(kTRUE);
	sigma4.StatOverflows(kTRUE);
	Esperimento esp1(1);
	Esperimento esp2(1);
	Esperimento esp3(1);
	Esperimento esp4(1);
	Esperimento esp5(1);
	for(int i = 0; i < nmax; i++){
		esp1.Esegui();
		esp1.Analizza();
		esp2.Esegui();
		esp2.Analizza_sigma_DeltaOmega_acceso();
		esp3.Esegui();
		esp3.Analizza_sigma_deltax_acceso();
		esp4.Esegui();
		esp4.Analizza_sigma_Ni_acceso();
		esp5.Esegui();
		esp5.Analizza_sigma_Ns_acceso();
		secdiff.Fill(esp1.Get_secdiff_misurato());
		sigma1.Fill(esp2.Get_secdiff_misurato());
		sigma2.Fill(esp3.Get_secdiff_misurato());
		sigma3.Fill(esp4.Get_secdiff_misurato());
		sigma4.Fill(esp5.Get_secdiff_misurato());
	}

	TCanvas can1("Sezione d'urto differenziale a 45#circ", "Sezione d'urto differenziale a 45#circ");
	can1.cd();
	secdiff.SetTitle("Sezione d'urto differenziale a 45#circ");
	secdiff.GetXaxis()->SetTitle("d#sigma/d#Omega[cm^{2}/sr]");
	secdiff.GetYaxis()->SetTitle("Numero di estrazioni");
	secdiff.Draw();
	cout <<"Media di d#sigma/d#Omega: "<< secdiff.GetMean() <<"+/-"<<secdiff.GetRMS()<< endl;
	
	TCanvas can2("Analisi errori", "Analisi errori");
	can2.Divide(2,2);
	can2.cd(1);
	sigma1.SetTitle("Sezione d'urto differenziale a 45#circ con solo #sigma_{#Delta#Omega}");
	sigma1.GetXaxis()->SetTitle("d#sigma/d#Omega[cm^{2}/sr]");
	sigma1.GetYaxis()->SetTitle("Numero di estrazioni");
	sigma1.Draw();
	cout <<"1) Media di d#sigma/d#Omega: "<< sigma1.GetMean() <<"+/-"<<sigma1.GetRMS()<< endl;
	can2.cd(2);
	sigma2.SetTitle("Sezione d'urto differenziale a 45#circ con solo #sigma_{x}");
	sigma2.GetXaxis()->SetTitle("d#sigma/d#Omega[cm^{2}/sr]");
	sigma2.GetYaxis()->SetTitle("Numero di estrazioni");
	sigma2.Draw();
	cout <<"2) Media di d#sigma/d#Omega: "<< sigma2.GetMean() <<"+/-"<<sigma2.GetRMS()<< endl;
	can2.cd(3);
	sigma3.SetTitle("Sezione d'urto differenziale a 45#circ con solo #sigma_{Ni}");
	sigma3.GetXaxis()->SetTitle("d#sigma/d#Omega[cm^{2}/sr]");
	sigma3.GetYaxis()->SetTitle("Numero di estrazioni");
	sigma3.Draw();
	cout <<"3) Media di d#sigma/d#Omega: "<< sigma3.GetMean() <<"+/-"<<sigma3.GetRMS()<< endl;
	can2.cd(4);
	sigma4.SetTitle("Sezione d'urto differenziale a 45#circ con solo #sigma_{Ns}");
	sigma4.GetXaxis()->SetTitle("d#sigma/d#Omega[cm^{2}/sr]");
	sigma4.GetYaxis()->SetTitle("Numero di estrazioni");
	sigma4.Draw();
	cout <<"4) Media di d#sigma/d#Omega: "<< sigma4.GetMean() <<"+/-"<<sigma4.GetRMS()<< endl;
	
	app.Run();
	return 0;

}