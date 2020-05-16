#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/*
    Declaro  Estructura empleado
*/



/**
* \brief  To indicate that all position in the array are empty,
* \brief  this function put the flag (isEmpty) in TRUE in all
* \brief  position of the array
*
* \param  list Employee* Pointer to array of employees
* \param  lengthEmp int Array
*
* \return int Return (-1) if Error - (0) if Ok*/

int initEmployees(Employee* employees, int lengthEmp);

/**
* \brief  add in a existing list of employees the values received as parameters
* \brief  in the first empty position
*
* \param  list       employee*
* \param  lengthEmp  int
* \param  id         int
* \param  name[]     char
* \param  lastName[] char
* \param  salary     float
* \param  sector     int
*
* \return int Return (-1) if Error - (0) if Ok*/
int addEmployee(Employee* employees, int lengthEmp, int id, char name[],char lastName[],float salary,int sector);

/**
* \brief find an Employee by Id en returns the index position in array.
*
* \param  list      Employee*
* \param  lengthEmp int
* \param  id        int
*
* \return Return employee index position or (-1) if*/
int findEmployeeById(Employee* employees, int lengthEmp,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*         find a employee] - (0) if Ok*/

int removeEmployee(Employee* employees, int lengthEmp);
int printEmployees(Employee* employees, int lengthEmp);
int sortEmployeesByName(Employee* employees, int lengthEmp, int order);



/**
* \brief Muestra un menu con las opciones principales
*
* \param  Se declara Int opcion
*
* \return Return opcion*/
int mainMenu();

/**
* \brief Muestra el menu de reportes
*
* \param  Se declara funcion Int opcion
*
* \return Return opcion*/
int reportsMenu();

/**
* \brief Muestra el menu de las modificaciones a empleados
*
* \param  Se declara funcion Int opcion
*
* \return Return opcion*/
int modifyMenu();



/**
* \brief  Recibe un empleado y lo muestra por pantalla.
*
* \param  Se declara una variable int.
*
* \return Return 0 - OK*/
int printEmployee(Employee employee);


//mostrar espacio libre
/**
* \brief  Busca el primer id libre verificando que esta vacio
*
* \param  se declara una variable int
*
* \return Return Index - OK / -1 - FAIL*/
int findEmptyIndex(Employee* employees, int lengthEmp);

/**
* \brief  Asigna legajos a los empleados
*
* \param  list              Employee*
* \param  lengthEmp         int
* \param  id                int*
* \param  requestedRandomId int*
*
* \return Return 0 - OK / -1 - FAIL*/
int getRandomId(Employee* employees, int lengthEmp, int* requestedRandomId);

/**
* \brief  Recibe el id de un empleado, verifica a que sector pertenece y return del indice
*
* \param  list      Sectors*
* \param  empleado  Int
* \param  id        int*
* \param  index     int
*
* \return Return indice del sector asignado al empleado - OK / -1 - FAIL*/


/**
* \brief  Recibe los vectores empleados, busca por legajo por la funcion findEmployeeById
* \brief  si no lo encuentra devuelve un -1, si lo encuentra muestra por pantalla un menu
*
* \param  list       Employee*
* \param  lengthEmp  Int
* \param  idEmpleado int*
* \param  index      int
*
* \return Return 0 - OK / -1 - FAIL*/

int modifyEmployee(Employee* employees, int lengthEmp);

/**
* \brief  - Recibe el id del empleado
* \brief  - pide un nuevo nombre y lo guarda en un auxiliar
* \brief  - valida que sea solo letras (A-Z) y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el nombre por el valor del auxiliar
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  idEmpleado  int
* \param  auxName     char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifyNameEmployee(Employee* employees, int lengthEmp, int index);

/**
* \brief  - Recibe el id del empleado
* \brief  - Pide un nuevo apellido y lo guarda en un auxiliar
* \brief  - Valida que sea solo letras (A-Z) y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el nombre por el valor del auxiliar
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  idEmpleado  int
* \param  auxLastName char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifyLastNameEmployee(Employee* employees, int lengthEmp, int index);

/**
* \brief  - Recibe el id del empleado
* \brief  - Pide un nuevo salario y lo guarda en un auxiliar
* \brief  - Valida que sea solo numeros enteros y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el nombre por el valor del auxiliar
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  idEmpleado  int
* \param  auxSalary float
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifySalaryEmployee(Employee* employees, int lengthEmp, int index);

/**
* \brief  - Recibe el id del empleado
* \brief  - Muestra menu de sectores, pide que se elija uno y lo guarda en un auxiliar
* \brief  - Valida que sea solo numeros enteros y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el idSector del empleado por el valor del auxiliar nuevo
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  idEmpleado  int
* \param  auxLastName char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int modifySectorEmployee(Employee* employees, int lengthEmp, int index);

/**
* \brief  - Muestra menu de reportes, pide que se elija una opcion
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  lengthSec   Int
*
* \return Return 0 - OK / -1 - FAIL*/
int reports(Employee* employees, int lengthEmp);

/**
* \brief  - Muestra reporte de
* \brief  - TOTAL Salarios, Salario promedio, Empleados q superen ese promedio
*
* \param  list        Employee*
* \param  lengthEmp   Int
*/
void reportsSalary(Employee* employees, int lengthEmp);

/**
* \brief  - Muestra menu de sectores, pide que se elija uno y lo guarda en un auxiliar
* \brief  - Valida que sea solo numeros enteros y se encuentre entre el limite minimo y maximo
* \brief  - Reemplaza el idSector del empleado por el valor del auxiliar nuevo
*
* \param  list        Employee*
* \param  lengthEmp   Int
* \param  idEmpleado  int
* \param  auxLastName char
* \param  confirm     int
*
* \return Return 0 - OK / -1 - FAIL*/
int chooseSector(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief  - Muestra menu de ORDENAR APELLIDOs y SECTORES
*
* \param  option    int
*
* \return Return opcionElegida - OK / -1 - FAIL*/
int sortingMenu(Employee* employees, int lengthEmp);

/**
* \brief  - Swapping parameters
*
* \param  list        Employee*
* \param  lengthEmp   Int
*/
void bubbleSorting(Employee* employees, int lengthEmp, int i, int j);
