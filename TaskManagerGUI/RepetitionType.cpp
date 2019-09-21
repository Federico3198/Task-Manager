#include "stdafx.h"

enum RepetitionType
{
	None,
	Dayly,
	Weekly,
	Monthly,
	Yearly,
};

class RepetitionTypeUtils
{
public:
	static RepetitionType ConvertItaToEnum(std::string text)
	{
		if (text == "Nessuna")
		{
			return RepetitionType::None;
		}
		else if (text == "Giornaliero")
		{
			return RepetitionType::Dayly;
		}
		else if (text == "Settimanale")
		{
			return RepetitionType::Weekly;
		}
		else if (text == "Mensile")
		{
			return RepetitionType::Monthly;
		}
		else if (text == "Annuale")
		{
			return RepetitionType::Yearly;
		}
	}
};