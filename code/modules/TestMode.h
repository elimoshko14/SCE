void testMode() {
	system("cls");
	printf("\n::WELCOME TO TESTING VERSION OF PROJECT::\n============================================\n");
	testMenu();
	printf("Make your choose: ");
	int tCh;
	while (1) {
			tCh = getInt();
			testChoose(tCh);
	}
}