#pragma once
#include <cmath>

namespace CBR{

	// 3次元ベクトルクラス
	// ベクトル同士の加減算,スカラーを乗除算,内積,外積,大きさの計算,正規化ができる
	class Vector3{
	public:
		// default : 何もしない
		constexpr Vector3():
			x(0), y(0), z(0){}

		// normal : 引数の値を持つ実体を生成
		constexpr explicit Vector3(const double x_, const double y_, const double z_):
			x(x_), y(y_), z(z_){}

		// copy : 引数と等しい値を持つ別実体を生成
		constexpr Vector3(const Vector3& vec) :
			x(vec.x), y(vec.y), z(vec.z){}

		~Vector3() = default;

		// 左辺の実体(this)のx,y,zに右辺の実体のx,y,zの値を代入
		constexpr Vector3& operator=(const Vector3& vec){
			if(this != &vec){
				x = vec.x;
				y = vec.y;
				z = vec.z;
			}
			return *this;
		}

		// ベクトル同士の加減算　同上
		constexpr Vector3 operator+(const Vector3& vec) const{
			return Vector3(x + vec.x, y + vec.y, z + vec.z);
		}

		constexpr Vector3 operator-(const Vector3& vec) const{
			return Vector3(x - vec.x, y - vec.y, z - vec.z);
		}

		// スカラー乗除算 (v/2 のように右側にスカラー)
		constexpr Vector3 operator/(const double num) const{
			return Vector3(x / num, y / num, z / num);
		}

		constexpr Vector3 operator*(const double num) const{
			return Vector3(x * num, y * num, z * num);
		}

		// 大きさを求める
		double Abs() const{
			return std::sqrt(x * x + y * y + z * z);
		}

		// 正規化
		Vector3 NormalizedVector() const{
			double abs = Abs();
			return Vector3(x / abs, y / abs, z / abs);
		}

		double x, y, z;
	};

	// スカラー乗算 (2v のように左側にスカラー)
	constexpr Vector3 operator*(const double num, const Vector3& vec){
		return Vector3(vec.x * num, vec.y * num, vec.z * num);
	}

	// ベクトルの内積・外積
	constexpr double Dot(const Vector3& a, const Vector3& b){
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	constexpr Vector3 Cross(const Vector3& a, const Vector3& b){
		return Vector3(a.y * b.z - a.z * b.y,
									 a.z * b.x - a.x * b.z,
									 a.x * b.y - a.y * b.x);
	}

}