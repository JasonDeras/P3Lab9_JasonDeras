#include <iostream>
#include <string.h>
#include <conio.h>
#include "Hilo_Vida.cpp"
#include "Hilo_Batalla.cpp"
#include "Hilo_Dinero.cpp"

using namespace std;

int main(){
	//Variable del nombre
	string nombre;
	cout<<"Ingrese su nombre: ";
	cin>>nombre;
	cout<<"\n\n\n";
	
	//Instancia del jugador
	Jugador*jugador=new Jugador();

	//Creacion del hilo de dinero
	Hilo_Dinero h_dinero;
	h_dinero.setVive(true);	
	h_dinero.setEspera(7000);
	h_dinero.setJugador(jugador);
	h_dinero.run();
	
	//Creacion del hilo de la vida
	Hilo_Vida h_vida;
	h_vida.setVive(true);
	h_vida.setEspera(6000);
	h_vida.setJugador(jugador);
	h_vida.run();
	
	//Creacion del hilo de la batalla
	Hilo_Batalla h_batalla;
	h_batalla.setVive(true);
	h_batalla.setEspera(10000);
	h_batalla.setJugador(jugador);
	h_batalla.run();
	
	bool cond=true;
	
	while(cond){
		
		system("cls");
		cout<<"..::MENU::.."<<endl;
		cout<<"1)Datos del Jugador"<<endl
		<<"2) Curar Vida"<<endl
		<<"3) Salir"<<endl;
		int opcion;
		if(jugador->getPelear()==false){
			cin>>opcion;
		}else{
			opcion=4;
		}
		switch(opcion){
			case 1:{
				cout<<"Nivel: "<<jugador->getNivel()<<endl
				<<"Dinero: "<<jugador->getDinero()<<endl
				<<"Vida: "<<jugador->getVida()<<"/"<<jugador->getVida_Maxima()<<endl;
				system("pause");
				break;
			}
			case 2:{
				jugador->comprarVida();
				system("pause");
				break;
			}
			case 3:{
				cout<<"Sesion cerrada"<<endl;
				cond=false;
				break;
			}
			case 4:{
				cout<<"Batalla!"<<endl;
				int vidaop=jugador->getNivel();
				while(vidaop>0&&jugador->getVida()>0){
					cout<<"1) Piedra"<<endl
					<<"2) Papel"<<endl
					<<"3) Tijeras"<<endl;
					int opcion;
					cin>>opcion;
					opcion+=3;
					int enemy=(rand() % 3) + 1;
					switch(opcion){
						case 4:{
							if(enemy==1){
								cout<<"Empate"<<endl;
							}else if(enemy==2){
								jugador->setVida(jugador->getVida()-1);
								cout<<"Perdio la ronda"<<endl;
							}else{
								vidaop-=1;
								cout<<"Gano la ronda"<<endl;
							}
							break;
						}
						case 5:{
							if(enemy==1){
								vidaop-=1;
								cout<<"Gano la ronda"<<endl;
							}else if(enemy==2){
								cout<<"Empate"<<endl;
							}else{
								jugador->setVida(jugador->getVida()-1);
								cout<<"Perdio la ronda"<<endl;
							}
							break;
						}
						case 6:{
							if(enemy==1){
								jugador->setVida(jugador->getVida()-1);
								cout<<"Perdio la ronda"<<endl;
							}else if(enemy==2){
								vidaop-=1;
								cout<<"Gano la ronda"<<endl;
							}else{
								cout<<"Empate"<<endl;
							}
							break;
						}
					}
				}
				if(vidaop==0){
					jugador->addVida_maxima();
					jugador->addNivel();
					cout<<"Gano el encuentro!"<<endl
					<<"+1 de vida Maximo"<<endl
					<<"Siguiente Nivel!"<<endl;
				}else{
					cout<<"Usted ha perdido"<<endl;
					cout<<"Datos de Sesion:"<<endl
					<<"		Nombre: "<<nombre<<endl
					<<"		Nivel: "<<jugador->getNivel()<<endl
					<<"		Dinero: "<<jugador->getDinero()<<endl
					<<"		Vida Maxima: "<<jugador->getVida_Maxima()<<endl;
					h_dinero.stop();
					h_vida.stop();
					h_batalla.stop();
					exit(0);
				}
				jugador->setPelear(false);
				system("pause");
				break;
			}
		}
		
	}//Fin del while
	
	return 0;
}//Fin del main

