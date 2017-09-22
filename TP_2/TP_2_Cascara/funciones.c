#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define true 1
#define false 0

/*ESTA FUNCION CONVIERTE DE UNA VARIABLE TIPO TEXTO(CHAR) A UNA NUEMRICA(LONG)
-VALORES DE ENTREDA: REQUIERE UNA VARIABLE TIPO CHAR PASADA POR VALOR
-VALORES DE SALIDA: DEVUELVE UNA VARIABLE NUMERICA TIPO LONG CON LA CADENA CONVERTIDA, EN CASO DE NO HABERCE PODIDO HABER LLEGADO A REALIZAR LA CONVERCION DEVUELVE CERO*/
long convertir_cadena_a_entero(const char *cad)
{
    long num = 0;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    int digito;
    int i;

    for (i = tam ; i > 0; --i) {
        digito = (int) (cad[i - 1] - 48);
        num += digito * pow(10.0, tam - i);
    }

    return num;
}
/*ESTA FUNCION CONVIERTE ENTEROS EN TEXTO
-VALORES DE ENTRADA: REQUIERE UNA VARIBLE NUMERICA DE TIPO INTERO
-VALORES DE SALIDA: DEVUELVE UNA VARIBLE DE TIPO CHAR CON EL LA CADENA CONVERTIDA*/
char * convertir_entero_a_cadena(int num)
{
#define MAX_TAM 80

    char *cad;
    int digito;
    int i = 0;

    cad = (char*) malloc(MAX_TAM * sizeof(char));  /* No olvidar liberar la memoria asignada */
    memcpy(cad, "\0", MAX_TAM);  /* Bruto, pero efectivo :) */

    while (num >= 1) {
        digito = num % 10;

        if (i < MAX_TAM - 1) {
            cad[i] = (char) (digito + 48);
            num -= digito;
            num /= 10;
        }

        ++i;
    }

    /* Pero los dígitos de la cadena han quedado en orden inverso,  */
    /* así que los ordenamos correctamente */

    int  tam = strlen(cad);
    char temp;

    for (i = 0; i < tam / 2; ++i) {
        temp = cad[i];
        cad[i] = cad[tam - i - 1];
        cad[tam - i - 1] = temp;
    }

    return cad;
}
/*ESTA FUNCION VALIDA SI ES QUE EL VALOR PASADO EN LA ENTRADA ES NUMERICO
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO*/
int ValidarInt(char Cadena[])
{
    char *subcadena;
    int valido=1;
    int a;
    int control = 0;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if(isdigit(Cadena[a]) == 0)
        {
            control = control + 1;
        }
    }
    if(LengtCadena(Cadena)>1 && Cadena[0]=='0')
    {
        control = control + 1;
    }
    if(control > 0)
    {
        valido=0;
    }
    return valido;
}
/*ESTA FUNCION VALIDA QUE EL VALOR INGREADO SEA UN NUMERICO DE TIPO FLOTANTE
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO FLOTANTE*/
int ValidarFloat(char Cadena[])
{
    int valido=1;
    int a;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if((Cadena[a] !='-') && (Cadena[a] !='.') && (isdigit(Cadena[a]) == 0))
        {
            valido = 0;
            return valido;
        }
    }
    return valido;
}

