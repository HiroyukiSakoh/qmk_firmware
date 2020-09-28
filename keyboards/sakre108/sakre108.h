/* Copyright 2020 Hiroyuki Sakoh
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define ___ KC_NO
#define E1A KC_NO
#define E1B KC_NO
#define E2A KC_NO
#define E2B KC_NO
#define E3A KC_NO
#define E3B KC_NO
#define LAYOUT( \
L00,   L01,L02,L03, L04,L05, E1S,     R00,R01,R02, R03,R04,R05, R06,  R07,R08,                       \
L10,L11,L12,L13,L14,L15,L16,        R10,R11,R12,R13,R14,R15,R16,R17,  R18,R19,R1A,  R1B,R1C,R1D,R1E, \
L20,  L21,L22,L23,L24,L25, E2S,   R20,R21,R22,R23,R24,R25,R26,  R27,  R28,R29,R2A,  R2B,R2C,R2D,R2E, \
L30,   L31,L32,L33,L34,L35,        R30,R31,R32,R33,R34,R35,R36,                     R37,R38,R39,     \
L40,    L41,L42,L43,L44,L45,        R40,R41,R42,R43,R44,R45,R46,          R47,      R48,R49,R4A,R4B, \
L50, L51,L52, L53,L54,     E3S,     R50,    R51, R52, R53, R54,R55,   R56,R57,R58,  R59    ,R5A      \
) { \
    /* B2,  B6,  B5,  B4,  E6,  D7,  C6,  D4, D3 */ \
    { L00, L01, L02, L03, L04, L05, E1A, E1B,E1S }, /* Left-Row0 B3 */          \
    { L10, L11, L12, L13, L14, L15, L16, ___,___ }, /* Left-Row1 B1 */          \
    { L20, L21, L22, L23, L24, L25, E2A, E2B,E2S }, /* Left-Row2 F7 */          \
    { L30, L31, L32, L33, L34, L35, ___, ___,___ }, /* Left-Row3 F6 */          \
    { L40, L41, L42, L43, L44, L45, ___, ___,___ }, /* Left-Row4 F5 */          \
    { L50, L51, L52, L53, L54, ___, E3A, E3B,E3S }, /* Left-Row5 F4 */          \
    { ___, ___, ___, ___, ___, ___, ___, ___,___ }, /* Left-Row6 D1 unused */   \
    { ___, ___, ___, ___, ___, ___, ___, ___,___ }, /* Left-Row7 D2 unused */   \
    /* F4,  F5,  F6,  F7,  B1,  B3,  B2,  B6, B5 */ \
    { R00, R01, R02, R03, R04, R05, R06, R07,R08 }, /* Right-Row0 D3 */         \
    { R10, R11, R12, R13, R14, R15, R16, R17,R1A }, /* Right-Row1 D2 */         \
    { R20, R21, R22, R23, R24, R25, R26, R18,R19 }, /* Right-Row2 D1 */         \
    { R30, R31, R32, R33, R34, R35, R36, R27,R28 }, /* Right-Row3 D4 */         \
    { R40, R41, R42, R43, R44, R45, R46, R29,R2A }, /* Right-Row4 C6 */         \
    { R50, R51, R52, R53, R54, R55, R56, R57,R58 }, /* Right-Row5 D7 */         \
    { R5A, R4B, R4A, R39, R2D, R2E, R1D, R1E,R1C }, /* Right-Row6 E6 */         \
    { R59, R49, R48, R38, R37, R2C, R2B, R1B,R47 }  /* Right-Row7 B4 */         \
}
