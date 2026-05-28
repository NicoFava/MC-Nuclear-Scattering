#ifndef __ESPERIMENTO_H__
#define __ESPERIMENTO_H__

#include "RandomGen.h"
using namespace std;

class Esperimento{
public:
	Esperimento(unsigned int seed);
	~Esperimento(){;};

	void Esegui();
	void Analizza();
	void Analizza_sigma_DeltaOmega_acceso();
	void Analizza_sigma_deltax_acceso();
	void Analizza_sigma_Ni_acceso();
	void Analizza_sigma_Ns_acceso();
	double Get_secdiff_misurato(){return m_secdiff_misurato;};

private:
	RandomGen m_rgen;
	double m_secdiff_input, m_cost, m_Ns_input, m_Ni_input, m_DeltaOmega_input, m_deltax_input;
	double m_secdiff_misurato, m_Ns_misurato, m_Ni_misurato, m_DeltaOmega_misurato, m_deltax_misurato;
	double m_sigma_secdiff, m_sigma_Ns, m_sigma_Ni, m_sigma_DeltaOmega, m_sigma_deltax;
};


#endif