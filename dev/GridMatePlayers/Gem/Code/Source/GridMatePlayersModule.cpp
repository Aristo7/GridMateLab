
#include "StdAfx.h"
#include <platform_impl.h>

#include <AzCore/Memory/SystemAllocator.h>

#include "GridMatePlayersSystemComponent.h"

#include <IGem.h>
#include "Components/PlayerControlsComponent.h"
#include "Components/InputCaptureComponent.h"

namespace GridMatePlayers
{
    class GridMatePlayersModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(GridMatePlayersModule, "{64B11EE9-696F-4A5A-90CC-FBD6E4867667}", CryHooksModule);
        AZ_CLASS_ALLOCATOR(GridMatePlayersModule, AZ::SystemAllocator, 0);

        GridMatePlayersModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                GridMatePlayersSystemComponent::CreateDescriptor(),
                InputCaptureComponent::CreateDescriptor(),
                PlayerControlsComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<GridMatePlayersSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(GridMatePlayers_83176372815649969d9127938273d9ad, GridMatePlayers::GridMatePlayersModule)
