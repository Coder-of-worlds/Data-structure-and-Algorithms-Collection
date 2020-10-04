#include <moka/moka.h>
#include <LinkedList.hpp>

Moka::Context all ("Collecton::DataStructure::LinkedList", [](Moka::Context& it) {
	it.should("Declare LinkedList", []() {
		Collection::DataStructure::LinkedList <int> array;
	});
	it.should("be with size 0", []() {
		Collection::DataStructure::LinkedList <int> array;
		must_equal (array.size (), 0ull);
	});
	it.should("push back a number", []() {
		Collection::DataStructure::LinkedList <int> array;
		array.push_back (1);
		must_equal (array.size (), 1ull);
	});
	it.should("push front a number", []() {
		Collection::DataStructure::LinkedList <int> array;
		array.push_front (1);
		must_equal (array.size (), 1ull);
	});
	it.should("push 2 numbers", []() {
		Collection::DataStructure::LinkedList <int> array;
		Collection::DataStructure::LinkedList <int>::Iterator item;
		array.push_front (1);
		item = array.push_front (2);
		must_equal (item(), 2);
		must_equal (item.Next()(), 1);
	});
	it.should("pop 2 numbers", []() {
		Collection::DataStructure::LinkedList <int> array;
		Collection::DataStructure::LinkedList <int>::Iterator item;
		array.push_front (1);
		array.push_front (2);
		item = array.pop_front ();
		must_equal (item(), 1);
		item = array.pop_front ();
		must_equal (item, array.None());
	});
	it.should("inster in the middle", []() {
		Collection::DataStructure::LinkedList <int> array;
		Collection::DataStructure::LinkedList <int>::Iterator item;
		array.push_front (1);
		item = array.push_front (2);
		item.insertAfter (3);
		must_equal (item(), 2);
		must_equal (item.Next()(), 3);
		must_equal (item.Next().Next()(), 1);
	});
});

int main ()
{
	std::cout << "===============================  Testing  ===============================\n";

	Moka::Report report;
	all.test(report);
	report.print();

	return 0;
}