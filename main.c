#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char personas[10][4][20]={{"Juan","Perez","1234","4567"},
                              {"Luis","Almeida","2345","soltero"},
                              {"Mateo","Ramirez","3456","soltero"},
                              {"Ana","Guerra","4567","1234"},
                              {"Lorena","Guillen","5678","soltero"},
                              {"Maria","Alvarez","6789","0987"},
                              {"Esteban","Mendez","7890","soltero"},
                              {"Jose","Ayala","0987","6789"},
                              {"Monica","Freire","9876","soltero"},
                              {"Rocio","Valle","8765","soltero"}};
       
    int opcion1,opcion2;
    do
    {
        printf("Seleccione una opcion:\n1.Ver Personas\n2.Registrar Matrimonio\n3.Verificar Persona\n>>");
        scanf("%d",&opcion1);
        switch (opcion1)
        {
        case 1:
            verPersonas(personas);
            break;
        case 2:
            registrarMatrimonio(personas);
            break;
        case 3:
            verificarPersona(personas);
            break;
        default:
            break;
        }
        printf("Desea elegir otra opcion:\n1.Si\n2.No\n>>");
        scanf("%d",&opcion2);
    } while (opcion2==1);
    
    return 0;
}