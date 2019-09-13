#include<iostream>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

using namespace std;

class Jugador{
	
      private:
      	
	  	int dinero;
		int vida;
 		int vida_maxima;
		int nivel;
	    bool pelear;
	    
      public:
      	
        Jugador(){
        	dinero=0;
        	vida=1;
        	vida_maxima=3;
        	nivel=1;
        	pelear=false;
		}//Constructor vacio
             
        void setDinero(int dinero){
        	this->dinero=dinero;
        }//Set del dinero
             
        int getDinero(){
            return dinero;
        }//Get del dinero
		  
		void addDinero(){
			setDinero(getDinero()+1);
			cout<<"+1 de Dinero"<<endl;
		}//Agregar el dinero  
		     
        void setVida(int vida){
            this->vida=vida;
        }//Set de la vida
             
        int getVida(){
            return vida;
        }//Get de la vida
        
		void setVida_Maxima(int vida_maxima){
        	this->vida_maxima=vida_maxima;
        }//Set de la vida maxima
             
        int getVida_Maxima(){
            return vida_maxima;
        }//Get de la vida maxima
		
		void addVida(){
			
			if(getVida()+1<=getVida_Maxima()){
				setVida(getVida()+1);
				cout<<"+1 de Vida"<<endl;
			}else{
				cout<<"Vida al maximo"<<endl;
			}//Fin del if de la vida al maximo
			
		}//Agregar vida
		
		void comprarVida(){
			
			if(getDinero()>0){
				if(getVida()+1<=getVida_Maxima()){
					setVida(getVida()+1);
					setDinero(getDinero()-1);
					cout<<"+1 de Vida"<<endl;
				}else{
					cout<<"Vida al maximo"<<endl;
				}
			}else{
				cout<<"No tiene dinero"<<endl;
			}//If que valida si tiene el dinero suficiente
			
		}//Metodo para comprar mas vida
		
		void addVida_maxima(){
			setVida_Maxima(getVida_Maxima()+1);
		}//Agregar mas vida maxima
		
		void setNivel(int nivel){
            this->nivel=nivel;
        }//Set del nivel
             
        int getNivel(){
            return nivel;
        }//Get del nivel	 
		
		void addNivel(){
			setNivel(getNivel()+1);
		}//Agregar nivel
		
		void setPelear(bool pelear){
			this->pelear=pelear;
		}//Set de la pelea
		
		bool getPelear(){
			return pelear;
		}//get de la pelea
		  
        void print(){
        	cout<<"Dinero: "<<dinero<<endl;
        	cout<<"Vida: "<<vida<<endl;
        	cout<<"Vida Maxima: "<<vida_maxima<<endl;
        	cout<<"Nivel: "<<nivel<<endl;
			cout<<"\n\n\n\n";
        }//Metodo print 
        
        ~Jugador(){
		}//Destructor

};
#endif
