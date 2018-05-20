rps player_jjeanba2(int round,rps *myhist,rps *opphist) {
	//return Rock;
	
	int choseRock = 0;
	int chosePaper = 0;
	int choseScissors = 0;
	winner mostChosen = Rock;

	for (int i = 0; i < round - 1; i++) {
		//count how many times the opponent chose each possible 'winner'
		if (opphist[i] == Rock) choseRock += 1;
		if (opphist[i] == Paper) chosePaper += 1;
		if (opphist[i] == Scissors) choseScissors += 1;
	}

	//if paper is the highest value
	if (chosePaper > choseRock && chosePaper > choseScissors) mostChosen = Paper;

	//if rock is the highest value
	if (choseRock > chosePaper && choseRock > choseScissors) mostChosen = Rock;

	//if scissors is the highest value
	if (choseScissors > chosePaper && choseScissors > choseRock) mostChosen = Scissors;

	//find the option that has been most chosen and return
	//the option that beats it!
	switch (mostChosen) {
	
		//return paper bc it beats rock
		case Rock: return Paper; break;

		//return scissors bc it beats paper
		case Paper: return Scissors; break;

		//return rock bc it beats scissors
		case Scissors: return Rock; break;

		default: return Unknown;

	}

}

register_player(player_jjeanba2,"jjeanba2");
