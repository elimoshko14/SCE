#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*********************/
/*	Generic Includes */
#include "lib/globals.h"
#include "lib/structs.h"

//--------------------//
#include "lib/rw-task.h"
#include "lib/rw-proj.h"
#include "lib/rw_usr.h"
#include "lib/rw-ctgry.h"
//--------------------//

#include "lib/login.h"
/*********************/
/*	Unit Testing	 */

#include "unitTesting/getDbs.h"

int main(int argc, char *argv[]) {
	// init()
	// login();

	unitTestGetDbs();
	return 0;
}


