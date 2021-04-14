// CRUD mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <mysql.h>
#include<string>
#include"Cliente.h"

using namespace std;

void menu();
void ingresar();
void buscar();
void modificar();
void eliminar();

int main()
{
    menu();
}

void menu() {

        int  a = 0;
        do {
                    system("cls");
                    cout << "    TABLA CLIENTES" << endl;

                    cout << "----------------------" << endl;
                    cout << "QUE DESEA HACER: " << endl << endl;
                    cout << " INGRESAR DATOS                 [1]" << endl;
                    cout << " BUSCAR DATO                    [2]" << endl;
                    cout << " ACTUALIZAR DATOS               [3]" << endl;
                    cout << " ELIMINAR DATOS                 [4]" << endl;
                    cout << " LEER LISTA DE DATOS COMPLETA   [5]" << endl;
                    cout << " SALIR                          [6]" << endl;
                    cout << " Ingrese opcion: [ ]\b\b";
                    cin >> a;
                    switch (a)
                    {
                    case 1:
                        system("cls");
                        ingresar();
                        break;
                    case 2:
                        system("cls");
                        buscar();
                        break;
                    case 3:
                        system("cls");
                        modificar();
                        break;
                    case 4:
                        system("cls");
                        eliminar();
                        break;

                    case 5:
                        system("cls");
                        Cliente c = Cliente();
                        c.leer();
                        system("pause");
                        break;
                    }
                } while (a != 6);
}

void ingresar() {
    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "Ingrese Nit:";
    cin.ignore();
    getline(cin, nit);
    cout << "Ingrese Nombres:";
    getline(cin, nombres);
    cout << "Ingrese Apellidos:";
    getline(cin, apellidos);
    cout << "Ingrese Direccion:";
    getline(cin, direccion);
    cout << "Ingrese Telefono:";
    cin >> telefono;
    cin.ignore();
    cout << "Fecha Nacimiento:";
    cin >> fecha_nacimiento;

    Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

    c.crear();
    system("pause");
}
void buscar() {
    string nit;
        cout << "POR FAVOR INGRESE EL ID DE LA MARCA PARA VER SU INFORMACION: ";
        cin.ignore();
        getline(cin, nit);
        Cliente c = Cliente("", "", "", 0, "", nit);
        c.buscar();
    system("pause");
}
void modificar() {
    string nit;
    cout << "Ingrese Nit Del Cliente a Modificar:";
    cin.ignore();
    getline(cin, nit);
    Cliente c = Cliente("", "", "", 0, "", nit);
    c.buscar();

    char respuesta;
    
            cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N]" << endl;
            cin >> respuesta;
            if ((respuesta == 's') || (respuesta == 'S')) {
                string nit1, nombres, apellidos, direccion, fecha_nacimiento;
                int telefono;
                
                cout << "Ingrese Nit:";
                cin.ignore();
                getline(cin, nit1);
                cout << "Ingrese Nombres:";
                getline(cin, nombres);
                cout << "Ingrese Apellidos:";
                getline(cin, apellidos);
                cout << "Ingrese Direccion:";
                getline(cin, direccion);
                cout << "Ingrese Telefono:";
                cin >> telefono;
                cin.ignore();
                cout << "Fecha Nacimiento usando el formato ANIO-MES-DIA:";
                cin >> fecha_nacimiento;
                Cliente c1 = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit1);
                c1.modificar(nit);
            }
        else
        {
            cout << "ERROR AL MODIFICAR..." << endl;
        }
    system("pause");
}
void eliminar() {
    string nit;
    cout << "Ingrese Nit Del Cliente a Eliminar:";
    cin.ignore();
    getline(cin, nit);
    Cliente c = Cliente("", "", "", 0, "", nit);
    c.buscar();
    char respuesta;
            cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N]" << endl;
            cin >> respuesta;
            if ((respuesta == 's') || (respuesta == 'S')) {
                c.eliminar(nit);
            }
        else
        {
            cout << "ELIMINACION FALLIDA..." << endl;
        }
    system("pause");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
