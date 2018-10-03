#pragma once

// 3次元ベクトルクラス
struct Vector3{
	// default : 何もしない
	Vector3();

	// normal : 引数の値を持つ実体を生成する
	explicit Vector3( const double x_, const double y_, const double z_ );

	// copy : 引数と等しい値を持つ別実体を生成する
	Vector3( const Vector3& vec );

	~Vector3();

	// 左辺の実体のx,y,zに右辺の実体のx,y,zの値を代入
	Vector3& operator=( const Vector3& vec );

	double x, y, z;
};

// ベクトルの内積・外積 a,bの値で演算して新しい実体を生成する
double Dot( const Vector3& a, const Vector3& b );
Vector3 Cross( const Vector3& a, const Vector3& b );

// ベクトルの加減算　同上
Vector3 operator+( const Vector3& a, const Vector3& b );
Vector3 operator-( const Vector3& a, const Vector3& b );