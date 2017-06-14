#include <stdint.h>
#include <string>

enum { SAND, FIRST, FIRSTPERFIX, SECOND, SECONDPERFIX, HUNDRED, BIG, BIGPERFIX };
const char* const numbers[][10] = {
	{ " و" },
	{ "واحد", "إثنان", "ثلاثة", "أربعة", "خمسه", "سته", "سبعه", "ثمانيه", "تسعه", "عشرة" },
	{ "واحد", "اثنا", "ثلاث", "أربع", "خمس", "ست", "سبع", "ثمان", "تسع" },
	{ "عشر", "عشرين", "ثلاثين", "أربعين", "خمسين", "ستين", "سبعين", "ثمانين", "تسعين" },
	{ " عشر", "عشرون", "ثلاثون", "أربعون", "خمسون", "ستون", "سبعون", "ثمانون", "تسعون" },
	{ "مائة", "مئتا" },
	{ "", " الف", " مليون", " مليار" },
	{ "", " آلاف", " ملايين", " ملايير" }
};

std::string numberToLetter(const unsigned int number)
{

	std::string sFinal;
	for (int i = 3; i >= 0; i--){
		int16_t nPrice;
		if (i == 3)
			nPrice = number / 1000000000;
		else if (i == 2)
			nPrice = (number - number / 1000000000 * 1000000000) / 1000000;
		else if (i == 1)
			nPrice = (number - number / 1000000 * 1000000) / 1000;
		else
			nPrice = (number - number / 1000 * 1000);

		if (nPrice <= 0)
			continue;

		if (nPrice >= 100){
			const int8_t temp = nPrice / 100;
			if (!sFinal.empty())
				sFinal += numbers[SAND][SAND];
			if (temp > 2){
				sFinal += numbers[FIRSTPERFIX][temp - 1];
				sFinal += +numbers[HUNDRED][0];
			}
			else
				sFinal += numbers[HUNDRED][temp - 1];
		}

		const int8_t temp = nPrice / 10;
		if (nPrice % 10 > 0){
			if (!sFinal.empty())
				sFinal += numbers[SAND][SAND];
			if (temp % 10 > 0)
				sFinal += numbers[FIRSTPERFIX][(nPrice % 10) - 1];
			else
				sFinal += numbers[FIRST][(nPrice % 10) - 1];

		}
		if (temp % 10 > 0){
			if (!sFinal.empty()){
				if (temp % 10 > 1)
					sFinal += numbers[SAND][SAND];
				sFinal += numbers[SECONDPERFIX][(temp % 10) - 1];
			}
			else
				sFinal += numbers[SECOND][(temp % 10) - 1];
		}

		if (nPrice > 10)
			sFinal += numbers[BIG][i];
		else
			sFinal += numbers[BIGPERFIX][i];
	}
	return sFinal;
}
