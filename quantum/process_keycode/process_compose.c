#include "process_compose.h"

__attribute__ ((weak))
void compose_start(void) {}

__attribute__ ((weak))
void compose_end(void) {}

// Compose key stuff
bool composing = false;
uint16_t compose_time = 0;

uint16_t compose_sequence[5] = {0, 0, 0, 0, 0};
uint8_t compose_sequence_size = 0;

bool process_compose(uint16_t keycode, keyrecord_t *record) {
    // Compose keye set-up
    if (record->event.pressed) {
        if (!composing && keycode == KC_COMP) {
            compose_start();
            composing = true;
            compose_time = timer_read();
            compose_sequence_size = 0;
            compose_sequence[0] = 0;
            compose_sequence[1] = 0;
            compose_sequence[2] = 0;
            compose_sequence[3] = 0;
            compose_sequence[4] = 0;
            return false;
        }
        if (composing) {
            compose_sequence[compose_sequence_size] = keycode;
            compose_sequence_size++;
            return false;
        }
    }
    return true;
}
