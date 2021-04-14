#pragma once
#include "Persona.h"
#include <mysql.h>
#include "ConexionBD.h"
#include <iostream>
#include <string>
using namespace std;
class Cliente : Persona
{
	//atributos
private: string nit;
	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn,  string n) :Persona(nom, ape, dir, tel,fn) {
		nit = n;
	}
	//METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setApellidos(string ape) { apellidos = ape; }

	void setDireccion(string dir) { direccion = dir; }

	void setTelefono(int tel) { telefono = tel; }

	//get (mostrar)

	string getNit() { return nit; }

	string getNombres() { return nombres; }

	string getApellidos() { return apellidos; }

	string getDireccion() { return direccion; }

	int getTelefono() { return telefono; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();

	}
	void buscar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes where nit ="+nit+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "ID CLIENTES    | NIT | NOMBRES\t| APELLIDOS\t| DIRECCION  | TELEFONO  | FECHA DE NACIMIENTO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "\t\t" << fila[1] << " |" << fila[2] << "\t|" << fila[3] << "\t|" << fila[4] << " \t|" << fila[5] << "\t|" << fila[6] << "|" << endl;
				}
			}
			else {
				cout << "error de conexion" << endl;
			}
			cn.cerrar_conexion();
		}
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "ID CLIENTES    | NIT | NOMBRES\t| APELLIDOS\t| DIRECCION  | TELEFONO  | FECHA DE NACIMIENTO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "\t\t" << fila[1] << " |" << fila[2] << "\t|" << fila[3] << "\t|" << fila[4] << " \t|" << fila[5] << "\t|" << fila[6] << "|" << endl;
				}
			}
			else {
				cout << "error de conexion" << endl;
			}
			cn.cerrar_conexion();
		}
	}
	void modificar(string n) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string consulta = "UPDATE clientes SET nit='" + nit + "',nombres='" + nombres + "',apellidos='" + apellidos + "',direccion='" + direccion + "',telefono=" + t + ",fecha_nacimiento='" + fecha_nacimiento + "' where nit='"+n+"';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar(string n) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string consulta = "delete  from clientes where nit='" + n + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
};