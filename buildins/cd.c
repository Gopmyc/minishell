#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void ft_cd(int argc, char **argv, char **env)
{
    char *oldpwd;
    char cwd[4096]; // Buffer pour stocker le chemin actuel

    if (argc != 2) // Vérifier qu'on a exactement un argument
    {
        fprintf(stderr, "cd: wrong number of arguments\n");
        return;
    }
    oldpwd = getcwd(NULL, 0);    // Sauvegarde de l'ancien PWD
    if (!oldpwd)
    {
        perror("cd: getcwd");
        return;
    }
    if (chdir(argv[1]) != 0)    // Essayer de changer de répertoir
    {
        fprintf(stderr, "cd: %s: %s\n", argv[1], strerror(errno));
        free(oldpwd);
        return;
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL) // Mettre à jour OLDPWD et PWD	// Obtenir le nouveau chemin
    {
        setenv("OLDPWD", oldpwd, 1); // Met à jour OLDPWD
        setenv("PWD", cwd, 1);       // Met à jour PWD
    }
    else
        perror("cd: getcwd");
    free(oldpwd); // Libérer la mémoire allouée par getcwd()
}

int main(int argc, char **argv, char **env)
{
    ft_cd(argc, argv, env);
    return (0);
}