#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include<sys/wait.h>

// we are just writing/reading integers from pipe // 
int main(int argc, char* argv[])
{
    int fd[2];
    // 0 for reading
    // 1 for writing 
    if(pipe(fd) == -1){
        printf("error with creating pipe!\n");
        return 1;
    }
    int answer;
    printf("Choose Source: \n 1[child1] ------- 2[child2]: \n");
    scanf("%d",&answer);
    
    if(answer == 1) // Child one is created first and writes to pipe
    {
        int pid =fork();
        if (pid == 0) /* first child */
        {
            close(fd[0]);
            printf("Child 1[%d] writing...\n",getpid());
            int buff;
            printf("Enter your number:");
            scanf("%d",&buff);
            write(fd[1], &buff, sizeof(int)); // writing an integer to file descriptor 1[write]
            close(fd[1]);
        }
        // parent creating second child to read 
        if(pid !=0)
        {   wait(NULL); // parent waits until child1 gets input from user and completes writing to pipe
            int pid2 = fork(); // parents forks again for child2
            if(pid2 == 0) // second child process
            {
                printf("Child 2[ID: %d] reading...\n",getpid());
                close(fd[1]);
                int buff2;
                read(fd[0], &buff2, sizeof(int)); // reading from pipe 
                printf("Read from pipe = %d\n",buff2);
                close(fd[0]);
            }
            
        }
    }
    // ------------------------------------------------------
    if (answer == 2) // second child writes and first child reads
    {
        int pid = fork();
        if(pid != 0)
        {   
            int pid = fork(); // creating second child
            if(pid == 0) // second child process
            {
                int buff;
                printf("Child 2[ID: %d] writing ...\n",getpid());
                printf("Enter your message:");
                scanf("%d",&buff);
                write(fd[1], &buff, sizeof(int));
                close(fd[1]);
                
            }
            wait(NULL); // parent waiting until child2 gets user input and writes to pipe
            
        }
        if (pid == 0) // first child process
        {
            int buff2;
            printf("Child 1[ID: %d] reading...\n",getpid());
            close(fd[1]);
            read(fd[0], &buff2, sizeof(char));
            close(fd[0]);
            printf("Read from pipe= %d\n",buff2); // printing what was read from pipe, written by child2

        }
        
    }
    
    return 0;
}    
    