hello-world: hello-world.o hello-world.ii
	g++ -o hello-world hello-world.o
	@echo "Preprocessed hello-world.ii has $(shell wc -l hello-world.ii | cut -f1 -d ' ') lines"

hello-world.o: hello-world.cpp
	g++ -c hello-world.cpp

hello-world.ii: hello-world.cpp
	g++ -E hello-world.cpp -o hello-world.ii

clean:
	rm -r *.o *.ii hello-world

