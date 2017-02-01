#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*********************/
/*	Generic Includes */
#include "lib/globals.h"
#include "lib/structs.h"
#include "i18/helper.h"

//api methods//
#include "lib/api.h"
 
//system functions//
#include "modules/functions.h"

// init functions to bild all dinamic structures
void init() {
	system("chcp 1251");
	getUsers();
	getProjs();
	getCategories();
	getTasks();
	changeLang();
	getComments();
}

/*	Unit Testing MAIN 	 */
#include "unitTesting/unitTest.h" 

int main() {
	// initialization of system
	init();

	/*USER VERSION*/
	int a = 1;
	// main loop
	while (1) {
		/*TESING VERSION*/
		if (a == 0 || user_ptr == NULL) {
			// starting ask
			printf("For Testing version press: [0]\nFor user version press: [1]\nFor exit press: [2]\n");
			a = getInt();
			if (a == 0) unitTestSerch();
			else if (a == 2)
				break;
		}
		if (user_ptr == NULL)
			startMode();
		else userSession();
		a = 1;
	}
	printf("\n");
	return 0;
}