#include "minitalk.h"

void ft_send_to_server(int id_server, int c)
{
    unsigned int    i;

    i = 0;
    while (i < 8)
    {
        if (((c >> (7 - i)) & 1 ) == 1)
            kill(id_server, SIGUSR2);
        else
            kill(id_server, SIGUSR1);
        usleep(50);
        i++;
    }
}

void ft_string_send(int id_server, char *str)
{
    while(*str)
    {
        ft_send_to_server(id_server, (int)*str);
        str++;
    }
    ft_send_to_server(id_server, '\n');
}

int main(int argc, char **argv)
{
    int id_server;

    if (argc == 3)
    {
        id_server = ft_atoi(argv[1]);
        if (id_server < 1)
        {
            write(STDOUT_FILENO, "first argument must be valid server id\n", 40);
            return (EXIT_FAILURE);
        }
        ft_string_send(id_server, argv[2]);
    }
    else
        return (EXIT_FAILURE);
}
