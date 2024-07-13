
#pragma once

#include <AzCore/Component/Component.h>

#include <O3DEProject/O3DEProjectBus.h>

namespace O3DEProject
{
    class O3DEProjectSystemComponent
        : public AZ::Component
        , protected O3DEProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(O3DEProjectSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        O3DEProjectSystemComponent();
        ~O3DEProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // O3DEProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
