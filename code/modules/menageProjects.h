void management_projets() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] ", ++i);
		printf("%s\n", i18("Add new project:"));
		printf("[%d] ", ++i);
		printf("%s\n", i18("Edit project:"));
		printf("[%d] ", ++i);
		printf("%s\n", i18("Delete project:"));
		printf("[%d] ", ++i);
		printf("%s\n", i18("Back to Menu"));
		printf("-----------------------------------\n\n");

		printf("%s\n", i18("Make your choise:"));
		int x = getInt();

		// add
		if (x == 1) {
			int id, manId, cost;
			char due[256];
			char name[256];
			system("cls");
			id = ++unique_project_key;

			// if project is allready exist arise error
			if (findProjById(id) != NULL) 
				printf("%s\n", i18("Projects is allready exist"));

			else {
				printf("%s\n", i18("Enter manager id for new project:"));
				manId = getInt();
				user * tmp = findUserById(manId);
				// if not found user
				if (tmp == NULL)
					printf("%s\n", i18("User not found!"));


				// if this user worker or director we need only manager
				else if (tmp->level != 2) {
					printf("%s\n", i18("User is allready exist"));
				}
				
				else {
					printf("%s\n", i18("Enter name of new project:"));
					getchar();  gets_s(name,256);
					printf("%s\n", i18("Enter cost of new project:"));
					cost = getInt();
					printf("%s\n", i18("Enter dead line of new project in format (d/m/y):"));
					getchar();  gets_s(due,256);

					addProj(id, name, manId, cost, due);
				}
			}
		}

		// update
		else if (x == 2) {
			// it is possible update all fields except ID
			system("cls");

			// if projects exist
			if (projects_list) {
				printf("%s\n", i18("All Projects:"));
				printProjTree();
				printf("%s\n", i18("Enter id of project which need to update"));
				int id = getInt();
				proj *tmp = findProjById(id);

				// if found project update it
				if (tmp != NULL) {
					while (1) {
						system("cls");
						i = 0;
						printf("\n%s", i18("Update project"));
						printf(" %s\n----------------------\n", tmp->name);
						printf("[%d]", ++i);
						printf("%s\n", i18("Change Name:"));
						printf("[%d]", ++i);
						printf("%s\n", i18("Change Cost:"));
						printf("[%d]", ++i);
						printf("%s\n", i18("Change Due:"));
						printf("[%d]", ++i);
						printf("%s\n", i18("Change Status"));
						printf("[%d]", ++i);
						printf("%s\n", i18("Change Manager"));
						printf("[%d]", ++i);
						printf("%s\n", i18("Back to previous menu"));
						int a = getInt();

						
						if (a== 1) { 
							char newName[256];
							printf("%s\n", i18("Enter New name:"));
							getchar(); gets_s(newName,256);
							updateProj(tmp->id, newName, tmp->manager_id, tmp->due, tmp->status, tmp->cost); 
							}

						else if(a==2) {
							printf("%s\n", i18("Enter New cost:"));
							int newCost = getInt();
							updateProj(tmp->id, tmp->name, tmp->manager_id, tmp->due, tmp->status, newCost); 
							}
						else if (a == 3) {
							char newDline[256];
							printf("%s\n", i18("Enter New dead line:"));
							getchar(); gets_s(newDline,256);
							updateProj(tmp->id, tmp->name, tmp->manager_id, newDline, tmp->status, tmp->cost);
							}

						else if (a == 4) {
							printf("%s\n", i18("Enter New status (0 or 1):"));
							int newStatus = getInt();
							if (newStatus > 1 || newStatus < 0)  printf("%s\n", i18("Project status incorrect")); 
							else updateProj(tmp->id, tmp->name, tmp->manager_id, tmp->due, newStatus, tmp->cost);
							}

						else if (a == 5) {
							printf("%s\n", i18("Enter id of new Manager:"));
							int newMan = getInt();
							user * tmpU = findUserById(newMan);
							if ((tmpU != NULL) && (tmpU->level == 2) && (tmpU->porj_id == 0)) {
								updateProj(tmp->id, tmp->name, newMan, tmp->due, tmp->status, tmp->cost);

								updateUser(tmpU->id, tmpU->name, tmpU->lang, tmpU->password, tmpU->level, tmp->id, tmpU->task_id, tmpU->salery, tmpU->online, tmpU->coments);
							}
							else {
								printf("error:NULL-%d level-%d porj_id-%d", tmpU != NULL, tmpU->level == 2, tmpU->porj_id == 0);
							}
						}

						else if (a == 6) { break; }

						else { break; }
					}	
				}
					
				// not found project
				else {
					printf("%s\n", i18("Not found projects with this id"));
				}
			}
			// arise error
			else {
				printf("%s\n", i18("Projects List is empty"));
			}
		}

		// delete
		else if (x == 3) {
			// if projects exist
			if (projects_list) {
				printf("%s\n", i18("All Projects:"));
				printProjTree();
				printf("%s\n", i18("Enter id of project which need delete"));
				int id = getInt();
				if (findProjById(id) == NULL)
					printf("%s\n", i18("Not found projects with this id"));
				
				else {
					// delete current project
					unSetProj(id);

				}
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