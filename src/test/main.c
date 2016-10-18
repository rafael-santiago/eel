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

    CUTE_ASSERT(libeel_plugboard(e, 1).l == 0);
    CUTE_ASSERT(libeel_plugboard(e, 1).r == 0);
    CUTE_ASSERT(libeel_plugboard(e, 2).l == 0);
    CUTE_ASSERT(libeel_plugboard(e, 2).r == 0);
    CUTE_ASSERT(libeel_plugboard(e, 3).l == 0);
    CUTE_ASSERT(libeel_plugboard(e, 3).r == 0);
    CUTE_ASSERT(libeel_plugboard(e, 4).l == 0);
    CUTE_ASSERT(libeel_plugboard(e, 4).r == 0);
    CUTE_ASSERT(libeel_plugboard(e, 5).l == 0);
    CUTE_ASSERT(libeel_plugboard(e, 5).r == 0);
    CUTE_ASSERT(libeel_plugboard(e, 6).l == 0);
    CUTE_ASSERT(libeel_plugboard(e, 6).r == 0);

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

    CUTE_ASSERT(libeel_ring(e, l) == 1);
    CUTE_ASSERT(libeel_ring(e, m) == 1);
    CUTE_ASSERT(libeel_ring(e, r) == 1);

    CUTE_ASSERT(libeel_enigma_input(e) == 0);
    CUTE_ASSERT(libeel_enigma_output(e) == 0);

    libeel_del_enigma_ctx(e);
CUTE_TEST_CASE_END

CUTE_TEST_CASE(libeel_init_machine_test)
    libeel_enigma_ctx *e = libeel_new_enigma_ctx();

    e->left_rotor = -1;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = -1;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = -1;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = -1;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'a';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'Z';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'Y';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'D';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 0);

    e->left_rotor = iv;
    e->middle_rotor = i;
    e->right_rotor = ii;
    e->reflector = c;
    libeel_plugboard(e, 1).l = 'x';
    libeel_plugboard(e, 1).r = 'a';
    libeel_plugboard(e, 2).l = 'Z';
    libeel_plugboard(e, 2).r = 'Y';
    libeel_plugboard(e, 3).l = 'B';
    libeel_plugboard(e, 3).r = 'D';
    libeel_plugboard(e, 6).l = 'k';
    libeel_plugboard(e, 6).r = 'F';
    CUTE_ASSERT(libeel_init_machine(e) == 1);
    libeel_del_enigma_ctx(e);
CUTE_TEST_CASE_END

CUTE_TEST_CASE(libeel_type_test)
    libeel_enigma_ctx *e_m3 = libeel_new_enigma_ctx();
    char *expected_outputs = "PXWIAFZZLY", *ep = NULL;
    char *expected_display = "ABCDEFGHIJ", *ed = NULL;
    e_m3->left_rotor = i;
    e_m3->middle_rotor = ii;
    e_m3->right_rotor = iii;
    libeel_rotor_at(e_m3, l) = 'A';
    libeel_rotor_at(e_m3, m) = 'A';
    libeel_rotor_at(e_m3, r) = 'Z';
    e_m3->reflector = b;
    CUTE_ASSERT(libeel_init_machine(e_m3) == 1);
    libeel_enigma_input(e_m3) = 'G';
    for (ep = expected_outputs, ed = expected_display; *ep != 0; ep++, ed++) {
        CUTE_ASSERT(libeel_type(e_m3) == *ep);
        CUTE_ASSERT(libeel_enigma_output(e_m3) == *ep);
        CUTE_ASSERT(libeel_display(e_m3, r) == *ed);
        printf("\t%c->%c [ok]\n", libeel_enigma_input(e_m3), libeel_enigma_output(e_m3));
    }
    libeel_del_enigma_ctx(e_m3);

    e_m3 = libeel_new_enigma_ctx();
    e_m3->left_rotor = i;
    e_m3->middle_rotor = ii;
    e_m3->right_rotor = iii;
    libeel_rotor_at(e_m3, l) = 'A';
    libeel_rotor_at(e_m3, m) = 'A';
    libeel_rotor_at(e_m3, r) = 'Z';
    e_m3->reflector = b;
    CUTE_ASSERT(libeel_init_machine(e_m3) == 1);
    for (ep = expected_outputs, ed = expected_display; *ep != 0; ep++, ed++) {
        libeel_enigma_input(e_m3) = *ep;
        CUTE_ASSERT(libeel_type(e_m3) == 'G');
        CUTE_ASSERT(libeel_enigma_output(e_m3) == 'G');
        CUTE_ASSERT(libeel_display(e_m3, r) == *ed);
        printf("\t%c->%c [ok]\n", libeel_enigma_input(e_m3), libeel_enigma_output(e_m3));
    }
    libeel_del_enigma_ctx(e_m3);
CUTE_TEST_CASE_END

CUTE_TEST_CASE(eel_tests)
    CUTE_RUN_TEST(libeel_enigma_ctx_test);
    CUTE_RUN_TEST(libeel_embedded_dsl_test);
    CUTE_RUN_TEST(libeel_init_machine_test);
    CUTE_RUN_TEST(libeel_type_test);
CUTE_TEST_CASE_END

CUTE_MAIN(eel_tests);
