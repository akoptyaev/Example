
#include "Help.h"

#include <stdlib.h>

namespace help
{
	float GetRandom(const float min, const float max, const int accuracy)
	{
		int var = rand() % accuracy;
		float k = static_cast<float>(var) / static_cast<float>(accuracy);

		float range = max - min;
		float value = min + range * k;

		return value;
	}
};