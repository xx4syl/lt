#include "lantern.h"

#include <stdint.h>

#define nil ((void *)0)

typedef enum {
	VALUE_VOID,
	VALUE_BOOLEAN,
	VALUE_NUMBER,
	VALUE_STRING,
	VALUE_HEAP,
} LtValueType;

typedef struct {
	LtValueType type;
} LtValue;

struct lt_context {
	struct {
		LtValue *start, *top, *end;
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
