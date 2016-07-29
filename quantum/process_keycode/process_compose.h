#ifndef PROCESS_COMPOSE_H
#define PROCESS_COMPOSE_H

#include "quantum.h"

bool process_compose(uint16_t keycode, keyrecord_t *record);

void compose_start(void);
void compose_end(void);

#ifndef COMPOSE_TIMEOUT
  #define COMPOSE_TIMEOUT 1000
#endif
#define SEQ_ONE_KEY(key) if (compose_sequence[0] == (key) && compose_sequence[1] == 0 && compose_sequence[2] == 0 && compose_sequence[3] == 0 && compose_sequence[4] == 0)
#define SEQ_TWO_KEYS(key1, key2) if (compose_sequence[0] == (key1) && compose_sequence[1] == (key2) && compose_sequence[2] == 0 && compose_sequence[3] == 0 && compose_sequence[4] == 0)
#define SEQ_THREE_KEYS(key1, key2, key3) if (compose_sequence[0] == (key1) && compose_sequence[1] == (key2) && compose_sequence[2] == (key3) && compose_sequence[3] == 0 && compose_sequence[4] == 0)
#define SEQ_FOUR_KEYS(key1, key2, key3, key4) if (compose_sequence[0] == (key1) && compose_sequence[1] == (key2) && compose_sequence[2] == (key3) && compose_sequence[3] == (key4) && compose_sequence[4] == 0)
#define SEQ_FIVE_KEYS(key1, key2, key3, key4, key5) if (compose_sequence[0] == (key1) && compose_sequence[1] == (key2) && compose_sequence[2] == (key3) && compose_sequence[3] == (key4) && compose_sequence[4] == (key5))

#define COMPOSE_EXTERNS() extern bool composing; extern uint16_t compose_time; extern uint16_t compose_sequence[5]; extern uint8_t compose_sequence_size
#define COMPOSE_DICTIONARY() if (composing)
#define STOP_COMPOSING() composing = false; compose_end()

#endif
