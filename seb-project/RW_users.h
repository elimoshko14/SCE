#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "lib/structs.h"
#include <string.h>



void read_user()
{
	FILE *fp;
	users U;
    char buffer[1000];
	fopen("db/users.txt", "r");
	//1||Admin||0||1,45,8||3||10000||EN
	while (fgets(buffer, 1000, fp) != NULL) {
		str_split(str, '||');
	}
	fclose(fp);
}
