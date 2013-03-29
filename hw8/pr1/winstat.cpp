#include "winstat.h"

Winstat::Winstat(){ //Constructor, creates vector for counting the 27 characters possible
	vector<int> v(27);
	stats = v;
}

void Winstat::add_ch(char ch){ //Updates frequencies of characters in stats. Brute-force switch method.
	switch(ch) {
		case 'a': ++stats[0]; break;
		case 'b': ++stats[1]; break;
		case 'c': ++stats[2]; break;
		case 'd': ++stats[3]; break;
		case 'e': ++stats[4]; break;
		case 'f': ++stats[5]; break;
		case 'g': ++stats[6]; break;
		case 'h': ++stats[7]; break;
		case 'i': ++stats[8]; break;
		case 'j': ++stats[9]; break;
		case 'k': ++stats[10]; break;
		case 'l': ++stats[11]; break;
		case 'm': ++stats[12]; break;
		case 'n': ++stats[13]; break;
		case 'o': ++stats[14]; break;
		case 'p': ++stats[15]; break;
		case 'q': ++stats[16]; break;
		case 'r': ++stats[17]; break;
		case 's': ++stats[18]; break;
		case 't': ++stats[19]; break;
		case 'u': ++stats[20]; break;
		case 'v': ++stats[21]; break;
		case 'w': ++stats[22]; break;
		case 'x': ++stats[23]; break;
		case 'y': ++stats[24]; break;
		case 'z': ++stats[25]; break;
		default: ++stats[26]; break;
	}
}

char Winstat::guess_ch(){ //Gives a random char determined from the frequencies within stats
	int total = 0;
	for(int i = 0; i < 27; ++i)
		total += stats[i];
	int rand_index = randint(1, total + 1);
	int sum = 0;
	int i = 0;
	while(sum < rand_index){
		sum += stats[i];
		++i;
	}
	--i; //i ends up 1 larger than index of correct value
	switch(i){
		case 0: return 'a';
		case 1: return 'b';
		case 2: return 'c';
		case 3: return 'd';
		case 4: return 'e';
		case 5: return 'f';
		case 6: return 'g';
		case 7: return 'h';
		case 8: return 'i';
		case 9: return 'j';
		case 10: return 'k';
		case 11: return 'l';
		case 12: return 'm';
		case 13: return 'n';
		case 14: return 'o';
		case 15: return 'p';
		case 16: return 'q';
		case 17: return 'r';
		case 18: return 's';
		case 19: return 't';
		case 20: return 'u';
		case 21: return 'v';
		case 22: return 'w';
		case 23: return 'x';
		case 24: return 'y';
		case 25: return 'z';
		default: return ' ';
	}
}
