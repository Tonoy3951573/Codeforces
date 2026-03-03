#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));
    int n;
    cin>>n;
    int dice = rand() % 6 + 1;
    printf("Dice: %d\n", dice);

    return 0;
}
