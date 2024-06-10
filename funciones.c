#include <stdio.h>
#include <string.h>
#include "funciones.h"

void verPersonas(char personas[][4][20]) {
    printf("Nombre\t\tApellido\t\tCedula\t\tEstadoCivil\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\n", personas[i][0], personas[i][1], personas[i][2], personas[i][3]);
    }
}

void registrarMatrimonio(char personas[][4][20]) {
    char cedula1[20], cedula2[20];
    printf("Ingrese la cedula de la primera persona: ");
    scanf("%s", cedula1);
    printf("Ingrese la cedula de la segunda persona: ");
    scanf("%s", cedula2);

    int indice1 = buscarPersonaXCedula(personas, cedula1);
    int indice2 = buscarPersonaXCedula(personas, cedula2);

    if (indice1 != -1 && indice2 != -1) {
        strcpy(personas[indice1][3], cedula2);
        strcpy(personas[indice2][3], cedula1);
        printf("Matrimonio registrado correctamente.\n");
    } else {
        printf("Alguna de las cedulas no corresponde a una persona registrada.\n");
    }
}

void verificarPersona(char personas[][4][20]) {
    char cedula[20];
    printf("Ingrese la cedula de la persona a verificar: ");
    scanf("%s", cedula);

    int indice = buscarPersonaXCedula(personas, cedula);

    if (indice != -1) {
        printf("La persona con cedula %s es: %s %s\n", cedula, personas[indice][0], personas[indice][1]);
        
        if (strcmp(personas[indice][3], "soltero") != 0) {
            int indice_casado = buscarPersonaXCedula(personas, personas[indice][3]);
            if (indice_casado != -1) {
                printf("Está casada con: %s %s\n", personas[indice_casado][0], personas[indice_casado][1]);
            } else {
                printf("Error: No se encontró la persona con la que está casada.\n");
            }
        } else {
            printf("La persona no está casada.\n");
        }
    } else {
        printf("No se encontró ninguna persona con la cedula proporcionada.\n");
    }
}


int buscarPersonaXCedula(char personas[][4][20], char cedula[20]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(personas[i][2], cedula) == 0) {
            return i; 
        }
    }
    return -1; 
}
