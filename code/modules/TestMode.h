void testMode() {
	int ch;
	while (1) {
		printf("\n::TESTING VERSION OF PROJECT::\n============================================\n");
		testMenu();
		printf("\n\nMake your choose: ");
		ch = getInt();
		int i = 1;

		if (i == ch) { unitTestLogin(); }i++;
		if (i == ch) { unitTestGetDbs(); }i++;
		if (i == ch) { testDeleteNonActiveUsers(); }i++;
		if (i == ch) { unitTestManageProject(); }i++;
		if (i == ch) { unitTestNewUserInfo(); }i++;
		if (i == ch) { unittestPrintProj(); }i++;
		if (i == ch) { unitTestUpdateTask(); }i++;
		if (i == ch) { unittestCloneProj(); }i++;
		if (i == ch) { printf("\n\n Bye Bye \n\n"); return; }

		printf("\n============================================\n::FINISH TEST::\n\n");
		
	}
}