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
#include "lib/rw-cmnt.h"
//--------------------//

#include "lib/login.h"

/*********************/
/*	Unit Testing	 */

#include "unitTesting/testGetDbs.h"
#include "unitTesting/testLogin.h"
<<<<<<< HEAD
#include "unitTesting/testAddProj.h"
#include "unitTesting/testUpdateUser.h"
=======
#include "unitTesting/testAdd.h"
>>>>>>> 947993e458e6319382cdeab52893d0b72c7d3f1b

// DO NOT CHANGE BELOW

/*	Unit Testing MAIN 	 */
#include "unitTesting/unitTest.h"

int main() {
	unitTest();
	return 0;
}