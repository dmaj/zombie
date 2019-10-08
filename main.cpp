// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the
// child process is running. The child process
// becomes orphan.
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <thread>
#include <string>

using namespace std;

int i = 0;
int main(int argc, char *argv[])
{
    int zombies = 1;
    if (argc > 1)
    {
        zombies = stoi (argv[1]);
    }
    pid_t pid01 = fork();
    if (pid01 == 0)
    {
        while (i<zombies)
        {
            pid_t pid02 = fork();
            if (pid02 != 0)
            {
                printf ("Zombie mit PID: %i\n", pid02);
                i++;
            }
            else return (0);
        }
    }
    else
    {
        int status = 0;
        waitpid(pid01, &status, 0);
        std::this_thread::sleep_until(std::chrono::time_point<std::chrono::system_clock>::max());
    }
}
