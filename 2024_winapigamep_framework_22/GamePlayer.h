#include"Stone.h"
#include "Item.h"

class GamePlayer
{
public:
	int stonecnt = 6;

	vector<Stone> stones;
	vector<Item> items;

	GamePlayer();
	~GamePlayer();
	void Init();
	void ShowPlayerState();

};
