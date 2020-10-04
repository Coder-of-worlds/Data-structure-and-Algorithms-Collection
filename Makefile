all: DynamicArray.out LinkedList.out Queue.out Stack.out
%.out: Tests/%.cpp
	${CXX} -std=c++11 -Wall -Wextra -Werror -I./Collection -I./UTest -o "bin/$@.exe" "$<"

test: all
	./bin/DynamicArray.out.exe
	./bin/LinkedList.out.exe
	./bin/Queue.out.exe
	./bin/Stack.out.exe

clean:
	rm -f ./Tests/DynamicArray.out ./Tests/LinkedList.out ./Tests/Queue.out ./Tests/Stack.out
