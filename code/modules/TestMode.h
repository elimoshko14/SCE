void testMode() {
	int ch;
	while (1) {
		int result = 0;
		printf("\n::TESTING VERSION OF PROJECT::\n============================================\n");
		testMenu();
		printf("\n\nMake your choose: ");
		ch = getInt();
		int i = 1;

		if (i == ch) {  result = unitTestLogin(); }i++;
		if (i == ch) {  result = unitTestGetDbs(); }i++;
		if (i == ch) {  result = unitTestSerch(); }i++;
		if (i == ch) {  result = unitTestDue(); }i++;
		if (i == ch) {  result = unitTestBonusManager(); }i++;
		if (i == ch) {  result = unitTestEditCtgry(); }i++;
		if (i == ch) {  result = testPrintProjWorker(); }i++;
		if (i == ch) {  result = testPrintTask(); }i++;
		if (i == ch) {  result = testDeleteNonActiveUsers(); }i++;
		if (i == ch) {  result = unitTestManageProject(); }i++;
		if (i == ch) {  result = unitTestNewUserInfo(); }i++;
		if (i == ch) {  result = unittestPrintProj(); }i++;
		if (i == ch) {  result = unitTestUpdateTask(); }i++;
		if (i == ch) {  result = unittestCloneProj(); }i++;
		if (i == ch) {  result = printf("\n\n Bye Bye \n\n"); return; }

		printf("\n============================================\n::FINISH TEST::\n\n");
		
	}
}