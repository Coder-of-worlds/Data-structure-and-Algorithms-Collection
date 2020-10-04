#include <moka/moka.h>
#include <Stack.hpp>

Moka::Context all ("**Collecton::DataStructure::Stack - testing**", [](Moka::Context& it) {
	it.should("Declare Stack", []() {
		Colleciton::DataStructure::Stack <int> array;
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