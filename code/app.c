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


	// starting ask
	printf("For Testing version press: [1]\nFor user version press: [0]\n");
	int a = getInt();

	/*TESING VERSION*/
	if (a == 1) {
		testMode();
	}

	else {
		/*USER VERSION*/
		// main loop
		while (1) {
			system("cls");
			// start if user not login
			if (user_ptr == NULL) { startMode(); }

			// user session with all functions of system
			else { userSession(); }
		}
	}
	printf("\n");
	return 0;
}