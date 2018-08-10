#include "window.hpp"

const int base_res = 400;

window::window()
{
	const auto game_loop_frequency_ = 14.0;
	const auto game_loop_period_ = 1.0 / game_loop_frequency_ * 2.0;

	display = al_create_display(base_res, base_res);
	redraw_timer = al_create_timer(game_loop_period_);
	main_event_queue = al_create_event_queue();

	al_register_event_source(main_event_queue, al_get_timer_event_source(redraw_timer));
	al_register_event_source(main_event_queue, al_get_display_event_source(display));
}

window::~window()
{
	al_destroy_event_queue(main_event_queue);
	al_destroy_timer(redraw_timer);
	al_destroy_display(display);
}

void window::game_loop()
{
	al_start_timer(redraw_timer);

	while (true)
	{
		ALLEGRO_EVENT ev_;
		al_wait_for_event(main_event_queue, &ev_);

		if (ev_.type == ALLEGRO_EVENT_TIMER)
		{
			paint_loop();
		}
		else if (ev_.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
	}
}

void window::paint_loop()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	const auto ui_scale_ = al_get_display_width(display) / base_res;
	for (auto&& sprite_sheet_ : sprite_sheets)
	{
		sprite_sheet_->animation_routine();
		sprite_sheet_->draw(ui_scale_);
	}

	al_flip_display();
}

void window::add_spritesheet(sprite_sheet** _sprite_sheet, int _position)
{
	switch (_position)
	{
	case ADD_SPRITE_AT_START:
		sprite_sheets.insert(sprite_sheets.begin(), *_sprite_sheet);
		break;
	case ADD_SPRITE_AT_END:
		sprite_sheets.insert(sprite_sheets.end(), *_sprite_sheet);
		break;
	default:
		if (_position > sprite_sheets.size())
		{
			_position = sprite_sheets.size();
		}
		else if (_position < 0)
		{
			sprite_sheets.insert(sprite_sheets.begin(), *_sprite_sheet);
		}

		auto cur_spr_ = sprite_sheets.begin();
		for (unsigned i_ = 0; i_ < _position; i_++)
		{
			++cur_spr_;
		}

		sprite_sheets.insert(cur_spr_, *_sprite_sheet);
	}
}

void window::swap_sprites(sprite_sheet** _a, sprite_sheet** _b)
{
	auto has_a_ = false;
	auto has_b_ = false;

	for (auto&& sprite_sheet_ : sprite_sheets)
	{
		if (sprite_sheet_ == *_a)
		{
			has_a_ = true;
		}
		else if (sprite_sheet_ == *_b)
		{
			has_b_ = true;
		}
	}

	if (!(has_a_ && has_b_))
	{
		throw std::invalid_argument("Either a or b aren't in the sprite sheets.");
	}

	for (auto&& sprite_sheet_ : sprite_sheets)
	{
		if (sprite_sheet_ == *_a)
		{
			sprite_sheet_ = *_b;
		}
		else if (sprite_sheet_ == *_b)
		{
			sprite_sheet_ = *_a;
		}
	}
}

vector<sprite_sheet*>& window::get_spritesheets()
{
	return sprite_sheets;
}
