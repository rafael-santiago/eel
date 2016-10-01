/*
 *                        Copyright (C) 2006, 2016 by Rafael Santiago
 *
 * This is free software. You can redistribute it and/or modify under
 * the terms of the GNU General Public License version 2.
 *
 */
#include <cutest.h>
#include "../eel.h"
#include <string.h>

CUTE_TEST_CASE(libeel_enigma_ctx_test)
    libeel_enigma_ctx *e = libeel_new_enigma_ctx();
    CUTE_ASSERT(e != NULL);
    libeel_del_enigma_ctx(e);
CUTE_TEST_CASE_END

CUTE_TEST_CASE(libeel_embedded_dsl_test)
    libeel_enigma_ctx *e = libeel_new_enigma_ctx();
    libeel_rotor_wiring_t null_rotor;
    memset(null_rotor, 0, sizeof(libeel_rotor_wiring_t));

    CUTE_ASSERT(e != NULL);

    CUTE_ASSERT(e->left_rotor == 0);
    CUTE_ASSERT(e->middle_rotor == 0);
    CUTE_ASSERT(e->right_rotor == 0);

    CUTE_ASSERT(e->reflector == 0);

    CUTE_ASSERT(memcmp(libeel_keyboard(e), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);

    CUTE_ASSERT(memcmp(libeel_rotor(e, l), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);
    CUTE_ASSERT(memcmp(libeel_rotor(e, m), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);
    CUTE_ASSERT(memcmp(libeel_rotor(e, r), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);

    CUTE_ASSERT(memcmp(libeel_rotor_inv(e, l), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);
    CUTE_ASSERT(memcmp(libeel_rotor_inv(e, m), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);
    CUTE_ASSERT(memcmp(libeel_rotor_inv(e, r), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);

    CUTE_ASSERT(libeel_notch(e, m) == 0);
    CUTE_ASSERT(libeel_notch(e, r) == 0);

    CUTE_ASSERT(libeel_display(e, l) == 0);
    CUTE_ASSERT(libeel_display(e, m) == 0);
    CUTE_ASSERT(libeel_display(e, r) == 0);

    CUTE_ASSERT(memcmp(libeel_reflector(e), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);

    CUTE_ASSERT(memcmp(libeel_rotor_offset(e, l), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);
    CUTE_ASSERT(memcmp(libeel_rotor_offset(e, m), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);
    CUTE_ASSERT(memcmp(libeel_rotor_offset(e, r), null_rotor, sizeof(libeel_rotor_wiring_t)) == 0);

    CUTE_ASSERT(libeel_rotor_at(e, l) == 0);
    CUTE_ASSERT(libeel_rotor_at(e, m) == 0);
    CUTE_ASSERT(libeel_rotor_at(e, r) == 0);

    CUTE_ASSERT(libeel_ring(e, l) == 0);
    CUTE_ASSERT(libeel_ring(e, m) == 0);
    CUTE_ASSERT(libeel_ring(e, r) == 0);

    CUTE_ASSERT(libeel_enigma_input(e) == 0);
    CUTE_ASSERT(libeel_enigma_output(e) == 0);

    libeel_del_enigma_ctx(e);
CUTE_TEST_CASE_END

CUTE_TEST_CASE(eel_tests)
    CUTE_RUN_TEST(libeel_enigma_ctx_test);
    CUTE_RUN_TEST(libeel_embedded_dsl_test);
CUTE_TEST_CASE_END

CUTE_MAIN(eel_tests);
