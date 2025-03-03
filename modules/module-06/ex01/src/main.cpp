#include	"../include/Serializer.hpp"

int     main()
{
	Data	data = {42, "Its 42 Data"};
	std::cout << "The address of the Data object is : " << &data << std::endl;
	std::cout << "NewData id : " << data.id << std::endl;
	std::cout << "NewData message : " << data.message << std::endl;

	uintptr_t	dataAdress = Serializer::serialize(&data);
	std::cout << "uintptr_t dataAdress value : " << dataAdress << std::endl;

	Data	*newData;
	newData = Serializer::deserialize(dataAdress);
	std::cout << "The address of the newData object is : " << &data << std::endl;
	std::cout << "NewData id : " << newData->id << std::endl;
	std::cout << "NewData message : " << newData->message << std::endl;

	return (0);
}