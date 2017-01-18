/*********************/
/*  NOT MAIN         */
/*  NOT MAIN         */
/*  NOT MAIN         */
/*  NOT MAIN         */

/*	Unit Testing	 */

/*  NOT MAIN         */
/*  NOT MAIN         */
/*  NOT MAIN         */

/*********************/
/*********************/
/*	Unit Testing	 */

#include "unitTesting/testGetDbs.h"
#include "unitTesting/testLogin.h"

// module unit test
#include "unitTesting/testUser.h";
#include "unitTesting/testProj.h";
#include "unitTesting/testTask.h";
#include "unitTesting/testCat.h";
#include "unitTesting/testComm.h";

void unitTest(){

	unitTestGetDbs();
    unitTestLogin();
	
	// unitTestCat();
	// unitTestComment();
	// unitTestProj();
	// unitTestUser();
	// unitTestTask();
}