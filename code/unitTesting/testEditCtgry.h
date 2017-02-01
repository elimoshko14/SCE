bool unitTestEditCtgry() {
	
	addCat(5, "peace of shitt", 8, "-1");
	printCat(findCatById(5));
	UpdateCat(5, "of shitt",8,"-1");
	printCat(findCatById(5));
	unSetCat(5);
}