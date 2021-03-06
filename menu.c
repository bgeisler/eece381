/*
 * menu.c
 *
 *  Created on: 2014-02-03
 *      Author: Kevin
 */

#include "menu.h"


char *display_string;//string to write to screen
char player_name[10];//player name
int count = 0;//count for player name
int playersconfig = 0;//number of players configured
int playerCharacter;
int playertype;
int hp = 50;
int gas = 25;
//int wind=0;//initialize to light
int audio_on = 0;
int big_exp = 0;
int cursor = 0;

void initState0() {
	playersconfig = 0;

	initScreen();
	clearCharBuffer();
	clearScreen();
	printString("TANKS", 36, 10);
	printString("NUMBER OF PLAYERS:", 10, 20);
	printString("_2", 28, 20);
	printString("HEALTH POINTS:", 10, 24);
	printString("50", 25, 24);
	printString("GAS:", 10, 28);
	printString("25", 15, 28);
/*	printString("WIND:", 10, 32);
	printString("LIGHT", 16, 32);*/
	printString("AUDIO:", 10, 32);
	printString("OFF", 17, 32);
//	printString("BIG EXPLOSIONS:", 10, 40);
//	printString("OFF", 26, 40);

	printString("PRESS SPACE", 33, 50);
	printString("CONTROLS:", 45, 20);
	printString("LEFT AND RIGHT ARROW : MOVE TANK", 45, 24);
	printString("UP AND DOWN ARROW : TILT GUN", 45, 28);
	printString("PGUP AND PGDOWN : CHANGE POWER", 45, 32);
	printString("Q : CHANGE WEAPON", 45, 36);
	printString("SPACE : FIRE", 45, 40);
	updateScreen();
}

void initState1(int playernum) {
	clearCharBuffer();
	clearScreen();
	playertype = COMPUTER;
	printString("TANKS", 36, 10);
	printString("Player #", 33, 14);
	if (playernum == pOne)
		printString("1", 42, 14);
	else if (playernum == pTwo)
		printString("2", 42, 14);
	else if (playernum == pThree)
		printString("3", 42, 14);
	else if (playernum == pFour)
		printString("4", 42, 14);
	//print player number
	printString("ENTER NAME:_", 14, 20);
	printString("CHANGE COLOR: ", 14, 24);
	printString("MARIO", 28, 24);//default
	//print player color
	printString("SELECT PLAYER TYPE: ", 14, 28);
	printString("COMP ", 34, 28);//default
	//print player type
	printString("PRESS SPACE TO START", 25, 50);
	updateScreen();
}

