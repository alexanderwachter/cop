#ifndef COP_CHANNEL_HPP
#define COP_CHANNEL_HPP

#include "Id.hpp"
#include "Error.hpp"

namespace cop {
    class Channel {
    public:
        ProtocolErrc sendEvent(/*Message& e*/) {
            return static_cast<ProtocolErrc>(0);
        }

    private:
        template<typename BeginItr, typename EndItr>
        ProtocolErrc read(BeginItr& beginItr, EndItr& endItr) {

            return static_cast<ProtocolErrc>(0);
        }
    };
}

#endif // COP_CHANNEL_HPP

