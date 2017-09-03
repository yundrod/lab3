#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b = 0, n, j, k, l, m, o, max=6, tabla[100][10];
	string countries[] = { "Bra", "Col", "Uru", "Chi", "Arg", "Per", "Par", "Ecu", "Bol", "Ven" };
	string auxcoun[] = { "Bra", "Col", "Uru", "Chi", "Arg", "Per", "Par", "Ecu", "Bol", "Ven" };
	int per[] = { 36, 25, 24, 23, 23, 21, 21, 20, 10, 7 };
	int aux[] = { 36, 25, 24, 23, 23, 21, 21, 20, 10, 7 };
	cout << "Tabla de posiciones actual: " << endl;
	for (int i = 0; i < 10; i++){
		cout << countries[i] << " : " << per[i] << endl;
	}
	cout << endl;
	int mayor = per[5];
	/*Cree cinco for ya que en la fecha 16 se jugaran 5 partidos que son los siguientes:
	Bolivia vs Chile
	Colombia vs Brasil
	Ecuador vs Peru
	Argentina vs Venezuela
	Paraguay vs Uruguay
	las condicionales if son para evaluar lo siguiente:
	-si el iterador es 0 el primer equipo habra ganado
	-si el iterador es 1 ambos equipos habran ganado
	-si el iterador es 2 el segundo equipo gana*/

	for (int i = 0; i < 3; i++){/* peru vs ecuador */
		if (i == 0){
			aux[5] += 3;
		}
		else if (i == 1){
			aux[5] += 1;
			aux[7] += 1;
		}
		else{
			aux[7] += 3;
		}
		for (int j = 0; j < 3; j++){/*brazil vs colombia*/
			if (j == 0){
				aux[1] += 3;
			}
			else if (j == 1){
				aux[0] += 1;
				aux[1] += 1;
			}
			else{
				aux[0] += 3;
			}
			for (int k = 0; k < 3; k++){/*uruguay vs paraguay*/
				if (k == 0){
					aux[6] += 3;
				}
				else if (k == 1){
					aux[6] += 1;
					aux[2] += 1;
				}
				else{
					aux[2] += 3;
				}
				for (int l = 0; l < 3; l++){/*argentina vs venezuela*/
					if (l == 0){
						aux[4] += 3;
					}
					else if (l == 1){
						aux[4] += 1;
						aux[9] += 1;
					}
					else{
						aux[9] += 3;
					}
					for (int m = 0; m < 3; m++){/*chile vs bolivia*/
						if (m == 0){
							aux[8] += 3;
						}
						else if (m == 1){
							aux[8] += 1;
							aux[3] += 1;
						}
						else{
							aux[3] += 3;
						}
						a = 0;/*reinicio "a" que es mi contaador de puesto*/
						for (n = 0; n < 10; n += 1)/*recorro puntajes de la posibilidad actual y veo posicion de peru, que seria a+1*/
						{
							if (aux[5] < aux[n])
							{
								a++;
							}
						}
						a++;/*le sumo 1 para obtener el puesto de peru en esta posibilidad*/
						if (max > a)/*compruebo si el puesto que tiene "a" en la posibilidad es mejor que el anterior(max) y lo guardo en tabla*/
						{
							max = a;
							for (o = 0; o < 10; o++)
							{
								tabla[0][o] = aux[o];
							}
							b = 0;

						}
						else if (max == a)/*si hubiera mas de una posibilidad optima se guardan en las siguientes filas de la matriz*/
						{
							b++;
							for (o = 0; o < 10; o++)
							{
								tabla[b][o] = aux[o];
							}
						}
						for (int r = 0; r < 10; r++)/*reinicio aux(lista de puntajes auxiliar) con el original*/
						{
							aux[r] = per[r];
						}
					}
				}
			}
		}
	}
	cout << "Tabla para que Peru llegue al mundial: " << endl;
	int mx = 9,x;
	char y;
	for (k = 0; k<b + 1; b++)/*esto repite b+1(cantidad de posibilidades optimas) veces la impresion*/
	{
		for (int i = 9; i>-1; i = i - 1)/*ordenamiento de puntajes y paises*/
		{
			mx = i;
			for (j = i - 1; j>-1; j = j - 1)
			{
				if (tabla[k][mx] < tabla[k][j])
				{
					mx = j;
				}
				x = tabla[k][mx];
				y = auxcoun[k][mx];
				tabla[k][j] = tabla[k][i];
				auxcoun[k][j] = auxcoun[k][i];
				tabla[k][i] = x;
				auxcoun[k][i] = y;
			}
		}
		for (l = 0; l < 10; l++)/*imprimo la tabla*/
		{
			cout << auxcoun[l] << " : " << tabla[k][l] << endl;
		}
		for (int r = 0; r < 10; r++)/*reinicio lista auxiliar de paises*/
		{
			auxcoun[r] = countries[r];
		}

	}
	
	system("pause");
	return 0;
}