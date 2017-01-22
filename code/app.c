#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*********************/
/*	Generic Includes */
#include "lib/globals.h"
#include "lib/structs.h"

//api methods//
#include "lib/api.h"

//system functions//
#include "modules/functions.h"

// init functions to bild all dinamic structures
void init() {
	getUsers();
	getProjs();
	getCategories();
	getTasks();

	getComments();
}

/*	Unit Testing MAIN 	 */
 #include "unitTesting/unitTest.h" 

int main() {
	// initialization of system
	init();

	// main loop
	while (1) {
		
		// start if user not login
		if (user_ptr == NULL) { startMode(); }

		// user session with all functions of system
		else { userSession(); }
	}

	printf("\n");
	return 0;
}