#include <iostream>
#include <math.h>
#include <stdio.h>

void HamiltonianFill(long double *Hamiltonian, double h, double, double, double);
long double fn(long double *Hamiltonian, double T);
void TextOut(const std::string & Text, int Number);

int main(int argc, char** argv) 
{
	double m_S1 = 0, m_S2 = 0, m_S3 = 0;
	double h = 0.0;
	double T=0.1;
	long double Hamiltonian[8];	
	
	double m_S1_t = 0, m_S2_t = 0, m_S3_t = 0;
    double M=0, M2= 0;
	char buf[256];


	long double fN=0, fN_temp = 0, fNOld = 0;
	int ii, jj, kk;

	while (h < 5)
	{	
	 	m_S1 = 0; 
	 	m_S2 = 0;
		m_S3 = 0;
		HamiltonianFill(Hamiltonian, h, 0, 0, 0);
		fN_temp = fn(Hamiltonian, T);
		fNOld = fn(Hamiltonian, T);
	
		for (ii = 0; ii<40; ii++)
		{
			m_S1 = (1-ii*0.05)/2;
			for (jj = 0; jj<40; jj++)
			{
				m_S2 = (1-jj*0.05)/2;
				for (kk = 0; kk<40; kk++)
				{
					m_S3 = (1-kk*0.05)/2;
					HamiltonianFill(Hamiltonian, h, m_S1, m_S2, m_S3);
					fN = fn(Hamiltonian, T);

					if (fN<fN_temp)
					{
						fN_temp = fN;
						m_S1_t = m_S1;
						m_S2_t = m_S2;
						m_S3_t = m_S3;	
					}
				}
			}		
		}
		std::cout << " \n";
		std::cout << " "  << m_S1_t << " "  << m_S2_t << " "  << m_S3_t <<" \n  	";

		M = m_S1_t + m_S2_t + m_S3_t ;
		M2 = -((fNOld) - (fN_temp))/ 0.05;
	
	
		std::cout << " M =  	"<< M << "\n";
		sprintf(buf, "%4.4f    %4.4f   %4.4f   %4.4f    %4.4f    %4.4f   \n", h,  M, M2, m_S1_t , m_S2_t , m_S3_t  );
		std::string ST(buf);	
				
		TextOut(ST, 0);
	
		fNOld =  fN_temp;
		h +=0.05;
	}	
	return 0;
}

void TextOut(const std::string & Text, int Number)
{
	// #include <stdio.h>
	FILE *stream;

	stream =
		fopen("DataEnh.txt",  "a");
 
	char *p;
	p = (char *)Text.c_str();
	if (stream != NULL)
	{
		fprintf(stream, p, "DataEnh.txt");
		fclose(stream);
	}
	return;
}

long double fn(long double *Hamiltonian, double T)
{
	int i;
	long double F = 0, F1;
	
	for (i = 0; i<8; i++)
	{
		F += exp(-Hamiltonian[i]/T);	
    }
    
	F1 = T*log(F);
	return F1;
}


void HamiltonianFill(long double *Hamiltonian, double h, double m_S1, double m_S2, double m_S3)
{
	int i, j, k, numbr;
	double S1, S2, S3, H;
	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{
			for (k = 0; k<2; k++)
			{
				numbr = 4*i + 2*j + k;
				S1=i*2-1;
				S2=j*2-1;
				S3=k*2-1;
				
				H = 0;
				H += S1*S2 + S2+S3 + S1*S3 - h*(S1+S2+S3);
				H += -m_S1*m_S3 - 1/2*m_S1*m_S2 - 1/2*m_S2*m_S3;
				H += S1*(m_S2+m_S3)+ S3*(m_S2+m_S1);
				
				Hamiltonian[numbr] = H;  
			}

		}

	}
	
}
