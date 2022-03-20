#pragma once

#include "YamApp.h"

#define YAM_INITIATE(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}