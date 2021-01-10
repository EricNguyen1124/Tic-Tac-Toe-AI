#ifndef BOT_H
#define BOT_H

#include "player.h"

class bot : public player
{
public:
	bot();
	bot(int num);
	int minimax(grid darray, bool maximizing);
};
#endif