void state_0(int decode_mode, alt_8 buf) {
	if (decode_mode == KB_BINARY_MAKE_CODE && buf == SPACEBAR) {
		cursor = 0;
		state = 1;
		aOn = audio_on;
	} else if (decode_mode == KB_LONG_BINARY_MAKE_CODE) {
		if (buf == LEFT_ARROW) {
			if (cursor == 0) {//on # of players
				if (numPlayers > 2)
					numPlayers -= 1;
				updateNumPlayers();
				//				snprintf(display_string, sizeof(display_string), "%d",
				//						numPlayers);
				//				AdjustChar(display_string, 29, 20);
			} else if (cursor == 1) {//on health points
				if (hp > 50)
					hp -= 10;
				snprintf(display_string, sizeof(display_string), "%d", hp);
				AdjustChar(display_string, 25, 24);
				if (hp < 100)
					AdjustChar(" ", 27, 24);
			} else if (cursor == 2) {
				if (gas > 0)
					gas -= 5;
				snprintf(display_string, sizeof(display_string), "%d", gas);
				AdjustChar(display_string, 15, 28);
				if (gas < 100)
					AdjustChar(" ", 17, 28);
			}
			/*else if (cursor == 3) {
				if (windPower == 0) {
					windPower = 1;
					AdjustChar("STRONG", 16, 32);
				} else if (windPower == 1) {
					windPower = 0;
					AdjustChar("LIGHT", 16, 32);
					AdjustChar(" ", 21, 32);
				}
			}*/
			else if (cursor == 3) {
				if (audio_on == 0) {
					audio_on = 1;
					AdjustChar("ON", 17, 32);
					AdjustChar(" ", 19, 32);
				} else if (audio_on == 1) {
					audio_on = 0;
					AdjustChar("OFF", 17, 32);
				}
			}
			/*else if (cursor == 5) {
				if (big_exp == 0) {
					big_exp = 1;
					AdjustChar("ON", 26, 40);
					AdjustChar(" ", 28, 40);
				} else if (big_exp == 1) {
					big_exp = 0;
					AdjustChar("OFF", 26, 40);
				}
			}*/
		}
		if (buf == RIGHT_ARROW) {
			if (cursor == 0) {
				if (numPlayers < 4)
					numPlayers += 1;
				updateNumPlayers();
				/*				snprintf(display_string, sizeof(display_string), "%d",
				 numPlayers);
				 AdjustChar(display_string, 29, 20);*/
			} else if (cursor == 1) {//on health points
				if (hp < 100)
					hp += 10;
				snprintf(display_string, sizeof(display_string), "%d", hp);
				AdjustChar(display_string, 25, 24);
			} else if (cursor == 2) {
				if (gas < 100)
					gas += 5;
				snprintf(display_string, sizeof(display_string), "%d", gas);
				AdjustChar(display_string, 15, 28);
			}
			/*else if (cursor == 3) {
				if (windPower == 0) {
					windPower = 1;
					AdjustChar("STRONG", 16, 32);
				} else if (windPower == 1) {
					windPower = 0;
					AdjustChar("LIGHT", 16, 32);
					AdjustChar(" ", 21, 32);
				}
			}*/
			else if (cursor == 3) {
				if (audio_on == 0) {
					audio_on = 1;
					AdjustChar("ON", 17, 32);
					AdjustChar(" ", 19, 32);
				} else if (audio_on == 1) {
					audio_on = 0;
					AdjustChar("OFF", 17, 32);
				}
			}
/*			else if (cursor == 5) {
				if (big_exp == 0) {
					big_exp = 1;
					AdjustChar("ON", 26, 40);
					AdjustChar(" ", 28, 40);
				} else if (big_exp == 1) {
					big_exp = 0;
					AdjustChar("OFF", 26, 40);
				}
			}*/
		}
		if (buf == UP_ARROW) {
			if (cursor > 0) {
				cursor -= 1;
			}
			if (cursor == 0) {
				AdjustChar(" ", 24, 24);
				AdjustChar("_", 28, 20);
			} else if (cursor == 1) {
				AdjustChar("_", 24, 24);
				AdjustChar(" ", 14, 28);
			} else if (cursor == 2) {
				AdjustChar("_", 14, 28);
				AdjustChar(" ", 16, 32);
			}
/*			else if (cursor == 3) {
				AdjustChar("_", 15, 32);
				AdjustChar(" ", 23, 36);
			}*/
//			 else if (cursor == 4) {
//				AdjustChar("_", 23, 36);
//				AdjustChar(" ", 25, 40);
//			}
		}
		if (buf == DOWN_ARROW) {
			if (cursor < 3) {
				cursor += 1;
			}
			if (cursor == 1) {
				AdjustChar("_", 24, 24);
				AdjustChar(" ", 28, 20);
			} else if (cursor == 2) {
				AdjustChar("_", 14, 28);
				AdjustChar(" ", 24, 24);
			} else if (cursor == 3) {
				AdjustChar("_", 16, 32);
				AdjustChar(" ", 14, 28);
			}
/*
			else if (cursor == 4) {
				AdjustChar("_", 16, 36);
				AdjustChar(" ", 15, 32);
			}
*/
//			 else if (cursor == 5) {
//				AdjustChar("_", 25, 40);
//				AdjustChar(" ", 23, 36);
//			}
		}
	}
}

