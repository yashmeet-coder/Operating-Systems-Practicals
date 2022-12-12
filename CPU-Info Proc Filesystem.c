#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nCPU Info\n");
    system("cat /proc/cpuinfo|awk 'NR==3'");
    system("cat /proc/cpuinfo|awk 'NR==8'");
    system("cat /proc/cpuinfo|awk 'NR==9'");
    system("cat /proc/cpuinfo|awk 'NR==13'");
    printf("\nCPU Model\n");
    system("cat /proc/cpuinfo|awk 'NR==5'");
    printf("\nKernel Version\n");
    system("cat /proc/version");
    printf("\n");
}
