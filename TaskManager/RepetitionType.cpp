#include "pch.h"
#include <string>

enum RepetitionType
{
	None,
	Dayly,
	Weekly,
	Monthly,
	Yearly,
};

class BoolUtils //TODO da spostare in un suo file
{
public:
	static std::string ConvertBoolToYesNoIta(bool value)
	{
		if (value)
		{
			return "Si";
		}
		else
		{
			return "No";
		}
	}
};

class RepetitionTypeUtils
{
public:

	static std::string ConvertEnumToIta(RepetitionType repetition)
	{
		switch (repetition)
		{
			case RepetitionType::None:
				return "Nessuna";

			case RepetitionType::Dayly:
				return "Giornaliero";

			case RepetitionType::Weekly:
				return "Settimanale";

			case RepetitionType::Monthly:
				return "Mensile";

			case RepetitionType::Yearly:
				return "Annuale";

			default:
				return "Undefined";
				break;
		}
	}

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
		else
		{
			return RepetitionType::None;
		}
	}
};