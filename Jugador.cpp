#include<iostream>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

using namespace std;

class Jugador{
	
      private:
      	
	   string cuenta;
	   string nombre;
	   string carrera;
	   string usuario;
	   string password; 
	   string rol;
	   vector<Clase*>cursadas;
	    
      public:
      	
        Alumno(){
        	cuenta="";
        	nombre="";
        	carrera="";
        	usuario="";
        	password="";
        	rol="";
		}//Fin del constructor de la red
			             
        Alumno(string cuenta,string nombre,string carrera,string usuario,string password,string rol){
        	this->cuenta.assign(cuenta);
			this->nombre.assign(nombre);	
			this->usuario.assign(usuario);		
			this->password.assign(password);	
			this->rol.assign(rol);		              
        }//Fin del constructor sobrecargado
             
        void setCuenta(string cuenta){
            this->cuenta.assign(cuenta);
        }//Set de la cuenta
             
        string getCuenta(){
            return this->cuenta;
        }//Set de la cuenta
             
        void setNombre(string nombre){
            this->nombre.assign(nombre);
        }//Set del nombre
             
        string getNombre(){
            return this->nombre;
        }//Get del nombre
        
		void setCarrera(string carrera){
        	this->carrera.assign(carrera);
        }//Get de la carrera
             
        string getCarrera(){
            return this->carrera;
        }//Get de la carrera
		
		void setUsuario(string usuario){
            this->usuario.assign(usuario);
        }//Set del usuario
             
        string getUsuario(){
            return this->usuario;
        }//Get del usuario
		          
		void setPassword(string password){
            this->password.assign(password);
        }//Set de la password
             
        string getPassword(){
            return this->password;
        }//Get de la password
				        
		void setRol(string rol){
            this->rol.assign(rol);
        }//Set del rol
             
        string getRol(){
            return this->rol;
        }//Get del rol
		
		void setCursadas(vector<Clase*>cursadas){
            this->cursadas=cursadas;
        }//Set de las clases cursadas
             
        void setClase(Clase*clase){
            this->cursadas.push_back(clase);
        }//Set de una sola clase a cursar
             
        vector<Clase*> getCursadas(){
            return this->cursadas;
        }//Get del vector de las cursadas
        
        void remClase(int p){
        	cursadas.erase(cursadas.begin()+p);
		}//Metodo que remueve una clase cursada		 
		              
        void print(){
        	cout<<"Cuenta: "<<cuenta<<
        	" Nombre del alumno: "<<nombre<<
        	" Carrera: "<<carrera<<
        	" Usuario: "<<usuario<<
        	" Password: "<<password<<
			" Rol: "<<rol<<endl;
			cout<<"Clase cursadas"<<endl;
			for(int i=0;i<cursadas.size();i++){
        		cursadas.at(i)->print();
			}//Fin del for de las computadoras
			cout<<"\n\n\n\n";
        }//Fin del metodo print 
        
        ~Alumno(){
		}//Fin del destructor    
};
#endif
