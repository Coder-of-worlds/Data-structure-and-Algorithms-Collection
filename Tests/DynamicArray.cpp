#include <moka/moka.h>
#include <DynamicArray.hpp>

Moka::Context all ("Collecton::DataStructure::DynamicArray", [](Moka::Context& it) {
	it.should("declare DynamicArray", []() {
		Collection::DataStructure::DynamicArray <int> array;
	});
    it.should("have 0 elements", []() {
		Collection::DataStructure::DynamicArray <int> array;
        must_equal (array.size (), 0ull);
	});
    it.should("have capacity 1", []() {
		Collection::DataStructure::DynamicArray <int> array;
        must_equal (array.capacity (), 1ull);
	});
    it.should("push an element with value 1", []() {
		Collection::DataStructure::DynamicArray <int> array;
        array.push (1); 
        must_equal (array.capacity (), 1ull);
	});
    it.should("set the first element to 2", []() {
		Collection::DataStructure::DynamicArray <int> array;
        array.push (1);
        array.get (0) = 2; 
        must_equal (array.get (0), 2);
	});
    it.should("pop the first element", []() {
		Collection::DataStructure::DynamicArray <int> array;
        array.push (1);
        must_equal (array.pop (), 1);
        must_equal (array.size(), 0ull);
	});
    it.should("resize on second element", []() {
		Collection::DataStructure::DynamicArray <int> array;
        array.push (1);
        array.push (1);
        must_equal (array.size (), 2ull);
        must_equal (array.capacity(), 2ull);
	});
    it.should("resize on third element", []() {
		Collection::DataStructure::DynamicArray <int> array;
        array.push (1);
        array.push (1);
        array.push (1);
        must_equal (array.size (), 3ull);
        must_equal (array.capacity(), 4ull);
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