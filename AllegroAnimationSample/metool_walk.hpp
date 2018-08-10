#pragma once
#include "sprite_sheet.hpp"
class metool_walk : public sprite_sheet
{
public:
	metool_walk();
	~metool_walk();

	void draw(int _ui_scale) const override;
	void animation_routine() override;
};

