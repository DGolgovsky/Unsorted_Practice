#include <iostream>
#include "src/parser.h"

int main() {
	srt::parser prs;

	/** Сообщение о сбросе */
	uint64_t message = 0x414B2FE73B0153D3;
	prs.serialize(message);
	prs.write("reset.json");

	/** Сообщение об ошибке */
	message = 0xA1630000000230E1;
	prs.serialize(message);
	prs.write("error.json");

	/** Ежемесячное сообщение */
	message = 0x696543210063D39A;
	prs.serialize(message);
	prs.write("monthly.json");

	/** Ежедневное сообщение */
	message = 0x3419240004F04724;
	prs.serialize(message);
	prs.write("daily.json");

	return 0;
}

