#pragma once
enum class LAYER
{
	DEFAULT,
	//UI,
	BACKGROUND,
	OBSTACLE,
	PLAYER,
	PROJECTILE,
	ENEMY,
	STATIC,
	UI,
	END
};

enum class ButtonState
{
	Default,
	Hover,
	Click,
	Press,
	END
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};


enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};
