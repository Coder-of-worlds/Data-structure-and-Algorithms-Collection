#include <moka/moka.h>
#include <Queue.hpp>

Moka::Context all ("**Collecton::DataStructure::Queue - testing**", [](Moka::Context& it) {
	it.should("Declare Queue", []() {
		Colleciton::DataStructure::Queue <int> array;
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