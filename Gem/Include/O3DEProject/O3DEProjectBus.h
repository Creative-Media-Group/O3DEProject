
#pragma once

#include <O3DEProject/O3DEProjectTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace O3DEProject
{
    class O3DEProjectRequests
    {
    public:
        AZ_RTTI(O3DEProjectRequests, O3DEProjectRequestsTypeId);
        virtual ~O3DEProjectRequests() = default;
        // Put your public methods here
    };

    class O3DEProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using O3DEProjectRequestBus = AZ::EBus<O3DEProjectRequests, O3DEProjectBusTraits>;
    using O3DEProjectInterface = AZ::Interface<O3DEProjectRequests>;

} // namespace O3DEProject
