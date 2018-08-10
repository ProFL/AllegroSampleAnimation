#ifndef __SPRITE_SHEET_HPP__
#define __SPRITE_SHEET_HPP__

#include <allegro5/bitmap.h>
#include "vectors.hpp"

class sprite_sheet
{
protected:
	ALLEGRO_BITMAP * bitmap;

	int draw_flags;
	uint16_t spr_count;
	Vector2D<int> pos;
	Vector2D<int> src_pos;
	Vector2D<int> spr_dim;

public:
	sprite_sheet(const char* _sprite_path, int _starting_x, int _starting_y,
		int _sprite_width, int _sprite_height, uint16_t _spr_count);

	virtual void draw(int _ui_scale) const;

	virtual void animation_routine() = 0;

	virtual ~sprite_sheet();
};

#endif // __SPRITE_SHEET_HPP__