#include "showordered.h"

showordered::showordered(std::unordered_map<std::string, std::list<ArchiveObject*>*>* a):archive(a)
{
}

showordered::~showordered()
{
}

void showordered::execute(std::string param)
{
	if (archive->count(param))
	{
		std::cout << param << std::endl;
		auto listarchive = (*archive)[param];
		// sort takes lambda function
		listarchive->sort([](const ArchiveObject * a, const ArchiveObject * b) {
			if (a->month < b->month) return 1;
			else if (a->month > b->month) return 0;

			if (a->days < b->days) return 1;
			else if (a->days > b->days) return 0;

			return 0; });// doesnt  matter which goes first if they are on the same day

		for (auto it = listarchive->begin(); it != listarchive->end(); it++)
		{
			(*it)->info();
		}
	}
}
