#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
    if(argc <= 1){
        printf("uses: ./cat [String]\n");
        return 0;
    }
    char cart[100] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
        'Q','R','S','T','U','V','W','X','Y','Z','a','b','c',
        'd','e','f','g','h','i','j','k','l','m','n','o','p',
        'q','r','s','t','u','v','w','x','y','z','0','1','2',
        '3','4','5','6','7','8','9',' ',',','.','/','<','>',
        '?',':',';','"','\'','[',']','{','}','\\','|','~','`',
        '!','@','#','$','%','^','&','*','(',')','-','_','+','='};
    char str[1000] ;
    strcpy(str,argv[1]);
    int k = 0;
    char st ;
    char finalStr[1000] = "";
    for(int i = 0; i < strlen(str);i++) finalStr[i] = '-';
    int j = 0;
    while(1){
        finalStr[j] = cart[k];
        k++;
        if(finalStr[j] == str[j]){
            j++;
            k = 0;
        }
        printf("\r[ %s ]",finalStr);
        fflush(stdout);
        usleep(50000);
        if(j >= strlen(str) || k>= 95) break;
    }
    printf("\n");
}