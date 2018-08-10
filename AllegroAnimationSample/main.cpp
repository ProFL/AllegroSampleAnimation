#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>

#include "window.hpp"
#include "sprite_sheet.hpp"
#include "metool_walk.hpp"

int main(int _argc, char ** _argv)
{
	al_init();
	al_init_image_addon();

	window window_;;
	auto metool_spritesheet_ = new metool_walk();
	window_.add_spritesheet(reinterpret_cast<sprite_sheet **>(&metool_spritesheet_), window::ADD_SPRITE_AT_START);
	window_.game_loop();

	return 0;
}
