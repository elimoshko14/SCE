void displayUsersbyProject() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
		if (users_list) {
			printf("Enter ID of exist project: ");
			int pId = getInt();
			proj *tmpP = findProjById(pId);

			printf("All Users in project %s:\n", tmpP->name);
			user_node * t = users_list;
			while (t) {
				if (t->ptr->porj_id == pId)
					printUser(t->ptr);
				t = t->next;
			}
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}

void displayWorkers() {
		system("cls");
		if (projects_list == NULL) {
			printf("%s\n", errors[0][2]); return;
		}

		else {
			if (users_list) {
				printf("Enter ID of exist project: ");
				int pId = getInt();
				proj *tmpP = findProjById(pId);

				printf("All Workers in project %s:\n", tmpP->name);
				user_node * t = users_list;
				while (t) {
					if (t->ptr->porj_id == pId)
						if (t->ptr->level == 3)
							printUser(t->ptr);
					t = t->next;
				}
			}
		}

		printf("To Back press [0]");
		int t = getInt();
}

void displayManagers() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
		if (users_list) {
			printf("Enter ID of exist project: ");
			int pId = getInt();
			proj *tmpP = findProjById(pId);

			printf("All Workers in project %s:\n", tmpP->name);
			user_node * t = users_list;
			while (t) {
				if (t->ptr->porj_id == pId)
					if (t->ptr->level == 2)
						printUser(t->ptr);
				t = t->next;
			}
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}