#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 10
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float salario;
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;
} eEmployee;

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

// Funciones Alumnos
void mostrarAlumno(eEmployee x);
void mostrarAlumnos(eEmployee vec[], int tam);
void ordenarAlumnos(eEmployee vec[], int tam);
void inicializarAlumnos(eEmployee vec[], int tam);
int buscarLibre(eEmployee vec[], int tam);
int buscarAlumno(int legajo, eEmployee vec[], int tam);
int altaAlumno(eEmployee vec[], int tam, int leg);
eEmployee newAlumno(int leg,char nombre[],int edad, char sexo, eFecha f, int idCarrera);
int bajaAlumno(eEmployee vec[], int tam);
int ModificarAlumno(eEmployee vec[], int tam);
int hardcodearAlumnos( eEmployee vec[], int tam, int cantidad);





int main()
{
    int legajo = 20000;
    char salir = 'n';
    eEmployee lista[TAM];

    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);


    do
    {

        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM);
            break;

        case 3:
            ModificarAlumno(lista, TAM);
            break;

        case 4:
            mostrarAlumnos(lista, TAM);
            break;

        case 5:
            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("======================\n");
    printf("****** TP_02 *********\n");
    printf("======================\n\n");
    printf("1-Alta Empleado\n");
    printf("2-Baja Empleado\n");
    printf("3-Modificar Empleado\n");
    printf("4-Listar Empleado\n");
    printf("5-Ordenar Empleado\n");
    printf("6-Informes Empleado\n");
    printf("7-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("****** Informes *******\n\n");
    printf(" 1-Mostrar Alumnos de una Carrera\n");
    printf(" 2-Mostrar Alumnos por Carrera\n");
    printf(" 3-Mostrar Cantidad de alumnos por Carrera\n");
    printf(" 4-Mostrar La Carrera con mas inscriptos\n");
    printf(" 5-Mostrar Mejor Promedio por Carrera\n");
    printf(" 6-Mostrar Alumnos Varones\n");
    printf(" 7-Mostrar Mujeres de Alguna Carrera\n");
    printf(" 8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf(" 9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron una determinada comida\n");
    printf("11-Listar cantidad de almuerzos x carrera\n");
    printf("12-Carrera amante de las milanesas\n");
    printf("13-Informe deuda alumno seleccionado\n");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void mostrarAlumno(eEmployee x)
{
    char descCarrera[20];


    printf("  %d  %10s   %d      %c       %3.2f     %02d/%02d/%d   %s\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.salario,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           descCarrera);
}

void mostrarAlumnos(eEmployee vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" Legajo    Nombre    Edad   Sexo  Salario   FIngreso  Carrera\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

void ordenarAlumnos(eEmployee vec[], int tam)
{
    eEmployee auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].sexo > vec[j].sexo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("Alumnos Ordenados\n\n");
}

void inicializarAlumnos(eEmployee vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eEmployee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eEmployee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eEmployee vec[], int tam, int leg)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    char sexo;
    int edad;
    int idCarrera;
    eFecha fecha;

    system("cls");

    printf("*****Alta Alumno*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        printf("Ingrese id carrera: ");
        scanf("%d", &idCarrera);

        vec[indice] = newAlumno(leg, nombre, edad, sexo, fecha, idCarrera);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eEmployee newAlumno(
    int leg,
    char nombre[],
    int edad,
    char sexo,
    eFecha fecha,
    int idCarrera
)
{

    eEmployee al;
    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.fechaIngreso = fecha;
    al.idCarrera = idCarrera;
    al.isEmpty = 0;

    return al;
}

int bajaAlumno(eEmployee vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese legajo\n\n");

    }
    else
    {
        mostrarAlumno(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

int ModificarAlumno(eEmployee vec[], int tam)
{

    int todoOk = 0;
    int legajo;
    int indice;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice]);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            /*printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota1);
            vec[indice].salario = (float) (vec[indice].nota1  + vec[indice].nota2)/2;*/
            break;

        case 2:
           /* printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota2);
            vec[indice].salario = (float) (vec[indice].nota1  + vec[indice].nota2)/2;*/
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}

int hardcodearAlumnos( eEmployee vec[], int tam, int cantidad)
{
    int cont = 0;

    eEmployee suplentes[]=
    {
        { 20000, "Juan", 20, 'm', 6, {12, 5, 2015}, 1002, 0},
        { 20001, "Alberto", 21, 'm', 5, {12, 5, 2019},1001, 0},
        { 20002, "Ana", 22, 'f', 4.5, {2, 7, 2018},1002, 0},
        { 20003, "Luis", 20, 'm', 8.5, {21, 5, 2018},1000, 0},
        { 20004, "Alicia", 21, 'f', 6.5, {11, 9, 2017},1001, 0},
        { 20005, "Diego", 23, 'm', 2, {12, 4, 2014},1000, 0},
        { 20006, "Sofia", 19, 'f', 8.5, {12, 2, 2014},1002, 0},
        { 20007, "Clara", 21, 'f', 3, {28, 8, 2018},1001, 0},
        { 20008, "Mauro", 20, 'm', 5.5, {23, 3, 2015},1001, 0},
        { 20009, "Daniela", 22, 'f', 4, {10, 10, 2016},1000, 0},
        { 20010, "Agustin", 24, 'm', 6.5, {1, 7, 2017},1002, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
