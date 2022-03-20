#pragma once

#include "YamApp.h"
#include "GmWin.h"

#define YAM_INITIATE(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}