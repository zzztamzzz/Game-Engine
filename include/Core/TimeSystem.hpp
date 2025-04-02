#pragma once

#include <vector>
#include <chrono>
#include "Vector4D.hpp"

struct TimeZone {
    // zone being the moment in time, giving possiblity of going through it
    Vector4D position;
    float radius;
    float timeScale; 
};

class TimeSystem {
    private:
        float globalTimeScale = 1.0f;
        std::vector<TimeZone> timeZones;
        float currentTime;

        struct TimeState {
            // moment in time is also a physical state
            float timeStamp;
            std::vector<uint8_t> state;
        };

        std::vector<TimeState> timelineStates;
        size_t maxTimelineStates;

    public:
        TimeSystem();

        void Update(float deltaTime);
        void SetGlobalTimeScale(float scale);
        void CreateTimeZone(const Vector4D& position, float radius, float timeScale);
        float GetLocalTimeScale(const Vector4D& position) const;

        // dormamu, i've come to bargain
        void storeTimelineState(const std::vector<uint8_t>& state);
        bool RevertToTime(float timeStamp);
        void ClearTimeline();

        float GetCurrentTime() const { return currentTime; }
};