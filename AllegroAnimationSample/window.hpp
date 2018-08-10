#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <allegro5/allegro.h>
#include <vector>

#include "sprite_sheet.hpp"

using std::vector;

class window
{
	ALLEGRO_DISPLAY * display;
	ALLEGRO_TIMER * redraw_timer;
	ALLEGRO_EVENT_QUEUE * main_event_queue;

	vector<sprite_sheet *> sprite_sheets;

public:
	const static int ADD_SPRITE_AT_START = -1;
	const static int ADD_SPRITE_AT_END = -2;

	window();
	~window();

	int get_ui_scale();

	void game_loop();

	void paint_loop();

	void add_spritesheet(sprite_sheet** _sprite_sheet, int _position = ADD_SPRITE_AT_END);

	void swap_sprites(sprite_sheet** _a, sprite_sheet** _b);

	vector<sprite_sheet *>& get_spritesheets();
};

#endif // __WINDOW_HPP__
