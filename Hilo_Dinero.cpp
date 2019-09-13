#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>
#include<string.h>
#ifndef HILO_DINERO_CPP
#define HILO_DINERO_CPP

using namespace std;

class Hilo_Dinero{
	
	private:
		
		bool vive;
		int espera;
		string texto;
		int dinero;//Variable para sumar el dinero del jugador
		
	public:
	
		Hilo_Dinero(){
			dinero=0;
		}//Constructor simple

		void setVive(bool vive){
			this->vive=vive;
		}//Set del vive
		
		void setTexto(string texto){
			this->texto=texto;
		}//Set del texto
		
		string getTexto(){
			return texto;
		}//Get del texto
		
		void setDinero(int dinero){
			this->dinero=dinero;
		}//Set del dinero del jugador despues de 7 segundos
		
		int getDinero(){
			return dinero;
		}//Get del dinero para del jugador despues de los 7 segundos
		
		void setEspera(int espera){
			this->espera=espera;
		}//Set del expera
		
		void stop(){
			vive=false;
		}//Detiene el hilo
		
		void run(){
			_beginthread(&Hilo_Dinero::runner,0,static_cast<void*>(this));
		}//Metodo run
		
		static void runner(void *o){
			static_cast<Hilo_Dinero*>(o)->runnerEstatico();
		}//Metodo runner
		
		void runnerEstatico(){
			
			while(vive){
				
				
				Sleep(espera);
				//MessageBox(0,texto.c_str(),"Advertencia",MB_OK);
				cout<<texto;
				dinero++;
				if(!vive){
					_endthread();
				}//Corre mientras sea verdadero
				
			}//While que hace la tarea del hilo
			
		}//Metodo de correr estatico
};
#endif
