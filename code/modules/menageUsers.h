void management_users() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] %s:\n", ++i, i18("Add new user"));
		printf("[%d] %s:\n", ++i, i18("Edit user"));
		printf("[%d] %s:\n", ++i, i18("Delete user"));
		printf("[%d] %s\n", ++i, i18("Back to Menu"));
		printf("-----------------------------------\n\n");

		printf("%s: ", i18("Make your choise"));
		int x = getInt();

		// add
		if (x == 1) {
			int id, pId, salery, level;
			char name[256];
			
			if (user_ptr->level == 1) {
				printf("%s: ", i18("Enter ID of exist project"));
				pId = getInt();
			}
			else { pId = user_ptr->porj_id; }

			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", i18("Not found projects with this id"));

			else {
				printf("%s: ", i18("Enter unique id of new user"));
				id = getInt();
				if (findUserById(id) != NULL)
					printf("%s\n", i18("User is allready exist"));
				else {
					printf("%s: ", i18("Enter name of user"));
					getchar();  gets_s(name,256);
					printf("%s\n[2] %s\n[3] %s\n ", i18("Enter level of user"), i18("Manager"), i18("Worker"));
					level = getInt();
					printf("%s (in $): ", i18("Enter salery of new user"));
					salery = getInt(); 

					addUser(id, name, "EN", "1234", level, pId, 0, salery, 0, "-1");
				}
			}
		}

		// update
		else if (x == 2) {
			int  newSalery, newLevel;
			char newName[256];
			// it is possible update all fields except ID's
			

			// if projects exist
			if (projects_list) {
				int pId;
				if (user_ptr->level == 1) {
					printf("%s: ", i18("Enter ID of exist project"));
					pId = getInt();
				}
				else { pId = user_ptr->porj_id; }
				proj *tmpP = findProjById(pId);
				if (!tmpP)break;
				printf("%s [%s]:\n", i18("All Users in project"), tmpP->name);
				user_node * t = users_list;
				while (t) {
					if (t->ptr->porj_id == pId)
						printUser(t->ptr);
					t = t->next;
				}
				printf("%s\n", i18("Enter id of users which need to update"));
				int id = getInt();
				user * tmp = findUserById(id);

				// if found user update it
				if (tmp != NULL) {
					while (1) {
						
						i = 0;
						printf("\n %s %s\n----------------------\n", i18("Update user"), tmp->name);
						printf("[%d] %s:\n", ++i, i18("Change Name"));
						printf("[%d] %s:\n", ++i, i18("Change Salery"));
						printf("[%d] %s\n", ++i, i18("Change Current Task"));
						printf("[%d] %s:\n", ++i, i18("Change Level"));
						printf("[%d] %s:\n", ++i, i18("Change Language of system"));
						printf("[%d] %s\n", ++i, i18("Back to previous menu"));
						int a = getInt();

						if (a == 1) {
							printf("%s: ", i18("Enter New name"));
							getchar(); gets_s(newName,256);
							updateUser(tmp->id, newName, tmp->lang, tmp->password, tmp->level, tmp->porj_id, tmp->task_id, tmp->salery, tmp->online, tmp->coments);
						}

						else if (a == 2) {
							printf("%s ($): ", i18("Enter New salery in"));
							newSalery = getInt();
							updateUser(tmp->id, tmp->name, tmp->lang, tmp->password, tmp->level, tmp->porj_id, tmp->task_id, newSalery, tmp->online, tmp->coments);
						}
						else if (a == 3) {
							printf("%s: ", i18("Enter task id"));
							int tId = getInt();
							task *tmpT = findTaskById(tId);
							if (tmpT == NULL) {
								printf("%s\n", i18("Not found task with this id"));
							}
							else if(tmpT->user_id != 0) {
								printf("%s\n", i18("Another user is allready do it"));
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
							printf("%s\n[2] %s\n[3] %s\n: ", i18("Enter New level"), i18("Manager"), i18("Worker"));
							newLevel = getInt();
							if (newLevel > 3 || newLevel < 2)  printf("%s\n", i18("Level of this user is not appropriate"));
							else updateUser(tmp->id, tmp->name, tmp->lang, tmp->password, newLevel, tmp->porj_id, tmp->task_id, tmp->salery, tmp->online, tmp->coments);
						}

						else if (a == 5) { 
							printf("%s \n[1]EN\n[2]RU: ", i18("Choose New language"));
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
					printf("%s\n", i18("User not found!"));
				}
			}
			// arise error no projects => no users (except director)
			else {
				printf("%s\n", i18("Projects List is empty"));
			}
		}

		// delete
		else if (x == 3) {
			// if user exists
			if (users_list) {
				int pId;
				if (user_ptr->level == 1) {
					printf("%s: ", i18("Enter ID of exist project"));
					pId = getInt();
				}
				else { pId = user_ptr->porj_id; }
				proj *tmpP = findProjById(pId);
				if (!tmpP)break;
				printf("%s [%s]:\n",i18("All Users in project"), tmpP->name);
				user_node * t = users_list;
				while (t) {
					if (t->ptr->porj_id == pId)
						printUser(t->ptr);
					t = t->next;
				}
				printf("%s\n", i18("Enter id of user which need to delete"));
				int id = getInt();
				user *tmpU = findUserById(id);
				if (tmpU == NULL)
					printf("%s\n", i18("User not found!"));
				
				else {
					int task_id = tmpU->task_id;
					int porj_id = tmpU->porj_id;
					unSetUser(id);
				}
			}
			else {
				printf("%s\n", i18("User list empty"));
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