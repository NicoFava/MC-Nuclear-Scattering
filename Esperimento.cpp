#include "Esperimento.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

Esperimento::Esperimento(unsigned int seed) : m_rgen(seed), m_cost(1.277E-24), m_DeltaOmega_input(0.062), m_secdiff_input(3.01E-26), m_Ns_input(12169.), m_sigma_Ns(sqrt(12169.)), m_sigma_DeltaOmega(0.007), m_deltax_input(2), m_sigma_deltax(0.05){
  m_Ni_input = m_Ns_input*m_cost/(m_DeltaOmega_input*m_secdiff_input*m_deltax_input);
  m_sigma_Ni = sqrt(m_Ni_input);
}

void Esperimento::Esegui(){
  m_DeltaOmega_misurato = m_rgen.Gauss(m_DeltaOmega_input, m_sigma_DeltaOmega);
  m_Ns_misurato = m_rgen.Gauss(m_Ns_input, m_sigma_Ns);
  m_Ni_misurato = m_rgen.Gauss(m_Ni_input, m_sigma_Ni);
  m_deltax_misurato = m_rgen.Gauss(m_deltax_input, m_sigma_deltax);
}

void Esperimento::Analizza(){
  m_secdiff_misurato = m_Ns_misurato*m_cost/(m_DeltaOmega_misurato*m_deltax_misurato*m_Ni_misurato);
}
void Esperimento::Analizza_sigma_DeltaOmega_acceso(){
  m_secdiff_misurato = m_Ns_input*m_cost/(m_DeltaOmega_misurato*m_deltax_input*m_Ni_input);
}

void Esperimento::Analizza_sigma_deltax_acceso(){
  m_secdiff_misurato = m_Ns_input*m_cost/(m_DeltaOmega_input*m_deltax_misurato*m_Ni_input);
}

void Esperimento::Analizza_sigma_Ni_acceso(){
  m_secdiff_misurato = m_Ns_input*m_cost/(m_DeltaOmega_input*m_deltax_input*m_Ni_misurato);
}

void Esperimento::Analizza_sigma_Ns_acceso(){
  m_secdiff_misurato = m_Ns_misurato*m_cost/(m_DeltaOmega_input*m_deltax_input*m_Ni_input);
}