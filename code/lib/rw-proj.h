void getProjects() {
	FILE *fptr;
	proj *proj_ptr;
	char msg[80];
	fptr = fopen("db\projects.txt","r");
	if (!fptr) 
		return 1;
	while (feof(fptr))
	{
		fscanf()
	}
	fclose(fptr);
	return 0;	
}