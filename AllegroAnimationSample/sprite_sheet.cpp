#include <allegro5/allegro.h>
#include <string>

#include "sprite_sheet.hpp"

using std::string;

sprite_sheet::sprite_sheet(const char* _sprite_path, const int _starting_x, const int _starting_y,
	const int _sprite_width, const int _sprite_height, const uint16_t _spr_count)
	: draw_flags(0), spr_count(_spr_count)
{
	const auto bmp_path_ = string(al_path_cstr(al_get_standard_path(ALLEGRO_RESOURCES_PATH), ALLEGRO_NATIVE_PATH_SEP)) + _sprite_path;
	const auto bmp_path_cstr_ = bmp_path_.c_str();
	bitmap = al_load_bitmap(bmp_path_cstr_);
	pos.x = 0;
	pos.y = 0;
	src_pos.x = _starting_x;
	src_pos.y = _starting_y;
	spr_dim.x = _sprite_width;
	spr_dim.y = _sprite_height;
}

void sprite_sheet::draw(const int _ui_scale) const
{
	const auto bmp_width_ = al_get_bitmap_width(bitmap);
	const auto bmp_height_ = al_get_bitmap_height(bitmap);
	al_draw_scaled_bitmap(bitmap, src_pos.x, src_pos.y, spr_dim.x, spr_dim.y, pos.x, pos.y, _ui_scale * bmp_width_, _ui_scale * bmp_height_, 0);
}

sprite_sheet::~sprite_sheet()
{
	al_destroy_bitmap(bitmap);
}
