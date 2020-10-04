#include <moka/moka.h>
#include <Queue.hpp>

Moka::Context all ("Collecton::DataStructure::Queue", [](Moka::Context& it) {
	it.should("declare Queue", []() {
		Collection::DataStructure::Queue <int> array;
	});
    it.should("be empty", []() {
		Collection::DataStructure::Queue <int> array;
        must_equal (array.empty (), true);
	});
    it.should("push an element with value 1", []() {
		Collection::DataStructure::Queue <int> array;
        array.push (1); 
        must_equal (array.back(), 1);
	});
    it.should("pop the only element", []() {
		Collection::DataStructure::Queue <int> array;
        array.push (1);
        must_equal (array.pop (), 1);
        must_equal (array.empty(), true);
	});
    it.should("pop the first element", []() {
		Collection::DataStructure::Queue <int> array;
        array.push (1);
        array.push (2);
        must_equal (array.pop (), 1);
        must_equal (array.empty(), false);
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