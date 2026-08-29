// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once
#include "keycodes.h"
// clang-format off
#define DE_COMM KC_COMM
#define DE_QUOT S(DE_HASH)
#define DM_MICR A(DE_M)
#define DW_MICR ALGR(DE_M)
#define DE_LABK KC_NUBS
#define DE_0 KC_0
#define DM_PIPE A(DE_7)
#define DW_PIPE ALGR(DE_LABK)
#define DE_X KC_X
#define DE_7 KC_7
#define DE_F KC_F
#define DE_LPRN S(DE_8)
#define DM_EURO A(DE_E)
#define DW_EURO ALGR(DE_E)
#define DE_C KC_C
#define DM_AT A(DE_L)
#define DW_AT ALGR(DE_Q)
#define DE_A KC_A
#define DE_DQUO S(DE_2)
#define DM_LBRC A(DE_5)
#define DW_LBRC ALGR(DE_8)
#define DE_EQL S(DE_0)
#define DE_2 KC_2
#define DE_SLSH S(DE_7)
#define DE_6 KC_6
#define DE_DLR S(DE_4)
#define DE_E KC_E
#define DE_S KC_S
#define DE_I KC_I
#define DE_R KC_R
#define DE_DOT KC_DOT
#define DE_QUES S(DE_SS)
#define DE_V KC_V
#define DE_9 KC_9
#define DE_MINS KC_SLSH
#define DE_CIRC KC_GRV
#define DE_M KC_M
#define DE_G KC_G
#define DE_ODIA KC_SCLN
#define DE_W KC_W
#define DE_8 KC_8
#define DE_N KC_N
#define DE_B KC_B
#define DE_SCLN S(DE_COMM)
#define DE_UNDS S(DE_MINS)
#define DE_1 KC_1
#define DM_RCBR A(DE_9)
#define DW_RCBR ALGR(DE_0)
#define DE_HASH KC_NUHS
#define DE_EXLM S(DE_1)
#define DM_RBRC A(DE_6)
#define DW_RBRC ALGR(DE_9)
#define DE_L KC_L
#define DE_Y KC_Z
#define DE_UDIA KC_LBRC
#define DE_D KC_D
#define DE_4 KC_4
#define DE_ACUT KC_EQL
#define DE_3 KC_3
#define DE_SECT S(DE_3)
#define DE_RPRN S(DE_9)
#define DE_PLUS KC_RBRC
#define DE_AMPR S(DE_6)
#define DM_LCBR A(DE_8)
#define DW_LCBR ALGR(DE_7)
#define DE_COLN S(DE_DOT)
#define DE_Z KC_Y
#define DM_TILD A(DE_N)
#define DW_TILD ALGR(DE_PLUS)
#define DE_J KC_J
#define DE_O KC_O
#define DE_ADIA KC_QUOT
#define DE_Q KC_Q
#define DE_P KC_P
#define DE_RABK S(DE_LABK)
#define DE_K KC_K
#define DE_PERC S(DE_5)
#define DE_GRV S(DE_ACUT)
#define DE_SS KC_MINS
#define DM_BSLS S(A(DE_7))
#define DW_BSLS ALGR(DE_SS)
#define DE_DEG S(DE_CIRC)
#define DE_ASTR S(DE_PLUS)
#define DE_U KC_U
#define DE_T KC_T
#define DE_H KC_H
#define DE_5 KC_5

