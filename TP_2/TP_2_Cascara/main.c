#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
/*
TP NRO 2 - SISTEMA DE PERSONAL
UTN-2017
CARRERA: TECNICO EN PROGRAMACION
MATERIA: LABORATORIO I
ALUMNO: CHOQUE ALBORNOZ IVAN EMILIO
CURSO:1E - TN
*/

#define CantPersonas 20

struct Persona{
    int Id;
    char Nombre[50];
    char Edad[3];
    char DNI[8];
};
int UltimoId = 0;

int main()
{
    /*DECLARAMOS VARIABLES GLOBALES*/
    char Seguir='S';
    char Opcion[]="0";
    char Verif;
    int Verificado=0;
    int isOK=0;

    //CREO ESTRUCTURA DE MI OBJETO
    struct Persona Person,ListPersonas[CantPersonas],ListPersonasConsulta[CantPersonas];
    //INICIALIZO OBJETOS
    int x;
    for (x=0;x<CantPersonas;x++)
        {
            //LISTA DE PERSONAS CARGADAS
            //DEFINO VALOR VACIO COMO X, POR CONTROL Y DISPONIBILIDAD EN FUTUROS USOS(NO APLICADOS EN ESTE TP)
            ListPersonas[x].Id=x;
            strcpy(ListPersonas[x].Nombre,"X");
            strcpy(ListPersonas[x].Edad,"X");
            strcpy(ListPersonas[x].DNI,"X");
            //LISTA DE RESULTADO DE CONSULTA
            ListPersonasConsulta[x].Id=x;
            strcpy(ListPersonasConsulta[x].Nombre,"X");
            strcpy(ListPersonasConsulta[x].Edad,"X");
            strcpy(ListPersonasConsulta[x].DNI,"X");
        }

    /*MENU INICIAR
    MIENTRAS LA VARIABLE 'Seguir' DE TIPO CHAR SEA 'S', SE REFRESCARA EL MENU INICIAR
    -COMO VALOR DE ENTRADA LA PANTALLA REQUIERE SELECCIONAR UNA OPCION DEL MENU
    -COMO VALOR DE SALIDA ESTA SELECCION DE DERIVARA A UN SELECTOR PARA EJECUTAR LA OPERACION SOLICITADA*/
    while(Seguir=='S')
    {
        printf("\n********************** ADMINISTRACION DE PERSONAL ***********************\n");
        printf("*                                                                       *\n");
        printf("*       OPERACIONES:                                                    *\n");
        printf("*                   1- Agregar personal                                 *\n");
        printf("*                   2- Borrar personal                                  *\n");
        printf("*                   3- Imprimir lista ordenada por nombre               *\n");
        printf("*                   4- Imprimir grafico de edades                       *\n");
        printf("*                   5- Salir                                            *\n");
        printf("*                                                                       *\n");
        printf("*************************************************************************\n");
        /*
        VALIDAMOS QUE SE INGRESE UN VALOR DE ENTRE LAS OPCIONES DADAS
        -LA VARIABLE DE TIPO 'Aux' CONTRENDRA EN VALOR FORMATEADO A ENTERO COMO VALIDACION DEL VALOR INGRESADO POR EL USUARIO
        */
        long Aux=0;
        do
        {
            printf("\nSELECCIONE UNA OPERACION: ");
            scanf("%s",&Opcion);
            Verificado = ValidarInt(Opcion);
            if(Verificado==1)
            {
                Aux = convertir_cadena_a_entero(Opcion);
                if(Aux>5 || Aux<1)
                {
                    printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
                }
            }
            else
            {
                printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
            }
         }while(Aux>5 || Aux<1);
        //LIMPIAMOS PANTALLA
        system("cls");
        /*
        SEGUN EL VALOR INGRESADO SELECCIONAREMOS LA OPERACION A REALIZAR
        */
        switch(Aux)
        {
            case 1: //ALTA PERSONA
                {
                    printf("\n****************************ALTA DE PERSONAL*****************************\n");
                    //CONTROLAMOS LA FACTIBILIDAD DE CARGAR UN REGISTRO NUEVO Y EN CASO DE SER VIABLE DEFINIMOS EL ID DEL REGISTRO
                    int contador,cargaOK=0;
                    //SI EL VALOR DE ID QUE SE PRETENDIA ASIGNAR ESTA LLENO VERIFICAMOS, SINO LO ASIGNAMOS AL NUEVO REGISTRO
                    while(ListPersonas[UltimoId].Edad[0]!='X')
                    {
                        //INCREMENTAMOS PARA COMPARAR CON EL SIGUIENTE REGISTRO DE LA LISTA
                        UltimoId = UltimoId+1;
                        //SI EXCEDEMOS LA CANTIDAD DE ID POR REGISTRO RESETEAMOS
                        if(UltimoId>CantPersonas)
                        {
                            UltimoId=0;
                        }
                        //CONTADOR DE REGISTROS COMPARADOS
                        contador = contador+1;
                        if(contador>CantPersonas)
                        {
                            //SI RECORRIMOS TODA LA LISTA Y NO HAY REGISTRO DISPONIBLE MOSTRAMOS MENSAJE Y BLOQUEAMOS LA CARGA
                            printf("\nHA EXEDIDO LA CANTIDAD DE REGISTROS PERMITIDOS!\nPara cargar un nuevo registro debe eliminar alguno de los cargados\n");
                            cargaOK=1;
                            break;
                        }
                    }
                    //SI LA CARGA EN VIABLE PROCEDEMOS A LEER-VERIFICAR-CARGAR DATOS
                    if(cargaOK==0)
                    {
                        //GRABAMOS ID DEL REGISTRO PERSONA
                        Person.Id = UltimoId;
                        printf("\n      NOMBRE: ");
                        scanf("%s",&Person.Nombre);
                        do
                        {
                            printf("\n      EDAD: ");
                            scanf("%s",&Person.Edad);
                            isOK=ValidarInt(Person.Edad);
                            //VALIDO QUE LA CADENA SEA NUMERICA Y PONGO UN LIMITE DE EDAD A 170 AÑOS
                            if(isOK==0 || convertir_cadena_a_entero(Person.Edad)>170 || convertir_cadena_a_entero(Person.Edad)==0)
                            {
                                isOK=0;//REASIGNO VALOR EN CERO POR SI LA CADENA ES NUEMRICA PERO EXCEDE EL VALOR DE EDAD ACEPTABLE(EDAD CREIBLE)
                                printf("\n      INGRESE UN NUMERO VALIDO!\n");
                            }
                        }while(isOK==0);
                        do
                        {
                            printf("\n      DNI: ");
                            scanf("%s",&Person.DNI);
                            isOK=ValidarInt(Person.DNI);
                            //VALIDO QUE LA CADENA SEA NUMERICA Y PONGO UN LIMITE DE CARACTERES PARA 99.999.999
                            if(isOK==0 || LengtCadena(Person.DNI)>8 || LengtCadena(Person.DNI)<7)
                            {
                                isOK=0;//REASIGNO VALOR EN CERO POR SI LA CADENA ES NUEMRICA PERO EXCEDE LA CANTIDAD DE DIGITOS PERMITIDOS
                                printf("\n      INGRESE UN DNI VALIDO!\n");
                            }
                        }while(isOK==0);

                        //CARGO OBJRETO Person EN LISTA Personas PARA GRABAR EL NUEVO REGISTRO
                        ListPersonas[UltimoId].Id=Person.Id;
                        strcpy(ListPersonas[UltimoId].Nombre,Person.Nombre);
                        strcpy(ListPersonas[UltimoId].Edad,Person.Edad);
                        strcpy(ListPersonas[UltimoId].DNI,Person.DNI);
                        //MENSAJE DE CONFIRMACION DE CARGA EXITOSA
                        printf("\n      REGISTRO CARGADO CORRECTAMENTE!\n\n");
                        //INCREMENTAMOS EL CONTADOR DE REGISTROS CARGADOS
                        UltimoId = UltimoId+1;
                        if(UltimoId>CantPersonas)
                        {
                            //SI EXEDEMOS LA CANTIDAD DE REGISTROS DE LA LISTA RESETEAMOS
                            UltimoId=0;
                        }
                    }
                    /*PREGUNTAMOS SI DESEA SALIR O NO DE LA PANTALLA*/
                    printf("_________________________________________________________________________\n");
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    system("cls");
                    break;
                }
            case 2:
                {
                    printf("\n***************************BORRAR PERSONAL*******************************\n");
                    //DEFINIMOS PARAMETRO DE BUSQUEDA, EN ESTE CASO CAMPO NOMBRE
                    printf("\n      BUSCAR NOMBRE: ");
                    scanf("%s",&Person.Nombre);
                    //INICIALIZAMOS CONTADOR DE REGISTROS ENCONTRADOS POR BUSQUEDA
                    int CantRegEncontrados = 0;
                    //RECORREMOS LA LISTA,MOSTRAMOS Y GUARDAMOS LOS RESULTADOS DE LA MISMA
                    printf("\n>RESULTADO:\n");
                    for(x=0;x<CantPersonas;x++)
                    {
                         if(strcmp(ListPersonas[x].Nombre,Person.Nombre)==0)
                         {
                             //CUENTO CANTIDAD DE REGISTROS ENCONTRADOS
                              CantRegEncontrados = CantRegEncontrados+1;
                              //MUESTRO EN PANTALLA REGISTRO/S RESULTANTE
                              printf("\nNro de Registro: %d\n",(ListPersonas[x].Id+1));
                              printf("Nombre: %s\n",ListPersonas[x].Nombre);
                              printf("Edad: %s\n",ListPersonas[x].Edad);
                              printf("DNI: %s\n",ListPersonas[x].DNI);
                              //GUARDO REGISTRO/S RESULTANTE
                              ListPersonasConsulta[x].Id=ListPersonas[x].Id;
                              strcpy(ListPersonasConsulta[x].Nombre,ListPersonas[x].Nombre);
                              strcpy(ListPersonasConsulta[x].Edad,ListPersonas[x].Edad);
                              strcpy(ListPersonasConsulta[x].DNI,ListPersonas[x].DNI);
                         }
                    }
                    //VERIFICAMOS QUE EXISTA AL MENOS UN RESULTADO PARA LA BUSQUEDA REALIZADA
                    if(CantRegEncontrados == 0)
                    {
                        //SI NO HAY COINCIDENCIAS MOSTRAMOS UN MENSAJE
                        printf("\nNO SE ENCONTRARON RESULTADOS!\n");
                    }
                    else
                    {
                        //INICIALIZAMOS INDICE DE SELECCION DE REGISTRO
                        int RegSeleccionado = -1;
                        if(CantRegEncontrados > 1)
                        {
                            do{
                                //SI HAY VARIOS REGISTROS COINCIDENTES PREGUNTAMOS CUAL QUIERE ELIMINAR
                                char ReadVal[]="";
                                printf("\nSeleccione Nro de Registro a eliminar: ");
                                scanf("%s",&ReadVal);
                                //RECORREMOS LISTA DE RESULTADOS PARA VALIDAR COINCIDENCIA
                                for(x=0;x<CantPersonas;x++)
                                {
                                    if(ListPersonasConsulta[x].Id==convertir_cadena_a_entero(ReadVal)-1)
                                    {
                                        RegSeleccionado=ListPersonasConsulta[x].Id;
                                    }
                                }
                                //SI NO HAY RELACION ENTRE EL VALOR INGRESADO Y LOS RESULTADOS MOSTRAMOS UN MENSAJE
                                if(RegSeleccionado==-1)
                                {
                                    printf("\nEL VALOR INGRESADO NO COINCIDE CON EL RESULTADO DE LA BUSQUEDA REALIZADA..\n");
                                }
                            }while(RegSeleccionado==-1);
                        }
                        else
                        {
                            //SI ENCONTRAMOS UN SOLO REGISTRO, LO SELECCIONAMOS POR DEFAULT PARA ELIMINARLO
                            RegSeleccionado = ListPersonasConsulta[0].Id;
                        }

                        printf("\n\n>>REGISTRO SELECIONADO\n");
                        printf("\nNro de Registro: %d\n",(ListPersonas[RegSeleccionado].Id+1));
                        printf("Nombre: %s\n",ListPersonas[RegSeleccionado].Nombre);
                        printf("Edad: %s\n",ListPersonas[RegSeleccionado].Edad);
                        printf("DNI: %s\n",ListPersonas[RegSeleccionado].DNI);
                        //CONFIRMAMOS SI DESEA BORRAR EL REGISTRO
                        int Respuesta = MensajeYESNO("Esta seguro que desea eliminar este registro?");
                        if(Respuesta==1) //SI LA RESPUESTA ES POSITIVA "ELIMINAMOS" REGISTRO
                        {
                            strcpy(ListPersonas[RegSeleccionado].Nombre,"X");
                            strcpy(ListPersonas[RegSeleccionado].Edad,"X");
                            strcpy(ListPersonas[RegSeleccionado].DNI,"X");
                            printf("\nEL REGISTRO SE ELIMINO CORRECTAMENTE!");
                        }
                    }
                    printf("\n\n");
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    printf("_________________________________________________________________________\n");
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 3: //IMPRIMIR LISTA POR NOMBRE
                {
                    printf("\n*************************LISTADO DE PERSONAL*****************************\n");
                    //INICIALIZAMOS CONTADOR DE REGISTROS ENCONTRADOS POR BUSQUEDA
                    int CantRegEncontrados = 0;
                    //RECORREMOS LA LISTA,MOSTRAMOS Y GUARDAMOS LOS RESULTADOS DE LA MISMA
                    printf("\n>RESULTADO:\n");
                    //ORDENA POR NRO DE REGISTRO MENOR A MAYOR
                    /*for(x = 0; x < CantPersonas;x++)
                    {
                        if(ListPersonas[x].Edad[0] != 'X')
                        {
                            //CUENTO CANTIDAD DE REGISTROS ENCONTRADOS
                           CantRegEncontrados = CantRegEncontrados+1;
                           printf("\nNro de Registro: %d\n",(ListPersonas[x].Id)+1);
                           printf("Nombre: %s\n",ListPersonas[x].Nombre);
                           printf("Edad: %s\n",ListPersonas[x].Edad);
                           printf("DNI: %s\n",ListPersonas[x].DNI);
                        }
                    }
                    //ORDENA POR NRO DE REGISTRO MAYOR A MENOR
                    for(x = CantPersonas; x > CantPersonas;x--)
                    {
                        if(ListPersonas[x].Edad[0] != 'X')
                        {
                           //CUENTO CANTIDAD DE REGISTROS ENCONTRADOS
                           CantRegEncontrados = CantRegEncontrados+1;
                           printf("\nNro de Registro: %d\n",(ListPersonas[x].Id)+1);
                           printf("Nombre: %s\n",ListPersonas[x].Nombre);
                           printf("Edad: %s\n",ListPersonas[x].Edad);
                           printf("DNI: %s\n",ListPersonas[x].DNI);
                        }
                    }*/
                    //ORDENA POR ORDEN ALFABETICO DE NOMBRE
                    //CREAMOS UNA LISTA IGUAL A LA QUE TENEMOS CARGADA PARA MODIFICARLA SIN PERDER EL ORDEN DE REGISTRO ORIGINAL(POR SI QUIERO ACTIVAR LAS OPCIONES COMENTADAS ANTES, SERIA MAS RAPIDO AL MODIFICAR EL CODIGO)
                    struct Persona ListPersonaxNombre[CantPersonas];
                    for(x=0;x<CantPersonas;x++)
                    {
                        ListPersonaxNombre[x] = ListPersonas[x];
                        //CONTAMOS REGISTROS LLENOS
                        if(ListPersonas[x].Edad[0] != 'X')
                        {
                            //CUENTO CANTIDAD DE REGISTROS ENCONTRADOS
                           CantRegEncontrados = CantRegEncontrados+1;
                        }
                    }
                    //RECORREMOS LA LISTA COMPARANDO POR PESO ALFABETICO Y ORDENANDO SOBRE LA LISTA COPIADA
                    int i,j;
                    for(i=0; i<CantPersonas-1; i++)
                    {
                        for(j=i+1; j<CantPersonas; j++)
                        {
                            if(strcmp(ListPersonaxNombre[i].Nombre, ListPersonaxNombre[j].Nombre) > 0)
                            {
                                Person = ListPersonaxNombre[i];
                                ListPersonaxNombre[i] = ListPersonaxNombre[j];
                                ListPersonaxNombre[j] = Person;
                            }
                        }
                    }
                    //MOSTRAMOS LA LISTA COPIADA YA ORDENADA
                    for(x = 0; x < CantPersonas;x++)
                    {
                        if(ListPersonaxNombre[x].Edad[0] != 'X')
                        {
                           printf("\nNro de Registro: %d\n",(ListPersonaxNombre[x].Id)+1);
                           printf("Nombre: %s\n",ListPersonaxNombre[x].Nombre);
                           printf("Edad: %s\n",ListPersonaxNombre[x].Edad);
                           printf("DNI: %s\n",ListPersonaxNombre[x].DNI);
                        }
                    }
                    printf("\n>>REGISTROS ENCONTRADOS: %d\n",CantRegEncontrados);
                    printf("\n\n");
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    printf("_________________________________________________________________________\n");
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 4: //IMPRIMIR GRAFICO
                {
                    printf("\n**************************GRAFICO DE BARRAS******************************\n");
                    //DECLARAMOS E INICIALIZAMOS CONTADORES
                    int hasta18=0;
                    int de19a35=0;
                    int mayorDe35=0;
                    //RECORREMOS LISTA PREGUNTANDO POR CONDICION DE AGRUPAMIENTO
                    for(x=0;x<CantPersonas;x++)
                    {
                        if(ListPersonas[x].Edad[0] != 'X') //SI EL REGISTRO ESTA UTILIZADO
                        {
                            if(convertir_cadena_a_entero(ListPersonas[x].Edad)<19)
                            {
                                hasta18=hasta18+1;
                            }
                            else
                            {
                                if(convertir_cadena_a_entero(ListPersonas[x].Edad)>35)
                                {
                                    mayorDe35=mayorDe35+1;
                                }
                                else
                                {
                                    de19a35=de19a35+1;
                                }
                            }
                        }
                    }
                    GraficarX3Colum(hasta18,de19a35,mayorDe35);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    printf("_________________________________________________________________________\n");
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    printf("SALI DEL MENSAJE");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 5: //SALIMOS DE LA PANTALLA
                {
                    Seguir = 'N';
                    break;
                }
        }
    }
    return 0;
}
