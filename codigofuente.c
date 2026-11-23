// Librerias y compatibilidad
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> //Para prueba con sleep
#ifdef _WIN32
void limpiar();
void limpiar() {
  system("cls");
}
#else 
void limpiar();
void limpiar() {
  system("clear");
}
#endif

// Prototipos
void gensec(int vecsec[], int nivel);
void mostrar(int vecsec[], int nivel);
void input(int vecusu[], int nivel);
bool comparar(int vecsec[], int vecusu[], int nivel, bool continuar);
void limpiarui();

// Main
int main() {
  srand(time(NULL));
  int opc;
  int nivel = 1;
  int vecsec[nivel];
  int vecusu[nivel];
  bool continuar = true;
  do{
    printf("Chimon diche\n");
    printf("Jugar ...... 1\n");
    printf("Ver nivel ...... 2\n");
    printf("Salir ......... 4\n");
    printf("Selecciona una opcion: ");
    scanf("%d",&opc);
    switch(opc){
      case 1: 
      gensec(vecsec, nivel);
      mostrar(vecsec, nivel);
      input(vecusu, nivel);
      continuar = comparar(vecsec, vecusu, nivel, continuar);
      if (continuar == false) {
        printf("Perdiste!\n");
        nivel = 1;
        return 0;
      }
      else if (continuar == true) {
        printf("Felicidades!\n LLevas %d rondas y avanzas al nivel %d!\n", nivel, nivel+1);
        nivel ++;
        limpiarui();

      }
      break;

      case 2: 
      printf("Nivel: %d\n", nivel);
      limpiarui();
      break;


      default: 
      break;
    }
  } while(opc!=4); 
}
// Funciones.


void gensec(int vecsec[], int nivel) {
  for (int i = 0; i< nivel; i++) {
    vecsec[i] = rand() % 11;
  }

}

void mostrar(int vecsec[], int nivel) {
  limpiar();
  printf("Recuerda la secuencia!\n");
  for (int i= 0; i<nivel; i++) {
    sleep(3); // Cambiar por un for según el doc de Liz.
    printf("%d\n", vecsec[i]);
    sleep(3); // Cambiar por un for según el doc de Liz.
    limpiar();
  }
}

void input(int vecusu[], int nivel) {
    printf("Ingresa la secuencia, en orden:\n");
    for (int i= 0; i<nivel; i++) {
        scanf("%d", &vecusu[i]);
    }

}

bool comparar(int vecsec[], int vecusu[], int nivel, bool continuar) {
    for (int i = 0; i < nivel; i++) {
        if (vecsec[i] != vecusu[i]) {
            continuar = false;
        }
    }
    return continuar;

}
void limpiarui() {
    fflush(stdin);
    getchar();
    limpiar();
}
//  Yo lo hice es funcional y avanza niveles, prácticamente está acabado.
// Aún le faltan cosas pero cualquier movimiento importante consultarmelo por Whats o en persona, me ayudarían mucho si pudieran sacar bugs o casos límite. Traten de entenderlo.
// Para un funcionamiento óptimo, ejecuten en consola (de su compu, no con shell)
// Atte: Jassiel