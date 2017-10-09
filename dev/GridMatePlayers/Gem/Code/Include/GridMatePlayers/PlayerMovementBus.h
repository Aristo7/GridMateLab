#pragma once
#include <AzCore/EBus/EBus.h>

namespace GridMatePlayers
{
    class PlayerMovementInterface
        : public AZ::EBusTraits
    {
    public:
        virtual ~PlayerMovementInterface() = default;

        ///////////////////////////////////////////////////
        // EBusTraits overrides
        static const AZ::EBusHandlerPolicy HandlerPolicy =
            AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy =
            AZ::EBusAddressPolicy::ById;
        using BusIdType = AZ::EntityId;
        ///////////////////////////////////////////////////

        // Put your public methods here
        virtual void ForwardKeyUp() = 0;
        virtual void ForwardKeyDown() = 0;
    };

    using PlayerMovementBus = AZ::EBus<PlayerMovementInterface>;
} // namespace GridMatePlayers