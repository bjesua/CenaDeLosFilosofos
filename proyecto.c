#include <iostream>
#include<stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h> 

using namespace std;

int chinos = 5;
int posicionChinos[]={0,1,2,3,4,5};
int palillos = 5;
int posicionPalillos[]={0,1,2,3,4,5};
int randomActualChinos = 0;
int randomActualPalillos = 0;

int ranChino1;
int ranChino2;
int tenedores[]={0,0,0,0,0,0};
int tiempo = 3;

int tenOcupados[] = {0,0,0,0,0,0};
//asigna posiciones de los chinos y los palillos
void asignaPosiciones(){
    for(int i=1; i<=5; i++){
        // cout << "asigna: " << i << "\n";
        posicionChinos[i] = i;
        posicionPalillos[i] = i;
    }
    for(int e=1; e<=5; e++){
        // posicionPalillos[e] = e;
    }
}

//genera un numero random del 1 al 5
int generaRandom(){
    int ra = rand() % 5 + 1;
    return ra;
}

//imprime las posiciones
void imprimePosiciones(){
    // asignaPosiciones();
    for(int i = 1; i<=5; i++){
        // cout << i << ") Posicion Palillos: " << posicionPalillos[i] << " ||| Posicion Chinos: " << posicionChinos[i] << "\n";
    }
}


void comer(int ten1, int ten2, int jugadorActual){
    
    // cout << "Comiendo: " << ten1 <<" - "<< ten2 << "\n";
    cout << "\nFilosofos meditando ..............\n";
    if(tenOcupados[ten1] != 0){
       // tenedor ocupado 
       sleep(tiempo);
       cout << "\n Palillo "<< ten1 <<  " Ocupado no puede comer el Filosofo: " << jugadorActual << " Morira de inhanicion\n";
    }else{
        sleep(tiempo);
        tenOcupados[ten1] = jugadorActual;        
        cout << "\n El Filosofo: "<< jugadorActual << " Esta comiendo con el Palillo : " << ten1;
    }
    cout << "\nFilosofos meditando ..............\n";
    if(tenOcupados[ten2] != 0){
        sleep(tiempo);
       cout << "\n Palillo "<< ten2<<  " Ocupado no puede comer el Filosofo: " << jugadorActual << " Morira de inhanicion\n";
    }else{
        sleep(tiempo);
        tenOcupados[ten2] = jugadorActual;
        cout << "\n El Filosofo: "<< jugadorActual << " Esta comiendo con el Palillo : " << ten2;
    }

    
}

void jugar(int jugador){
    cout << "\n Jugador: " << jugador;
    if(posicionChinos[jugador]==1){
        cout << "\n A comer \n";
        comer(5,1,1); 
    }else if(posicionChinos[jugador]==2){
        cout << "\n A comer \n";
        comer(1,2,2); 
    }else if(posicionChinos[jugador]==3){
        cout << "\n A comer \n";
        comer(2,3,3); 
    }else if(posicionChinos[jugador]==4){
        cout << "\n A comer \n";
        comer(3,4,4); 
    }else if(posicionChinos[jugador]==5){
        cout << "\n A comer \n";
        comer(4,5,5); 
    }
}
void generaJugadores(){
    srand (time(NULL));
    srand((unsigned)time(0)); 
    // ranChino1 = rand() % 5 + 1;
    // ranChino2 = rand() % 5 + 1;
    
    while(ranChino1 == 0){
        ranChino1 = generaRandom();
    }
    ranChino2 = generaRandom();
    while(ranChino2 == ranChino1){
        if(ranChino2 == 0){
           ranChino2 = generaRandom(); 
        }
        ranChino2 = generaRandom();
    }
    
    // cout << ranChino1  << " - " << ranChino2 << "\n";
    jugar(ranChino1);
    jugar(ranChino2);
}
int main()
{
    
    srand((unsigned)time(0)); 
    // asignaPosiciones();
    imprimePosiciones();
    
    cout<<"\nIngrese cantidad de jugadas\n";
    int total;
    cin >> total;
    
   
    for(int i = 1 ; i<= total; i++){
        cout << "\n ----######--- Jugada ---#####---- " << i <<"\n";
        for(int e = 0 ; e<=5 ; e++){
            tenOcupados[e] = 0;
        }
        ranChino1 = rand() % 5 + 1;
        ranChino2 = rand() % 5 + 1;
        generaJugadores();
        sleep(tiempo);
    }    
  
    
    
}





















