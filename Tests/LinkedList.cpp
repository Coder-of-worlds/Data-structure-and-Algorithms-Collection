#include <moka/moka.h>
#include <LinkedList.hpp>

Moka::Context all ("**Collecton::DataStructure::LinkedList - testing**", [](Moka::Context& it) {
	it.should("Declare LinkedList", []() {
		Collection::DataStructure::LinkedList <int> array;
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