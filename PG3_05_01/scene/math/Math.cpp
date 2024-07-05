#include "Math.h"

//加法
Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	Vector2 result{};
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
}

//加法(+=)
Vector2& operator+=(Vector2& v1, const Vector2& v2) {
	v1 = v1 + v2;
	return v1;
}

//加法(Vector2とfloat)
Vector2 operator+(const Vector2& v1, const float num) {
	Vector2 result{};
	result.x = v1.x + num;
	result.y = v1.y + num;
	return result;
}

//加法(Vector2とfloatの+=)
Vector2 operator+=(Vector2& v1, const float num) {
	v1 = v1 + num;
	return v1;
}


