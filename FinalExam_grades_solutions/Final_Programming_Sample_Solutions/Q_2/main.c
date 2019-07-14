#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "calc.h"

int main()
{
    char s[100];
    load(s);
    calc(s);

    return 0;
}

