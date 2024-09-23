CC=clang
CFLAGS=-Wall -Werror -g

PROGRAMS=test_vecteur test_vecteur_memfail \
         test_matrice test_matrice_memfail \
         test_matrice_lineaire test_matrice_lineaire_memfail \
         test_vecteur_dynamique test_vecteur_dynamique_memfail \
         test_memcpy test_memmove test_is_little_endian test_reverse_endianess \
         test_matrice_dynamique test_matrice_dynamique_memfail


.PHONY: all programs test clean

all:
	@echo "Indiquez une cible (ex. 'make test' ou 'make vecteur_testbase par exemple')"

programs: $(PROGRAMS) $(OTHER_PROGRAMS)

test: $(PROGRAMS)
	@echo;echo "*** TESTS ***";echo;\
	chmod u+x ./teste_programme
	for file in $^;\
		do echo ;\
		./teste_programme $$file 2>/dev/null || break;\
	done

clean:
	-rm -f *.o $(PROGRAMS) $(OTHER_PROGRAMS) *.output

test_vec%.o: test_vecteur.c vec%.h my_memory.h utils_vecteur.h utils_tests.h
	$(CC) $(CFLAGS) -include my_memory.h -include vec$*.h -c -o $@ $<

utils_vec%.o: utils_vecteur.c vec%.h my_memory.h utils_vecteur.h
	$(CC) $(CFLAGS) -include my_memory.h -include vec$*.h -c -o $@ $<

test_mat%.o: test_matrice.c mat%.h my_memory.h utils_tests.h
	$(CC) $(CFLAGS) -include my_memory.h -include mat$*.h -c -o $@ $<

test_memcpy.o test_memmove.o: test_mem%.o: test_memops.c memory_operations.h vecteur.h utils_vecteur.h my_memory.h utils_tests.h
	[ "$*" = "cpy" ] && DEFOP="-DMEMCPY"; $(CC) $(CFLAGS) -include my_memory.h $$DEFOP -c -o $@ $<

my_memory.o: my_memory.c
	$(CC) $(CFLAGS) -c $<

my_memory_fail_%.o: my_memory.c
	$(CC) $(CFLAGS) -DMALLOC_FAIL_AFTER=$* -c -o $@ $<

%.o: %.c my_memory.h
	$(CC) $(CFLAGS) -include my_memory.h -c $<

%_memfail:
	$(CC) -o $@ $^

# dependences
test_vecteur: test_vecteur.o vecteur.o my_memory.o utils_vecteur.o utils_tests.o
test_vecteur_memfail: test_vecteur.o vecteur.o my_memory_fail_2.o utils_vecteur.o utils_tests.o

test_matrice: test_matrice.o matrice.o my_memory.o utils_tests.o
test_matrice_memfail: test_matrice.o matrice.o my_memory_fail_7.o utils_tests.o

test_matrice_lineaire: test_matrice_lineaire.o matrice_lineaire.o my_memory.o utils_tests.o
test_matrice_lineaire_memfail: test_matrice_lineaire.o matrice_lineaire.o my_memory_fail_2.o utils_tests.o

test_vecteur_dynamique: test_vecteur_dynamique.o vecteur_dynamique.o my_memory.o utils_vecteur_dynamique.o utils_tests.o
test_vecteur_dynamique_memfail: test_vecteur_dynamique.o vecteur_dynamique.o my_memory_fail_2.o utils_vecteur_dynamique.o utils_tests.o

test_memcpy: test_memcpy.o memory_operations.o vecteur.o utils_vecteur.o my_memory_fail_2.o utils_tests.o
test_memmove: test_memmove.o memory_operations.o vecteur.o utils_vecteur.o my_memory_fail_2.o utils_tests.o
test_is_little_endian: memory_operations.o my_memory_fail_2.o utils_tests.o
test_reverse_endianess: memory_operations.o my_memory_fail_2.o utils_tests.o

test_matrice_dynamique: test_matrice_dynamique.o matrice_dynamique.o my_memory.o utils_tests.o vecteur_dynamique.o
test_matrice_dynamique_memfail: test_matrice_dynamique.o matrice_dynamique.o my_memory_fail_6.o utils_tests.o vecteur_dynamique.o

vecteur.o: vecteur.h
vecteur_dynamique.o: vecteur_dynamique.h

matrice.o: matrice.h
matrice_lineaire.o: matrice_lineaire.h
matrice_dynamique.o: matrice_dynamique.h

memory_testcpy.o: vecteur.h memory_operations.h utils_vecteur.h
memory_testmove.o: vecteur.h memory_operations.h utils_vecteur.h
memory_testendianess.o: memory_operations.h

memory_operations.o: memory_operations.h

utils_tests.o: utils_tests.h
