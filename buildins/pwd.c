#include <stdio.h>
#include <unistd.h>
#include <limits.h> // Pour PATH_MAX

void ft_pwd(void)
{
    char cwd[PATH_MAX]; // PATH_MAX est la taille max d'un chemin

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        perror("pwd"); // Affiche une erreur si `getcwd` échoue
}

int main(void)
{
    ft_pwd();
    return (0);
}