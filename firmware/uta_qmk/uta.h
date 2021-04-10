#pragma once

#include "quantum.h"

#define LAYOUT_horizontal( \
	K00, K01, K02 \
) { \
	{ K00, K01, K02 }  \
}

#define LAYOUT LAYOUT_horizontal
