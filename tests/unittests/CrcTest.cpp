#include <catch2/catch.hpp>
#include "cop/Crc.hpp"

SCENARIO("The Crc will be calculated", "[CRC]") {
    GIVEN(" some data") {
        std::vector data{
           std::byte(0x01), std::byte(0x02), std::byte(0x03), std::byte(0x04),
           std::byte(0x05), std::byte(0x06), std::byte(0x07), std::byte(0x08),
           std::byte(0x09), std::byte(0x00), std::byte(0x00)
        };
        auto it = data.begin(); auto end = data.end();

        cop::Crc crc(it, end);

        THEN("the crc will be calculated") {
            crc.send();

            REQUIRE(std::byte(0x42) == data[9]);
            REQUIRE(std::byte(0x04) == data[10]);

        }
    }

    GIVEN(" a message ") {
        std::vector data{
            std::byte('1'), std::byte('2'), std::byte('3'), std::byte('4'),
            std::byte('5'), std::byte('6'), std::byte('7'), std::byte('8'),
            std::byte('9'), std::byte(0xBB), std::byte(0x3D)
        };
        auto it = data.cbegin(); auto end = data.cend();

        cop::Crc crc(it, end);

        THEN(" the crc will be apended") {
            REQUIRE(cop::ProtocolErrc::success == crc.receive());
        }
    }
}
