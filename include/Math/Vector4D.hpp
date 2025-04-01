#pragma once
#include <cmath>

class Vector4D {
    private:
        float x, y, z, w; 
    public:
    Vector4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f) : x(x), y(y), z(z), w(w) {}

    Vector4D operator+(const Vector4D& other) const {
        return Vector4D(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vector4D operator-(const Vector4D& other) const {
        return Vector4D(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vector4D operator*(float scalar) const {
        return Vector4D(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    float DotProduct(const Vector4D& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    float LengthSquared() const {
        return x * x + y * y + z * z + w * w;
    }

    float Length() const {
        return std::sqrt(LengthSquared());
    }

    Vector4D Normalize() const {
        float len = Length();
        if (len > 0){
            return *this * (1.0f / len);
        }
        return *this; // 0 division 
    }

    float GetX() const { return x; }
    float GetY() const { return y; }
    float GetZ() const { return z; }
    float GetW() const { return w; }

    void SetX(float value) { x = value; }
    void SetY(float value) { y = value; }
    void SetZ(float value) { z = value; }
    void SetW(float value) { w = value; }

    float GetTimeComponent() const { return w; } 
    void SetTimeComponent(float value) { w = value; }
    void SetComponents(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};