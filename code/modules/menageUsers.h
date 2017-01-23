void management_users() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] Add new user:\n", ++i);
		printf("[%d] Edit user:\n", ++i);
		printf("[%d] Delete user:\n", ++i);
		printf("[%d] Back to Menu\n", ++i);
		printf("-----------------------------------\n\n");

		printf("Make your choise: ");
		int x = getInt();

		// add
		if (x == 1) {
			int id, pId, salery, level;
			char name[256];
			system("cls");
			if (user_ptr->level == 1) {
				printf("Enter ID of exist project: ");
				pId = getInt();
			}
			else { pId = user_ptr->porj_id; }

			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", errors[0][0]);

			else {
				printf("Enter unique id of new user: ");
				id = getInt();
				if (findUserById(id) != NULL)
					printf("%s\n", errors[4][1]);
				else {
					printf("Enter name of user: ");
					getchar();  gets_s(name,256);
					printf("Enter level of user\n[2] Manager\n[3] Worker\n ");
					level = getInt();
					printf("Enter salery of new user (in $): ");
					salery = getInt(); 

					addUser(id, name, "EN", "String", level, pId, 0, salery, 0, "-1");
				}
			}
		}

		// update
		else if (x == 2) {
			int  newSalery, newLevel;
			char newName[256];
			// it is possible update all fields except ID's
			system("cls");

			// if projects exist
			if (projects_list) {
				int pId;
				if (user_ptr->level == 1) {
					printf("Enter ID of exist project: ");
					pId = getInt();
				}
				else { pId = user_ptr->porj_id; }
				proj *tmpP = findProjById(pId);
				
				printf("All Users in project [%s]:\n", tmpP->name);
				user_node * t = users_list;
				while (t) {
					if (t->ptr->porj_id == pId)
						printUser(t->ptr);
					t = t->next;
				}
				printf("Enter id of users which need to update\n");
				int id = getInt();
				user * tmp = findUserById(id);

				// if found user update it
				if (tmp != NULL) {
					while (1) {
						system("cls");
						i = 0;
						printf("\n Update user %s\n----------------------\n", tmp->name);
						printf("[%d] Change Name:\n", ++i);
						printf("[%d] Change Salery:\n", ++i);
						printf("[%d] Change Current Task\n", ++i);
						printf("[%d] Change Level:\n", ++i);
						printf("[%d] Change Language of system:\n", ++i);
						printf("[%d] Back to previous menu\n", ++i);
						int a = getInt();

						if (a == 1) {
							printf("Enter New name: ");
							getchar(); gets_s(newName,256);
							updateUser(tmp->id, newName, tmp->lang, tmp->password, tmp->level, tmp->porj_id, tmp->task_id, tmp->salery, tmp->online, tmp->coments);
						}

						else if (a == 2) {
							printf("Enter New salery in ($): ");
							newSalery = getInt();
							updateUser(tmp->id, tmp->name, tmp->lang, tmp->password, tmp->level, tmp->porj_id, tmp->task_id, newSalery, tmp->online, tmp->coments);
						}
						else if (a == 3) {
							printf("Enter task id: ");
							int tId = getInt();
							task *tmpT = findTaskById(tId);
							if (tmpT == NULL) {
								printf("%s\n", errors[2][0]);
							}
							else if(tmpT->user_id != 0) {
								printf("%s\n", errors[4][3]);
							}
							else {
								// first set new task to user
								updateUser(tmp->id, tmp->name, tmp->lang, tmp->password, tmp->level, tmp->porj_id, tId, tmp->salery, tmp->online, tmp->coments);
								//second set user to this task
								// attention tmp->id => user id
								updateTask(tmpT->id, tmpT->title, tmp->id, tmpT->category_id, tmpT->cost, tmpT->status, tmpT->tags, tmpT->due, tmpT->comments);
							}
						}

						else if (a == 4) {
							printf("Enter New level\n[2] Manager\n[3] Worker\n: ");
							newLevel = getInt();
							if (newLevel > 3 || newLevel < 2)  printf("%s\n", errors[4][2]);
							else updateUser(tmp->id, tmp->name, tmp->lang, tmp->password, newLevel, tmp->porj_id, tmp->task_id, tmp->salery, tmp->online, tmp->coments);
						}

						else if (a == 5) { 
							printf("Choose New language \n[1]EN\n[2]RU: ");
							int langChoose = getInt();
							char newLang[3];
							if (langChoose == 2) { strcpy(newLang, "EN"); }
							else { strcpy(newLang, "EN"); }

							updateUser(tmp->id, tmp->name, newLang, tmp->password, tmp->level, tmp->porj_id, tmp->task_id, tmp->salery, tmp->online, tmp->coments);
						}

						else if (a == 6) { break; }

						else { break; }
					}
				}
					
				// not found user
				else {
					printf("%s\n", errors[4][0]);
				}
			}
			// arise error no projects => no users (except director)
			else {
				printf("%s\n", errors[0][2]);
			}
		}

		// delete
		else if (x == 3) {
			// if user exists
			if (users_list) {
				int pId;
				if (user_ptr->level == 1) {
					printf("Enter ID of exist project: ");
					pId = getInt();
				}
				else { pId = user_ptr->porj_id; }
				proj *tmpP = findProjById(pId);

				printf("All Users in project [%s]:\n", tmpP->name);
				user_node * t = users_list;
				while (t) {
					if (t->ptr->porj_id == pId)
						printUser(t->ptr);
					t = t->next;
				}
				printf("Enter id of user which need to delete\n");
				int id = getInt();
				user *tmpU = findUserById(id);
				if (tmpU == NULL)
					printf("%s\n", errors[4][0]);
				
				else {
					int task_id = tmpU->task_id;
					int porj_id = tmpU->porj_id;
					unSetUser(id);
				}
			}
			else {
				printf("User list empty\n");
			}
		}

		// back to main menu
		else if (x == 4) {
			return;
		}

		// if choise is wrong back 
		else { return;  }
	}
}