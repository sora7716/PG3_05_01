#pragma once
typedef struct Vector2 {
	float x;
	float y;
}Vector2;

/// <summary>
/// 加法
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
Vector2 operator+(const Vector2& v1, const Vector2& v2);

/// <summary>
/// 加法(+=)
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
Vector2& operator+=(Vector2& v1, const Vector2& v2);

/// <summary>
/// 加法(Vector2とfloat)
/// </summary>
/// <param name="v1"></param>
/// <param name="num"></param>
/// <returns></returns>
Vector2 operator+(const Vector2& v1, const float num);

/// <summary>
/// 加法(Vector2とfloatの+=)
/// </summary>
/// <param name="v1"></param>
/// <param name="num"></param>
/// <returns></returns>
Vector2 operator+=(Vector2& v1, const float num);