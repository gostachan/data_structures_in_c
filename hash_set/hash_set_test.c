#include "hash_set.h"
#include <assert.h>
#include <complex.h>
#include <stdbool.h>
#include <stdio.h>

void	test_init(void)
{
	HashSet	set;

	init_hs(&set);
	printf("test_init passed\n");
	free_hs(&set);
}

void	test_add_contains(void)
{
	HashSet	set;
	NodeHS *target;
	int size = 5;
	int index = 0;
	int array[] = {20, 30, 10, 0, 40};
	int sorted_array[] = {0, 10, 20, 30, 40};

	printf("tabel_size = %d\n", TABLE_SIZE);

	init_hs(&set);
	for (int i = 0; i < size; ++i) {
		assert(add_hs(&set, array[i]) == true);
	}
	for (int i = 0; i < size; ++i) {
		assert(contains_hs(&set, sorted_array[i]) == true);
	}
	printf("test_add_contains passed\n");
	free_hs(&set);
}

void	test_remove(void)
{
	HashSet	set;

	init_hs(&set);
	add_hs(&set, 30);
	assert(contains_hs(&set, 30) == true);
	remove_hs(&set, 30);
	assert(contains_hs(&set, 30) == false);
	printf("test_remove passed\n");
	free_hs(&set);
}

void	test_free(void)
{
	HashSet	set;

	init_hs(&set);
	add_hs(&set, 40);
	add_hs(&set, 50);
	add_hs(&set, 60);
	free_hs(&set);
	printf("test_free passed\n");
}

int main() {
    test_init();
    test_add_contains();
    test_remove();
    test_free();
    printf("All tests passed!\n");
    return (0);
}
