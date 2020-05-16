#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "arrayEmployees.h"
#include "validaciones.h"

#define TAM 1000


int main()
{
    char exit='s';
    char confirm;
    char requestedName[51];
    char requestedLastName[51];
    float requestedSalary;
    int requestedRandomId;
    int requestedSector;
    int emptySpace;
    int retry;
    int countEmployee=0;
    int validationName=0;
    int validationLastName=0;
    int validationSalary=0;
    int validationSector=0;
    Employee employees[TAM];


    initEmployees(employees,TAM);

    do
    {
        switch(mainMenu())
        {
        case 1:
            retry=0;

            emptySpace=findEmptyIndex(employees,TAM);

            if(emptySpace>=0)
            {

                getRandomId(employees,TAM,&requestedRandomId);
                do
                {

                    validationName=getString(requestedName,"Ingrese el nombre empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);

                    if(validationName==-1)
                    {

                        retry++;

                        if(retry>2)
                        {
                            break;
                        }
                    }
                }
                while(validationName==-1);

                if(validationName!=-1)
                {
                    retry=0;
                    do
                    {

                        validationLastName=getString(requestedLastName,"Ingrese el apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);

                        if(validationLastName==-1)
                        {
                            retry++;
                            if(retry>2)
                            {
                                break;
                            }
                        }
                    }
                    while(validationLastName==-1);
                }

                if(validationName!=-1 && validationLastName!=-1)
                {
                    retry=0;
                    do
                    {

                        validationSalary=getFloat(&requestedSalary,"Ingrese el salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,1000000);



                        if(validationSalary==-1)
                        {
                            retry++;
                            if(retry>2)
                            {
                                break;
                            }
                        }
                    }
                    while(validationSalary==-1);
                }

                if(validationName!=-1 && validationLastName!=-1 && validationSalary!=-1)
                {
                    do
                    {

                        validationSector=getInt(&requestedSector,"Ingrese sector del empleado [1-5]","Opcion invalida, rango [1-5]",1,5);



                        if(validationSector==-1)
                        {
                            retry++;
                            if(retry>2)
                            {
                                break;
                            }
                        }
                    }
                    while(validationSector==-1);
                }

                if((validationName!=-1) && (validationLastName!=-1) && (validationSalary!=-1) && (validationSector!=-1))
                {

                    addEmployee(employees,TAM,requestedRandomId,requestedName,requestedLastName,requestedSalary,requestedSector);
                    countEmployee++;
                }
                else
                {
                    printf("No se pudo validar al empleado\n\n");
                }
            }
            else
            {

                printf("No hay espacio para mas empleados\n");
            }
            system("pause");
            break;
        case 2:
            if(countEmployee>0)
            {
                modifyEmployee(employees,TAM);
            }
            else
            {
                printf("\nNo hay empleados cargados en el sistema\n\n");
            }
            system("pause");
            break;

        case 3:
            if(countEmployee>0)
            {
                removeEmployee(employees,TAM);
                countEmployee--;
            }
            else
            {
                printf("\nNo hay empleados cargados en el sistema\n\n");
            }
            system("pause");
            break;
        case 4:
            if(countEmployee>0)
            {
                reports(employees,TAM);
            }
            else
            {
                printf("\nNo hay empleados cargados en el sistema\n\n");
            }
            system("pause");
            break;
        case 5:
            printf("Desea salir? s/n\n");
            fflush(stdin);
            confirm=getch();

            if(tolower(confirm)=='s')
            {
                exit='n';
                printf("Programa finalizado\n");
                system("pause");
            }
            break;
        }
    }
    while(exit=='s');

    return 0;
}
