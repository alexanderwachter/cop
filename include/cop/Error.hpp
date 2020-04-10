#ifndef COP_ERRROR_HPP
#define COP_ERRROR_HPP

#include <system_error>

namespace cop {

enum class ProtocolErrc
{
    success = 0,
    invalidMessageId
};

std::error_code make_error_code(ProtocolErrc);

} // namespace COP

namespace std {
    template<>
    struct is_error_code_enum<cop::ProtocolErrc> : true_type{};
}

#endif // COP_ERRROR_HPP
