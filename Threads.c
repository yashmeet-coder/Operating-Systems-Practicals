#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum;                   
void *runner(void *param); 
int main(int argc, char *argv[])
{
    pthread_t tid;       
    pthread_attr_t attr;
     if (argc == 1)
    {
       fprintf(stderr, "Please enter the numbers to be added");
        return -1;
     }
    if (atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }
    
    if(atoi(argv[1])<argc-2)
{printf("Numbers exceed length");
return -1;}

if(atoi(argv[1])>argc-2)
{printf("Less numbers entered");
return -1;}

    int k=2;
    pthread_attr_init(&attr);
    for(int i=0;i<atoi(argv[1]);i++)
    pthread_create(&tid, &attr, runner, argv[k++]);

    pthread_join(tid, NULL);

    printf("sum %d\n", sum);
}

void *runner(void *param)
{
   
    sum += atoi(param);
   
    pthread_exit(0);
}