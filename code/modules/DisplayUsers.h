void displayUsersbyProject() {
	system("cls");
	if (projects_list == NULL) {
		printf("%s\n", errors[0][2]); return;
	}

	else {
		int pId;
		if (users_list) {
			if (user_ptr->level == 1) {
				printf("Enter ID of exist project: ");
				 pId = getInt();
			}
			else { pId = user_ptr->porj_id; }
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
	int pId;
		system("cls");
		if (projects_list == NULL) {
			printf("%s\n", errors[0][2]); return;
		}

		else {
			if (users_list) {
				if (user_ptr->level == 1) {
					user_node * tmp = users_list;
					while (tmp != NULL) {
						if (tmp->ptr->level == 3)
							printUser(tmp->ptr);
						tmp = tmp->next;
					}
				}
				else {
					pId = user_ptr->porj_id;
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
			user_node * tmp = users_list;
			while (tmp != NULL) {
				if (tmp->ptr->level == 2)
					printUser(tmp->ptr);
				tmp = tmp->next;
			}
			
		}
	}

	printf("To Back press [0]");
	int t = getInt();
}