#ifndef LANTERN_H
#define LANTERN_H

typedef struct lt_context Lantern;

typedef void *(*LtRealloc)(void *block, size_t size);

Lantern *ltNew(LtRealloc realloc);
Lantern *ltNewDefault(void);
void ltFree(void);

void ltInterpret(Lantern *lt, const char *script);

#endif
