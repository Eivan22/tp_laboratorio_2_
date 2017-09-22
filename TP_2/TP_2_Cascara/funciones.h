#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*CREAMOS PROTOTIPOS DE LAS FUNCIONES DE NUESTRA BIBLIOTECA*/

/*CONVERSION*/
long convertir_cadena_a_entero(const char *cad);
char * convertir_entero_a_cadena(int num);
int LengtCadena(char *Cadena);
char *SubCadena(char *cadena, int inicio, int longitud);
/*VALIDACION*/
int ValidarInt(char Cadena[]);
int ValidarFloat(char Cadena[]);
int ValidarYESNO(char Cadena[]);
/*MESSENGEBOX*/
int MensajeYESNO(char Mensaje[]);
/*OPERACIONES MATEMATICAS*/
float Suma(float ValorOne, float ValorTwo);
float Resta(float ValorOne, float ValorTwo);
float Dividir(float ValorOne, float ValorTwo);
float Multiplicar(float ValorOne, float ValorTwo);
int Factorial(float Valor);
/*GRAFICAR*/
int GraficarX3Colum(int Colum1, int Colum2, int Colum3);
