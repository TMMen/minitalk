#include "minitalk.h"

void signalhandler(int sig)
{
    static unsigned int i;
    static unsigned int asc;
    char                printable;

    if (sig == SIGUSR1)
    {
        asc = asc * 2;
    }
    else if (sig == SIGUSR2)
    {
        asc = asc * 2 + 1;
    }
    i++;
    if (i == 8)
    {
        printable = (char)asc;
        write(STDOUT_FILENO, &printable, 1);
        write(STDOUT_FILENO, "\0", 1);
        i = 0;
        asc = 0;
    }
}

void ft_id_server_print(int num)
{
    char    c;

    if (num > 9)
        ft_id_server_print(num / 10);
    c = '0' + num % 10;
    write(STDOUT_FILENO, &c, 1);
}

int main()
{
    ft_id_server_print(getpid());
    write(STDOUT_FILENO, "\n", 1);
    signal(SIGUSR1, signalhandler);
    signal(SIGUSR2, signalhandler);
    while (1)
    {
        pause();
        sleep(1);
    }
}
