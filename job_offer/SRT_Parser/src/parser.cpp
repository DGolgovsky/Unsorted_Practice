#include "parser.h"

srt::parser::parser(const std::string &&file)
	: out_file(file)
{ }

void srt::parser::write(std::string const &ofile)
{
	if (ofile.empty()) {
		std::cerr << "Wrong or empty filename\n";
		return;
	}
	// Write JSON to output_file
	std::ofstream ofs(ofile);
	ofs << std::setw(4) << std::hex << o_json << std::endl;
	ofs.close();
	o_json.clear();
}

void srt::parser::write()
{
	this->write(out_file);
}

void srt::parser::serialize(uint64_t &message)
{
	uint64_t type = message >> 56;
	to_json(std::make_pair("sign", type));
	switch (type) {
		case 0x41: // Reset
			parse_reset(message);
			break;
		case 0xA1: // Error
			parse_error(message);
			break;
		case 0x69: // Monthly statement
			parse_monthly(message);
			break;
		default:
			if (!(type & 1)) // Daily
				parse_daily(message);
			break;
	}
}

template<typename T, typename U>
void srt::parser::to_json(std::pair<T, U> &&it)
{
	o_json[it.first] = it.second;
}

void srt::parser::parse_reset(uint64_t &message)
{
	uint64_t value = message >> 24 & 0x0FFFFFFFFFF;
	value = __builtin_bswap32(value);
	uint64_t hard = message >> 16 & 0xFF;
	uint64_t soft = message >> 8 & 0xFF;
	uint64_t crc = message & 0xFF;
	to_json(std::make_pair("value", value));
	to_json(std::make_pair("hard", hard));
	to_json(std::make_pair("firmware", soft));
	to_json(std::make_pair("crc", crc));
}

void srt::parser::parse_error(uint64_t &message)
{
	uint64_t value = message >> 24 & 0x0FFFFFFFFFF;
	value = __builtin_bswap32(value);
	uint64_t hard = message >> 16 & 0xFF;
	uint64_t soft = message >> 8 & 0xFF;
	uint64_t crc = message & 0xFF;
	to_json(std::make_pair("err_code", value));
	to_json(std::make_pair("hard", hard));
	to_json(std::make_pair("firmware", soft));
	to_json(std::make_pair("crc", crc));
}

void srt::parser::parse_monthly(uint64_t &message)
{
	uint64_t value = message >> 24 & 0x0FFFFFFFFFF;
	value = __builtin_bswap32(value);
	uint64_t count = message >> 8 & 0xFFFF;
	count = __builtin_bswap16(count);
	uint64_t meta = message & 0xFF;
	to_json(std::make_pair("value", value));
	to_json(std::make_pair("count", count));
	to_json(std::make_pair("strength", meta >> 6));
	to_json(std::make_pair("flow", meta & 0x3F));
}

void srt::parser::parse_daily(uint64_t &message)
{
	uint64_t meta = message & 0xFFFFFFFFFFFF;
	uint64_t counter = message >> 48;
	counter = __builtin_bswap16(counter);

	to_json(std::make_pair("counter", counter >> 1));
	to_json(std::make_pair("meta", meta));

	std::vector<std::array<uint16_t, 4>> hours(6);

	for (int i = 0; i < 48; i += 8) {
		auto temp = meta >> i & 0xFF;
		to_json(std::make_pair<std::string, std::array<uint16_t, 4>>(
				"[consumption] " +
				std::to_string(i / 2) + "-" +
				std::to_string(i / 2 + 3),
				{
						static_cast<unsigned short>(temp >> 6),
						static_cast<unsigned short>(temp >> 4 & 0x3),
						static_cast<unsigned short>(temp >> 2 & 0x3),
						static_cast<unsigned short>(temp & 0x3)
				}
		        )
		);
	}
}
