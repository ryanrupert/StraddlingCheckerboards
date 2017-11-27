#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Encoding.h"

TEST_CASE("English encode")
{
	Crypto crypto;
	crypto.setLang("EN");
	CHECK(crypto.encode("CT1", "TEST") == "62836");
	CHECK(crypto.encode("CT1", "A") == "1");
	CHECK(crypto.encode("CT1", "B") == "70");
	CHECK(crypto.encode("CT1", "VIM") == "85379");
	CHECK(crypto.encode("CT1", "HOW ARE YOU.") == "75586991822998858491");
	CHECK(crypto.encode("CT1", "A YOUNG MAN NAMED JOHN RECEIVED A PARROT AS A GIFT.") == "19988584474997914994179272997657549906867299199801828256991839919974373691");
}

TEST_CASE("English decode")
{
	Crypto crypto;
	crypto.setLang("EN");
	CHECK(crypto.decode("CT1", "62836") == "TEST");
	CHECK(crypto.decode("CT1", "1") == "A");
	CHECK(crypto.decode("CT1", "70") == "B");
	CHECK(crypto.decode("CT1", "85379") == "VIM");
	CHECK(crypto.decode("CT1", "75586991822998858491") == "HOW ARE YOU.");
	CHECK(crypto.decode("CT1", "19988584474997914994179272997657549906867299199801828256991839919974373691") == "A YOUNG MAN NAMED JOHN RECEIVED A PARROT AS A GIFT.");
}

TEST_CASE("English encode codepage")
{
	Crypto crypto;
	crypto.setLang("EN");
	CHECK(crypto.encode("CT1", "HELLO") == "0956");
	CHECK(crypto.encode("CT1", "ABORT") == "0000");
	CHECK(crypto.encode("CT1", "ACCEPT") == "0019");
	CHECK(crypto.encode("CT1", "CHANGE") == "0145");
}

TEST_CASE("German encode")
{
	Crypto crypto;
	crypto.setLang("DE");
	CHECK(crypto.encode("CT1", "TEST") == "8326083");
	CHECK(crypto.encode("CT1", "A") == "1");
	CHECK(crypto.encode("CT1", "B") == "70");
	CHECK(crypto.encode("CT1", "VIM") == "85379");
}

TEST_CASE("German encode" * doctest::should_fail())
{
	Crypto crypto;
	crypto.setLang("DE");
	CHECK(crypto.encode("CT1", "ß") == "62");
	CHECK(crypto.encode("CT1", "Ä") == "61");
	CHECK(crypto.encode("CT1", "Ö") == "63");
	CHECK(crypto.encode("CT1", "Ü") == "64");
}

TEST_CASE("Spanish encode" * doctest::should_fail())
{
	Crypto crypto;
	crypto.setLang("ES");
	CHECK(crypto.encode("CT1", "Á") == "61");
	CHECK(crypto.encode("CT1", "É") == "62");
	CHECK(crypto.encode("CT1", "Í") == "63");
	CHECK(crypto.encode("CT1", "Ó") == "64");
	CHECK(crypto.encode("CT1", "Ú") == "65");
	CHECK(crypto.encode("CT1", "Ñ") == "66");
	CHECK(crypto.encode("CT1", "¡") == "67");
	CHECK(crypto.encode("CT1", "¿") == "68");
}

TEST_CASE("getLang test")
{
	std::string temp; 
	Crypto crypto;
	crypto.setLang("EN");
	temp = crypto.getLang();
	CHECK(temp == "EN");

	crypto.setLang("DE");
	temp = crypto.getLang();
	CHECK(temp == "DE");
	
	crypto.setLang("ES");
	temp = crypto.getLang();
	CHECK(temp == "ES");
}
