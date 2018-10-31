#pragma once

// 3次元ベクトルクラス
// ベクトル同士の加減算,スカラーを乗除算,内積,外積,大きさの計算,正規化ができる
struct Vector3{
	// default : 何もしない
	Vector3();

	// normal : 引数の値を持つ実体を生成
	explicit Vector3( const double x_, const double y_, const double z_ );

	// copy : 引数と等しい値を持つ別実体を生成
	Vector3( const Vector3& vec );

	~Vector3();

	// 左辺の実体(this)のx,y,zに右辺の実体のx,y,zの値を代入
	Vector3& operator=( const Vector3& vec );

	// ベクトル同士の加減算　同上
	Vector3 operator+( const Vector3& vec ) const;


	Vector3 operator-( const Vector3& vec ) const;

	// スカラー乗除算 (v/2 のように右側にスカラー)
	Vector3 operator/( const double num ) const;
	Vector3 operator*( const double num ) const;

	// 大きさを求める
	double Abs() const;

	// 正規化
	Vector3 NormalizedVector() const;

	double x, y, z;
};

// スカラー乗算 (2v のように左側にスカラー)
Vector3 operator*( const double num, const Vector3& vec );

// ベクトルの内積・外積
double Dot( const Vector3& a, const Vector3& b );
Vector3 Cross( const Vector3& a, const Vector3& b );