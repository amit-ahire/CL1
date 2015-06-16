#include<check.h>
#include"bin_search.h"

START_TEST(check_search)
{
    int test_array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 10;

    ck_assert_int_eq(binary_search(test_array, 0, size-1, 4), 5);
}
END_TEST

Suite * binary_search_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Binary Search");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, check_search);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = binary_search_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 1 : -1;
}
