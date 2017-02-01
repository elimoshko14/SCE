void testMode() {
	int tCh;
	while (1) {
		system("cls");
		printf("\n::TESTING VERSION OF PROJECT::\n============================================\n");
		testMenu();
		printf("\n\nMake your choose: ");
			tCh = getInt();
			testChoose(tCh);
			printf("\n============================================\n::FINISH TEST::\n\n");
			system("pause");
	}
}