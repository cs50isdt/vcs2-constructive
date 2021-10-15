all: main

main: main.c
	gcc main.c -o main

.PHONY: test
test: main
	./main-tests.sh
	@echo "Tests passed!"

.PHONY: clean
clean:
	rm -f main
