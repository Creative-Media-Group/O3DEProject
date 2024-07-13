
#include <AzCore/Serialization/SerializeContext.h>

#include "O3DEProjectSystemComponent.h"

#include <O3DEProject/O3DEProjectTypeIds.h>

namespace O3DEProject
{
    AZ_COMPONENT_IMPL(O3DEProjectSystemComponent, "O3DEProjectSystemComponent",
        O3DEProjectSystemComponentTypeId);

    void O3DEProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<O3DEProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void O3DEProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("O3DEProjectService"));
    }

    void O3DEProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("O3DEProjectService"));
    }

    void O3DEProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void O3DEProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    O3DEProjectSystemComponent::O3DEProjectSystemComponent()
    {
        if (O3DEProjectInterface::Get() == nullptr)
        {
            O3DEProjectInterface::Register(this);
        }
    }

    O3DEProjectSystemComponent::~O3DEProjectSystemComponent()
    {
        if (O3DEProjectInterface::Get() == this)
        {
            O3DEProjectInterface::Unregister(this);
        }
    }

    void O3DEProjectSystemComponent::Init()
    {
    }

    void O3DEProjectSystemComponent::Activate()
    {
        O3DEProjectRequestBus::Handler::BusConnect();
    }

    void O3DEProjectSystemComponent::Deactivate()
    {
        O3DEProjectRequestBus::Handler::BusDisconnect();
    }
}
