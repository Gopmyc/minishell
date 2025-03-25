#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    (void)argc;  // On ignore argc et argv qui ne sont pas utilisés
    (void)argv;

    while (*envp) {  // Tant qu'il y a des variables d'environnement
        printf("%s\n", *envp);  // Affiche la variable
		envp++;  // Passe à la variable suivante
    }

    return 0;
}