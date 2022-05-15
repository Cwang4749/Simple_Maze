#pragma once

#include "YamApp.h"
#include "GmWin.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "KeyCodes.h"
#include "Events.h"

#define YAM_INITIATE(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}