#include "lantern.h"

#include <stdint.h>

#define nil ((void *)0)

typedef uint64_t LtValue;

struct lt_context {
	struct {
		LtValue *array;
		size_t count, size;
	} stack;

	LtRealloc realloc;
};

Lantern *
ltNew(LtRealloc realloc)
{
	Lantern *lt = realloc(nil, sizeof(Lantern));

	if (lt == nil) return nil;

	lt->realloc = realloc;

	return lt;
}
