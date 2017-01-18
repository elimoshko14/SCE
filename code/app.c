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

//--------------------//
#include "lib/rw-task.h"
#include "lib/rw-proj.h"
#include "lib/rw_usr.h"
#include "lib/rw-ctgry.h"
#include "lib/rw-cmnt.h"
//--------------------//
#include "modules/mainMenu.h"
#include "modules/login.h"
#include "modules/bonus_EEO.h"
// DO NOT CHANGE BELOW

/*	Unit Testing MAIN 	 */
#include "unitTesting/unitTest.h"

int main() {

	unitTest();

	return 0;
}