#include "TimeSystem.hpp"
#include <algorithm>

// should be similar to engine.cpp 
// this code strictly manages time states and zones, the amount of time player in level will have access to.

TimeSystem::TimeSystem()
    : currentTime(0.0f)
    , globalTimeScale(1.0f)
    ,maxTimelineStates(100) {
}

void TimeSystem::Update(float deltaTime) {
    float scaledDelta = deltaTime * globalTimeScale;
    currentTime += scaledDelta;

    while (timelineStates.size() > maxTimelineStates) {
        timelineStates.erase(timelineStates.begin());
    }
}

float TimeSystem::GetLocalTimeScale(const Vector4D& position) const {
    float localScale = globalTimeScale;

    for(const auto& zone : timeZones) {
        Vector4D distance = position - zone.position;
        float distanceSquared = distance.LengthSquared();

        if (distanceSquared < zone.radius * zone.radius) {
            float effect = 1.0f - (std::sqrt(distanceSquared) / zone.radius);
            localScale *= zone.timeScale * effect;
        }
    }
    return localScale;
}