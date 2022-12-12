#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Memory Info\n");
    printf("Total memory\n");
    system("cat /proc/meminfo | awk 'NR==1'");
    printf("Free Memory\n");
    system("cat /proc/meminfo | awk 'NR==2'");
}