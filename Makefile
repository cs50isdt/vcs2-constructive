all: calc

calc: main.c
	gcc main.c -o calc

.PHONY: test
test: calc
	./main-tests.sh
	@echo "Tests passed!"

.PHONY: clean
clean:
	rm -f calc
