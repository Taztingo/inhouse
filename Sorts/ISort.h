#ifndef ISORT_H_
	#define ISORT_H_

	namespace inhouse
	{
		class ISort
		{
			public:
				virtual ~ISort();
				virtual bool compare(ISort* item) = 0;	
		};
	}

#endif
