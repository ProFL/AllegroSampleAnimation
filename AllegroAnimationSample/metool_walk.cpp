#include "metool_walk.hpp"
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include "window.hpp"

metool_walk::metool_walk()
	: sprite_sheet("WalkForward.bmp", 0, 0, 15, 16, 5)
{
	al_convert_mask_to_alpha(bitmap, al_map_rgb(0xFF, 0, 0xFF));
}

metool_walk::~metool_walk() = default;

void metool_walk::draw(const int _ui_scale) const
{
	const auto scale_factor_ = 3;
	al_draw_tinted_scaled_rotated_bitmap_region(
		bitmap,
		src_pos.x, src_pos.y,
		spr_dim.x, spr_dim.y,
		al_map_rgba(0xFF, 0xFF, 0xFF, 1),
		0, 0,
		0, 0,
		3 * _ui_scale,  3 *_ui_scale,
		0, 0
	);
}

void metool_walk::animation_routine()
{
	src_pos.x += spr_dim.x;

	if (src_pos.x >= spr_dim.x * spr_count)
	{
		src_pos.x = 0;
	}
}
