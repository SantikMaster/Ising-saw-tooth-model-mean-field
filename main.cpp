#include <iostream>
#include <math.h>
#include <stdio.h>

// доделать суммирование по состояниям и вычисление стат суммы

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
	double m_S1 = 0, m_S2 = 0, m_S3 = 0;
	double h = 0.0;
	double T=0.1;
	long double Hamiltonian[8];
void HamiltonianFill();
long double fn();
void TextOut(string Text, int Number);

int main(int argc, char** argv) 
{
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
	HamiltonianFill();
	fN_temp = fn();
	fNOld = fn();
//		HamiltonianFill();
//	fN_temp = fn();
	//	cout << "              " << fN<< "              "<< fN_temp;
	
	for (ii = 0; ii<40; ii++)
	{
		m_S1 = (1-ii*0.05)/2;
		for (jj = 0; jj<40; jj++)
		{
			m_S2 = (1-jj*0.05)/2;
			for (kk = 0; kk<40; kk++)
			{
				m_S3 = (1-kk*0.05)/2;
	//	cout << "1" ;
					HamiltonianFill();
					fN = fn();
	//					cout << "              " << fN<< "              "<< fN_temp;
					if (fN<fN_temp)
					{
					//	cout << "!!!!!!!\n\n\n\n\n" ; 
						fN_temp = fN;
						m_S1_t = m_S1;
						m_S2_t = m_S2;
						m_S3_t = m_S3;
						
					}
					
					
  //   				cout << " "  << Hamiltonian [1];
				

//	    cout << " \n  	";
	}}}
	 cout << " \n  \n\n	";
	  cout << " \n  	";
	cout << " "  << m_S1_t << " "  << m_S2_t << " "  << m_S3_t ;
	cout << " \n  	";
//	*/
	M = m_S1_t + m_S2_t + m_S3_t ;
	M2 = -((fNOld) - (fN_temp))/ 0.05;
	
	
	cout << " M =  	"<< M << "\n";
	sprintf(buf, "%4.4f    %4.4f   %4.4f   %4.4f    %4.4f    %4.4f   \n", h,  M, M2, m_S1_t , m_S2_t , m_S3_t  );
	string ST(buf);	
				
	TextOut(ST, 0);
	
	fNOld =  fN_temp;
	h +=0.05;
}

//getchar();	
	return 0;
}
void TextOut(string Text, int Number)
{

	// #include <stdio.h>

	FILE	 	*stream;
	char str[10];


	char Stri[25];

	//   itoa(Number, Stri, 12);
	//  string strs(Stri);

	//   strcpy(str,("D/Data"+strs+".txt").c_str() ) ;

//	sprintf(Stri, "Data.txt");
	stream =
		fopen("DataEnh.txt",  "a");
fopen(Stri,  "a");

	//	stream = fopen(Stri, , "rw");

	//  "Data.txt"
	char * p;
	p = (char *)Text.c_str();
	if (stream != NULL)
	{
		fprintf(stream, p, "DataEnh.txt");
//		fprintf(stream, p, Stri);
		fclose(stream);
	}
	return;
}
long double fn()
{
	int i;
	long double F = 0, F1;
		for (i = 0; i<8; i++)
	{
		F += exp(-Hamiltonian[i]/T);
		
	
	//		cout << "       \n\n";  	
	//		cout << "   "<<Hamiltonian[i]<< "       "  <<exp(-Hamiltonian[i]/T);
	//		cout << "    " << F;  
			
		
    }
	F1 = T*log(F);
	return F1;
}


void HamiltonianFill()
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
			//		cout << " "  << H;
	       
			}

		}

	}
	
}