void state_1(int decode_mode, alt_8 buf, char ascii) {
	if (decode_mode == KB_ASCII_MAKE_CODE) {//letters
		Name_Entered(ascii);
	}

	else if (decode_mode == KB_BINARY_MAKE_CODE) {
		if (buf == SPACEBAR) {
			printf("SPACE HIT");
			//TODO: make an options menu to adust hp
			//printf("playerCharacter %i",playerCharacter);
			if (playersconfig < numPlayers - 1) {
				printf("first");
				if (count > 0) {
					initPlayer(playersconfig, playerCharacter, player_name, hp,
							gas, playertype);
				} else {
					initPlayer(playersconfig, playerCharacter, "Guest", hp,
							gas, playertype);
				}
				clearPlayerName();
				playersconfig++;//this corresponds to the player ID
				cursor = 0;
				count = 0;
				initState1(playersconfig);
			} else {
				printf("about to change to game state");
				if (count > 0) {
					initPlayer(playersconfig, playerCharacter, player_name, hp,
							gas, playertype);
				} else {
					initPlayer(playersconfig, playerCharacter, "Guest", hp,
							gas, playertype);
				}
				state = 2;
				if (numPlayers == 2) {
					initPlayer(pThree, MARIO, NULL, hp, gas, HUMAN);
					initPlayer(pFour, MARIO, NULL, hp, gas, HUMAN);
				}
				if (numPlayers == 3) {
					initPlayer(pFour, MARIO, NULL, hp, gas, HUMAN);
				}
			}
		} else if (buf == BACKSPACE) {//back space
			if (cursor == 0) {
				if (count > 0) {
					player_name[count - 1] = 0;
					count--;
					AdjustChar(" ", 26 + count, 20);
				}
			}
		}
	} else if (decode_mode == KB_LONG_BINARY_MAKE_CODE) {
		switch (buf) {
		case LEFT_ARROW: //left
			if (cursor == 1) {
				if (playerCharacter == LUIGI) {
					playerCharacter = MARIO;
					AdjustChar("MARIO", 28, 24);
				} else {
					playerCharacter = LUIGI;
					AdjustChar("LUIGI", 28, 24);
				}
			}
			if (cursor == 2) {
				if (playertype == COMPUTER) {
					playertype = HUMAN;
					AdjustChar("HUMAN", 34, 28);
				} else {
					playertype = COMPUTER;
					AdjustChar("COMP ", 34, 28);
				}
			}
			break;
		case RIGHT_ARROW: //right
			if (cursor == 1) {
				if (playerCharacter == LUIGI) {
					playerCharacter = MARIO;
					AdjustChar("MARIO", 28, 24);
				} else {
					playerCharacter = LUIGI;
					AdjustChar("LUIGI", 28, 24);
				}
			}
			if (cursor == 2) {
				if (playertype == COMPUTER) {
					playertype = HUMAN;
					AdjustChar("HUMAN", 34, 28);
				} else {
					playertype = COMPUTER;
					AdjustChar("COMP ", 34, 28);
				}
			}
			break;
		case UP_ARROW: //up
			if (cursor > 0) {
				cursor -= 1;
			}
			if (cursor == 0) {
				AdjustChar(" ", 27, 24);
				AdjustChar("_", 25, 20);
			} else if (cursor == 1) {
				AdjustChar(" ", 33, 28);
				AdjustChar("_", 27, 24);
			}
			break;
		case DOWN_ARROW:
			printf("DOWN");
			if (cursor < 2) {
				cursor += 1;
			}
			if (cursor == 1) {
				AdjustChar("_", 27, 24);
				AdjustChar(" ", 25, 20);
			} else if (cursor == 2) {
				AdjustChar("_", 33, 28);
				AdjustChar(" ", 27, 24);
			}
			break;
		}
	}
}

void AdjustChar(char *string, int x, int y) {
	printString(string, x, y);
}

void clearPlayerName() {
	while (count > 0) {
		player_name[count] = 0;
		count--;
	}
}

void Name_Entered(char *a) {
	player_name[count] = a;
	count++;
	if (count <= 10)
		AdjustChar(player_name, 26, 20);
}

void updateNumPlayers() {
	switch (numPlayers) {
	case 2:
		AdjustChar("_2", 28, 20);
		break;
	case 3:
		AdjustChar("_3", 28, 20);
		break;
	case 4:
		AdjustChar("_4", 28, 20);
		break;
	}
}

