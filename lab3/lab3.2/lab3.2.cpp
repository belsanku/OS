#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdio>
#include <signal.h>
#include <iostream>

using namespace std;


void oldman()
{
    fprintf(stdout, "I'm not yet dead! My ID is %i\n", (int) getpid());
}

void recreation()
{
    fprintf(stdout, "Who I am? My ID is %i\n", (int) getpid());
}

int main() {
    pid_t child_pid, parent_pid, temp1, temp2, temp3;
    int i=0;
    parent_pid=(int) getpid();
    fprintf(stdout, "Before RECREATION %i\n", parent_pid);
    if ((int)getpid() == (int)parent_pid) {
        child_pid=fork();
        //cout << getpid() << endl;
    }
    if ((int)getpid() == (int)parent_pid) {
        temp1=fork();
        //cout << getpid() << endl;
    }
    pause();
    while(i++<5) {
         if(child_pid!=0)
         {
             oldman();
             if(i==3) kill(child_pid,SIGKILL);
         }
         else
             recreation();
    }
    //pause();
    //getchar();
    return 0;
}