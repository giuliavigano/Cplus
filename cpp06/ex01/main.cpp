#include "Serializer.hpp"


int	main() {
	Data*		original_value;
	Data*		deserialized;
	uintptr_t	serialized;
	Data	data(42, "test", 3.14);
	
	original_value = &data;
	serialized = Serializer::serialize(original_value);
	deserialized = Serializer::deserialize(serialized);

	if (deserialized == original_value) {
		std::cout << "Test Passed: pointers match!" << std::endl;
		std::cout << "Original: " << original_value << std::endl;
		std::cout << "Serialized: " << serialized << std::endl;
		std::cout << "Deserialized: " << deserialized << std::endl;
	} else 
		std::cout << "Test Failed!" << std::endl;
	return 0;
}