#include "StdAfx.h"
#include "PlayerControlsComponent.h"
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Component/TransformBus.h>

using namespace AZ;
using namespace GridMatePlayers;

void PlayerControlsComponent::Reflect(ReflectContext* context)
{
    if (auto sc = azrtti_cast<SerializeContext*>(context))
    {
        sc->Class<PlayerControlsComponent>()
            ->Version(1);

        if (auto ec = sc->GetEditContext())
        {
            ec->Class<PlayerControlsComponent>("Player Controls",
                "Controls player according to player input")
                ->ClassElement(Edit::ClassElements::EditorData,
                    "")
                ->Attribute(Edit::Attributes::Category,
                    "GridMate Players")
                ->Attribute(
                    Edit::Attributes::AppearsInAddComponentMenu,
                    AZ_CRC("Game"));
        }
    }
}

void PlayerControlsComponent::Activate()
{
    PlayerControlsBus::Handler::BusConnect(GetEntityId());
    TickBus::Handler::BusConnect();
}

void PlayerControlsComponent::Deactivate()
{
    PlayerControlsBus::Handler::BusDisconnect();
    TickBus::Handler::BusDisconnect();
}

void PlayerControlsComponent::ForwardKeyReleased()
{
    m_movingForward = false;
}

void PlayerControlsComponent::ForwardKeyPressed()
{
    m_movingForward = true;
}

void PlayerControlsComponent::OnTick(
    float deltaTime, ScriptTimePoint)
{
    if (!m_movingForward) return;

    AZ::EntityId parent;
    EBUS_EVENT_ID_RESULT(parent, GetEntityId(),
        AZ::TransformBus, GetParentId);

    Vector3 currentPosition;
    EBUS_EVENT_ID_RESULT(currentPosition, parent,
        AZ::TransformBus, GetWorldTranslation);

    Vector3 newPosition = currentPosition +
        Vector3::CreateAxisY(m_movingSpeedPerSecond * deltaTime);
    EBUS_EVENT_ID(parent, AZ::TransformBus,
        SetWorldTranslation, newPosition);
}