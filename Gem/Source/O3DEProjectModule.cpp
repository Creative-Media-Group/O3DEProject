
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "O3DEProjectSystemComponent.h"

#include <O3DEProject/O3DEProjectTypeIds.h>

namespace O3DEProject
{
    class O3DEProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(O3DEProjectModule, O3DEProjectModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(O3DEProjectModule, AZ::SystemAllocator);

        O3DEProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                O3DEProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<O3DEProjectSystemComponent>(),
            };
        }
    };
}// namespace O3DEProject

AZ_DECLARE_MODULE_CLASS(Gem_O3DEProject, O3DEProject::O3DEProjectModule)
