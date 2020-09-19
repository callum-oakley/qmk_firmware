#pragma once

#define MASTER_RIGHT

#define LAYOUT_callum(                                                                  \
    KEY00, KEY01, KEY02, KEY03, KEY04,               KEY05, KEY06, KEY07, KEY08, KEY09, \
    KEY10, KEY11, KEY12, KEY13, KEY14,               KEY15, KEY16, KEY17, KEY18, KEY19, \
    KEY20, KEY21, KEY22, KEY23, KEY24,               KEY25, KEY26, KEY27, KEY28, KEY29, \
                         KEY30, KEY31,               KEY32, KEY33                       \
)                                                                                       \
LAYOUT_split_3x5_3(                                                                     \
    KEY00, KEY01, KEY02, KEY03, KEY04,               KEY05, KEY06, KEY07, KEY08, KEY09, \
    KEY10, KEY11, KEY12, KEY13, KEY14,               KEY15, KEY16, KEY17, KEY18, KEY19, \
    KEY20, KEY21, KEY22, KEY23, KEY24,               KEY25, KEY26, KEY27, KEY28, KEY29, \
                  KC_NO, KEY30, KEY31,               KEY32, KEY33, KC_NO                \
)
