#include<iostream>
#include <string.h>
#include<CONIO.H>
#include "Jugador.cpp"
#include "Hilo_Dinero.cpp"
#include "Hilo_Vida.cpp"
#include "Hilo_Batalla.cpp"

using namespace std;

int main(){
	
	//Variable de control del nombre del jugador
	string nombre;
	
	cout<<"Ingrese su nombre: ";
	cin>>nombre;
	
	//Creacion del jugador
	Jugador jugador;
	
	//Creacion del Hilo del dinero
	Hilo_Dinero dinero;
	dinero.setVive(true);
	dinero.setTexto("Gano +1 de dinero");
	dinero.setEspera(7000);
	dinero.run();
	
	while(true){
		
		int op;
		
		cout<<"Menu\n\n\n";
		cout<<"1. Ver datos\n\n";
		cout<<"2. Curar un punto de vida<$1>\n\n";
		cout<<"3. Salir\n\n\n";
		cout<<"Ingrese una opcion: ";
		cin>>op;
		cout<<"\n\n\n";
		
		switch(op){
			
			case 1:
				
				if(dinero.getDinero()==1){
					jugador.setDinero(jugador.getDinero()+1);
					jugador.print();
					dinero.setDinero(0);
				}else{
					jugador.print();
				}//If auxilar de los datos del jugador
				
			break;
			
			case 3:
				exit(0);
				dinero.stop();
			break;
			
			default:
				cout<<"Opcion no valida\n\n";
			break;
			
		}//Fin de las opciones del jugador
		
	}//Fin repetitivo
	
	return 0;
	
}//Fin del main
