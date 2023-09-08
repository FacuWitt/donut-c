#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <windows.h>

double sin(), cos();

int main() {	
	float A=0, B=0, i, j; // R1 radio interno, R2 radio externo (de rotacion sobre la generatriz)
	const int w=100,h=32;
	char b[w*h];
	float z[w*h];
	
	// Resolucion de la pantalla es de 80 col * 22 filas (1760 caracteres)
	for(;;){
		system("cls");
		memset(b, 32, w*h); // Limpiamos la cadena b con espacios en blanco
		memset(z, 0, w*h*4); // El array z se limpia en 0
							// el 7040 proviene del tamaño del array de bytes 
							// (un float son 4 bytes, por lo tanto, 1760x4 = 7040)
		
		float cA = cos(A);
		float cB = cos(B);
		float sA = sin(A);
		float sB = sin(B);
		
		for(j=0;j<6.28;j+=0.07){
			for(i=0;i<6.28;i+=0.02){
				// i = tita, j = phi
				// varian en razon a 0.07 y 0.02 dando una vuelta completa formando circunferencias
				
				
				float sI = sin(i);//
				float sJ = sin(j);//
				float cI = cos(i);//
				float cJ = cos(j);//
				float cJ2 = cJ + 2;//
				
				float mess=1/(sI*cJ2*sA + sJ*cA + 6.0);//
				float t = sI*cJ2*cA-sJ*sA;//
				
				/*				int x = (R2 + R1*cI) * (cB*cJ + sA*sB*sJ) - R1*cA*sB*sI;*/
				/*				int y = (R2 + R1*cI) * (cJ*sB - cB*sA*sJ) + R1*cA*cB*sI;*/
				
				int x = w/2+50*mess*(cI*cJ2*cB - t*sB);
				int y = h/2+25*mess*(cI*cJ2*sB + t*cB);
				int o = x + y * w;
				int N = 8 *((sJ*sA - sI*cJ*cA) * cB - sI*cJ*sA- sJ*cA - cI*cJ*sB);
				if (y>0 && y<h && x>0 && x<w && mess>z[o]){
					z[o]=mess;
					b[o]=".,:;=+*ea#$@"[N>0 ? N:0]; 
				}
			}
		}
		for(int k=0; k < w*h; k++){
			putchar(k%w?b[k]:10);
		}
		A+= 0.4;
		B+= 0.2;
			
	}
	return 0;
}