int ValidarYESNO(char Cadena[])
{
    int valido=1;
    int a;
    int control = 0;
    if(LengtCadena(Cadena)>1)
    {
        valido=0;
    }
    else
    {
        if(Cadena[0]=='s' || Cadena[0]=='S' || Cadena[0]=='n' || Cadena[0]=='N')
        {
            valido=1;
        }
        else
        {
            valido=0;
        }
    }
    return valido;
}
/*ESTA FUNCION CUENTA LA LONGITUD DE LA CADENA PASADA COMO ENTRADA
-VALORES DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALORES DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO CON LA CANTIDAD DE CARACTERES QUE TIENE LA CADENA DE ENTRADA*/
int LengtCadena(char *Cadena)
{
    int a=0;
    while(Cadena[a]!='\0')
    {
        a++;
    }
    return a;
}
/*ESTA FUNCION EJECUTA UN MENSAJE CON RESPUESTA YES/NO QUE EL USUARIO DESEEE
-VALORES DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR, LA QUE SE MOSTRARA EN EL CUERPO DEL MENSAJE
-VALORES DE SALIDA: DEVUEVE UNA VARIABLE DE TIPO ENTERO HACIENDO REFERENCIA A LA RESPUESTA DEL USUARIO ANTE EL MENSAJE,
DONDE 0 ES RESPUESTA NEGATIVA Y 1 ES RESPUESTA POSITIVA*/
int MensajeYESNO(char Mensaje[])
{
    char Respuesta[25];
    int IsOK;
    do{
        printf("\n\n%s S/N",Mensaje);
        scanf(" %s",&Respuesta);
        IsOK = ValidarYESNO(Respuesta);
        if(IsOK==1)
        {
            if((Respuesta[0]=='S') || (Respuesta[0]=='s'))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("\nEL VALOR INGRESADO NO CORRESPONDE A UNA OPCION VALIDA!\n");
        }
    }while(IsOK==0);
}
/*ESTA FUNCION SUMA DOS VALORES INGRESADOS POR EL USUARIO
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, LAS CUALES SE SUMARAN
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA SUMA*/
float Suma(float ValorOne, float ValorTwo)
{
    return ValorOne+ValorTwo;
}
/*ESTA FUNCION RESTA DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, DE LAS CUALES LA SEGUNDA SE RESTARA DE LA PRIMERA
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA RESTA*/
float Resta(float ValorOne, float ValorTwo)
{
    return ValorOne-ValorTwo;
}
/*ESTA FUNCION DIVIDE DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, DE LAS CUALES LA SEGUNDA DIVIDE A LA PRIMERA
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA DIVICION*/
float Dividir(float ValorOne, float ValorTwo)
{
    return ValorOne/ValorTwo;
}
/*ESTA FUNCION MULTIPLICA DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, LAS CUALES SE MULTIPLICARAN
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA MULTIPLICACION*/
float Multiplicar(float ValorOne, float ValorTwo)
{
    return ValorOne*ValorTwo;
}
/*ESTA FUNCION FACTORIZA UN VALOR INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: UNA VARIABLE NUMERICAS DE TIPO FLOTANTE, LA CUAL SE CALCULARA EL FACTORIAL
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DEL FACTORIAL*/
int Factorial(float Valor)
{
    int aux,factor= 1;
    for (aux = Valor; aux > 1; aux--)
    {
        factor = factor * aux;
    }
    return factor;
}

int GraficarX3Colum(int Colum1, int Colum2, int Colum3)
{
    int i, hasta18=Colum1, de19a35=Colum2, mayorDe35=Colum3, mayor;
    //ESTABLECEMOS CUAL ES LA COLUMNA CON MAYOR VALOR PARA GRAFICAR MEJOR
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }
    //ROTULO DE EJE Y
    printf("(Cant)\n");
    //GRAFICAMOS VALORES CON FORMATO
    for(i=mayor; i>0; i--){
        //ROTULO DE CAMPOS EJE Y
        if(i<10){
            printf("    %d| ",i);
        }
        else
        {
            printf("   %d| ",i);
        }
        //GRAFICAMOS COLUMNAS
        if(i<= hasta18){
            printf("\t###");
        }
        else
        {
            printf("\t   ");
        }
        if(i<= de19a35){
            printf("\t###");
        }
        else{printf("\t   ");}
        if(i<= mayorDe35){
                printf("\t###");
        }
        printf("\n");
    }
    printf("   --+-------------------------");
    //ROTULO DE EJE X
    printf("\n     |\t<18\t19-35\t>35    (Edad)");
    //VALORES DE LAS COLUMNAS
    printf("\n      \t(%d)\t(%d)\t(%d)\n", hasta18, de19a35, mayorDe35);
    return 0;
}


/*ESTA FUNCION DEVUELVE LA CADENA RECORTADA POR LOS PARAMETROS DE ENTRADA
-VALORES DE ENTRADA: UN ENTERO DE INICIO Y LONGITUD DE SUBCADENA ESPERADA
-VALORES DE SALIDA: LA CADENA RECORTADA O NULL EN CASO DE NO SER POSIBLE LA ACCION*/
char *SubCadena(char *cadena, int inicio, int longitud)
{

}
