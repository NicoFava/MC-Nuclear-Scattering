#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__
#include <cmath>
class RandomGen {

public:

	RandomGen(unsigned int a){
		m_seed = a;
		m_a = (unsigned int) 1664525;
		m_c = (unsigned int) 1013904223;
		m_m = (unsigned int) 2E31;
	};

	void SetA(unsigned int a) {m_a = a;}
	void SetC(unsigned int c) {m_c = c;}
	void SetM(unsigned int m) {m_m = m;}

	double Rand( ){
		m_seed = (m_a*m_seed+m_c)% m_m;
		return m_seed/double (m_m);
	};                                  // distribuzione uniforme tra 0 e 1
	double Unif(double xmin, double xmax){
		return (xmin+((xmax-xmin)*Rand()));
	};           // distribuzione uniforme tra xmin e xmax
	double Exp(double lambda){
		return -1./lambda*log(1-Rand());
	};                       // distribuzione esponenziale con costante lambda
	double Gauss(double mean, double sigma){
		  double s = Rand();
		  double t = Rand();
		  double x = sqrt(-2.*log(s))*cos(2.*M_PI*t);
		  return mean+x*sigma; 
	};          // distribuzione gaussiana (Box-Muller)
	double GaussAR(double mean, double sigma){
		 double max = 1./(sigma*sqrt(2.*M_PI));
		 double s = Rand();
		 double t = Rand();
		 double y = max*t;
		 double x = Unif(-10*sigma,10*sigma);
		 while (y>((1./(sigma*sqrt(2.*M_PI)))*exp(-pow(x-mean,2)/(2.*pow(sigma,2))))){
					y = max*Rand();
					x = Unif(-10*sigma,10*sigma);
			}
			return x;
	};  // distribuzione gaussiana (Accept-Reject)

 private:

	unsigned int m_a, m_c, m_m;
	unsigned int m_seed;

};

#endif