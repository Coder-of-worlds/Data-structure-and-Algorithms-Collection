#include <moka/moka.h>
#include <DynamicArray.hpp>

Moka::Context all ("**Collecton::DataStructure::DynamicArray - testing**", [](Moka::Context& it) {
	it.should("Declare DynamicArray", []() {
		Colleciton::DataStructure::DynamicArray <int> array;
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