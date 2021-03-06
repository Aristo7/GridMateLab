/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#pragma once

// include the required headers
#include "EMotionFXConfig.h"
#include "AnimGraphNode.h"


namespace EMotionFX
{
    /**
     * The blend tree's final node.
     * This node always exists inside the blend tree.
     * The input of this node will be what the motion tree's output will be.
     * The final node has only one single input.
     */
    class EMFX_API BlendTreeFinalNode
        : public AnimGraphNode
    {
        MCORE_MEMORYOBJECTCATEGORY(BlendTreeFinalNode, EMFX_DEFAULT_ALIGNMENT, EMFX_MEMCATEGORY_ANIMGRAPH_BLENDTREENODES);

    public:
        AZ_RTTI(BlendTreeFinalNode, "{1A755218-AD9D-48EA-86FC-D571C11ECA4D}", AnimGraphNode);

        enum
        {
            TYPE_ID = 0x00000001
        };

        enum
        {
            OUTPUTPORT_RESULT   = 0
        };

        enum
        {
            PORTID_OUTPUT_POSE = 0
        };

        enum
        {
            INPUTPORT_POSE  = 0
        };

        enum
        {
            PORTID_INPUT_POSE   = 0
        };


        static BlendTreeFinalNode* Create(AnimGraph* animGraph);

        AnimGraphPose* GetMainOutputPose(AnimGraphInstance* animGraphInstance) const override         { return GetOutputPose(animGraphInstance, OUTPUTPORT_RESULT)->GetValue(); }

        void RegisterPorts() override;
        void RegisterAttributes() override;

        bool GetHasOutputPose() const override                  { return true; }
        uint32 GetVisualColor() const override                  { return MCore::RGBA(255, 0, 0); }
        bool GetIsDeletable() const override                    { return false; }
        bool GetIsLastInstanceDeletable() const override        { return false; }
        bool GetHasVisualOutputPorts() const override           { return false; }
        bool GetCanHaveOnlyOneInsideParent() const override     { return true; }
        AnimGraphObjectData* CreateObjectData() override;

        const char* GetPaletteName() const override;
        AnimGraphObject::ECategory GetPaletteCategory() const override;

        const char* GetTypeString() const override;
        AnimGraphObject* Clone(AnimGraph* animGraph) override;

    private:
        BlendTreeFinalNode(AnimGraph* animGraph);
        ~BlendTreeFinalNode();

        void Init(AnimGraphInstance* animGraphInstance) override;
        void Output(AnimGraphInstance* animGraphInstance) override;
        void Update(AnimGraphInstance* animGraphInstance, float timePassedInSeconds) override;
    };
}   // namespace EMotionFX
