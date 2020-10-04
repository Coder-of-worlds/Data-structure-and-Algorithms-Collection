all: DynamicArray.out LinkedList.out Queue.out Stack.out
%.out: Tests/%.cpp
	${CXX} -std=c++11 -Wall -Wextra -Werror -I./Collection -I./UTest -o "$@" "$<"

test: all
	./Tests/DynamicArray.out
	./Tests/LinkedList.out
	./Tests/Queue.out
	./Tests/Stack.out

clean:
	rm -f ./Tests/DynamicArray.out ./Tests/LinkedList.out ./Tests/Queue.out ./Tests/Stack.out
