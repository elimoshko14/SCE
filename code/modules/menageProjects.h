void management_projets() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] Add new project:\n", ++i);
		printf("[%d] Edit project:\n", ++i);
		printf("[%d] Delete project:\n", ++i);
		printf("[%d] Back to Menu\n", ++i);
		printf("-----------------------------------\n\n");

		printf("Make your choise: ");
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
				printf("%s\n", errors[0][1]);

			else {
				printf("Enter manager id for new project: ");
				manId = getInt();
				user * tmp = findUserById(manId);
				// if not found user
				if (tmp == NULL)
					printf("%s\n", errors[4][0]);


				// if this user worker or director we need only manager
				else if (tmp->level != 2) {
					printf("%s\n", errors[4][1]);
				}
				
				else {
					printf("Enter name of new project: ");
					getchar();  gets_s(name,256);
					printf("Enter cost of new project: ");
					cost = getInt();
					printf("Enter dead line of new project in format (d/m/y): ");
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
				printf("All Projects:\n");
				printProjTree();
				printf("Enter id of project which need to update\n");
				int id = getInt();
				proj *tmp = findProjById(id);

				// if found project update it
				if (tmp != NULL) {
					while (1) {
						system("cls");
						i = 0;
						printf("\n Update project %s\n----------------------\n", tmp->name);
						printf("[%d] Change Name:\n", ++i);
						printf("[%d] Change Cost:\n", ++i);
						printf("[%d] Change Due:\n", ++i);
						printf("[%d] Change Status\n", ++i);
						printf("[%d] Back to previous menu\n", ++i);
						int a = getInt();

						
						if (a== 1) { 
							char newName[256];
							printf("Enter New name: ");
							getchar(); gets_s(newName,256);
							updateProj(tmp->id, newName, tmp->manager_id, tmp->due, tmp->status, tmp->cost); 
							}

						else if(a==2) {
							printf("Enter New cost: ");
							int newCost = getInt();
							updateProj(tmp->id, tmp->name, tmp->manager_id, tmp->due, tmp->status, newCost); 
							}
						else if (a == 3) {
							char newDline[256];
							printf("Enter New dead line: ");
							getchar(); gets_s(newDline,256);
							updateProj(tmp->id, tmp->name, tmp->manager_id, newDline, tmp->status, tmp->cost);
							}

						else if (a == 4) {
							printf("Enter New status (0 or 1): ");
							int newStatus = getInt();
							if (newStatus > 1 || newStatus < 0)  printf("%s\n", errors[0][3]); 
							else updateProj(tmp->id, tmp->name, tmp->manager_id, tmp->due, newStatus, tmp->cost);
							}

						else if (a == 5) { break; }

						else { break; }
					}	
				}
					
				// not found project
				else {
					printf("%s\n", errors[0][0]);
				}
			}
			// arise error
			else {
				printf("%s\n", errors[0][2]);
			}
		}

		// delete
		else if (x == 3) {
			// if projects exist
			if (projects_list) {
				printf("All Projects:\n");
				printProjTree();
				printf("Enter id of project which need delete\n");
				int id = getInt();
				if (findProjById(id) == NULL)
					printf("%s\n", errors[0][0]);
				
				else {
					// delete current project
					unSetProj(id);

					// delete all categoryes of project
					//category_node * DelCats = categories_list;
					//if (DelCats) {
					//	while (DelCats) {
					//		if (DelCats->ptr->proj_id == id) {

					//			// delete all task by current category
					//			task_node * DelTask = tasks_list;
					//			if (DelTask) {
					//				while (DelTask) {
					//					if (DelTask->ptr->category_id == DelCats->ptr->id) {
					//						// delete Task
					//						unSetTask(DelTask->ptr->id);
					//					}
					//				DelTask = DelTask->next;
					//				}
					//			}
					//			//delete category
					//			unSetCat(DelCats->ptr->id);
					//		}
					//		DelCats = DelCats->next;
					//	}
					//}
					//// delete all comments by project
					//comment_node * DelComm = comments_list;
					//if (DelComm) {
					//	while (DelComm) {
					//		if (DelComm->ptr->porj_id == id) {
					//			// delete Comments
					//			unSetComment(DelComm->ptr->id);
					//		}
					//		DelComm = DelComm->next;
					//	}
					//}

					//// delete all users (workers, manager) by project
					//user_node * DelUser = users_list;
					//if (DelUser) {
					//	while (DelUser) {
					//		if (DelUser->ptr->porj_id == id) {
					//			// delete User
					//			unSetUser(DelUser->ptr->id);
					//		}
					//		DelUser = DelUser->next;
					//	}
					//}

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