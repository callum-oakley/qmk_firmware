#ifndef PROCESS_LEADER_H
#define PROCESS_LEADER_H

#include "quantum.h"

bool process_leader(uint16_t keycode, keyrecord_t *record);

void leader_start(void);
void leader_end(void);

#ifndef LEADER_TIMEOUT
  #define LEADER_TIMEOUT 1000
#endif

#define REGISTER_ONE_KEY(key) {}
#define REGISTER_TWO_KEYS(key1, key2) if (leader_sequence[0] == (key1) && leader_sequence[1] == 0 && leader_sequence[2] == 0 && leader_sequence[3] == 0 && leader_sequence[4] == 0) {partial_match = true;}
#define REGISTER_THREE_KEYS(key1, key2, key3) if (leader_sequence[0] == (key1) && (leader_sequence[1] == (key2) || leader_sequence[1] == 0) && leader_sequence[2] == 0 && leader_sequence[3] == 0 && leader_sequence[4] == 0){partial_match = true;}
#define REGISTER_FOUR_KEYS(key1, key2, key3, key4) if (leader_sequence[0] == (key1) && (leader_sequence[1] == (key2) || leader_sequence[1] == 0) && (leader_sequence[2] == (key3) || leader_sequence[2] == 0) && leader_sequence[3] == 0 && leader_sequence[4] == 0){partial_match = true;}
#define REGISTER_FIVE_KEYS(key1, key2, key3, key4, key5) if (leader_sequence[0] == (key1) && (leader_sequence[1] == (key2) || leader_sequence[1] == 0) && (leader_sequence[2] == (key3) || leader_sequence[2] == 0) && (leader_sequence[3] == (key4) || leader_sequence[3] == 0) && leader_sequence[4] == 0){partial_match = true;}

#define DESCRIBE_ONE_KEY(key) if (leader_sequence[0] == (key) && leader_sequence[1] == 0 && leader_sequence[2] == 0 && leader_sequence[3] == 0 && leader_sequence[4] == 0)
#define DESCRIBE_TWO_KEYS(key1, key2) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == 0 && leader_sequence[3] == 0 && leader_sequence[4] == 0)
#define DESCRIBE_THREE_KEYS(key1, key2, key3) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == (key3) && leader_sequence[3] == 0 && leader_sequence[4] == 0)
#define DESCRIBE_FOUR_KEYS(key1, key2, key3, key4) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == (key3) && leader_sequence[3] == (key4) && leader_sequence[4] == 0)
#define DESCRIBE_FIVE_KEYS(key1, key2, key3, key4, key5) if (leader_sequence[0] == (key1) && leader_sequence[1] == (key2) && leader_sequence[2] == (key3) && leader_sequence[3] == (key4) && leader_sequence[4] == (key5))

#define LEADER_EXTERNS() extern bool leading; extern uint16_t leader_time; extern uint16_t leader_sequence[5]; extern uint8_t leader_sequence_size; extern bool partial_match
#define LEADER_DICTIONARY() if (leading)
#define REGISTER_SEQUENCES() if (timer_elapsed(leader_time) <= LEADER_TIMEOUT)
#define DESCRIBE_SEQUENCE_BEHAVIOUR() if (!partial_match)
#define STOP_LEADING() leading = false; leader_end()

#endif
