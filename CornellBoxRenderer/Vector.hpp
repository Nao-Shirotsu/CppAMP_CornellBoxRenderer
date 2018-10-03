#pragma once

// 3�����x�N�g���N���X
struct Vector3{
	// default : �������Ȃ�
	Vector3();

	// normal : �����̒l�������̂𐶐�����
	explicit Vector3( const double x_, const double y_, const double z_ );

	// copy : �����Ɠ������l�����ʎ��̂𐶐�����
	Vector3( const Vector3& vec );

	~Vector3();

	// ���ӂ̎��̂�x,y,z�ɉE�ӂ̎��̂�x,y,z�̒l����
	Vector3& operator=( const Vector3& vec );

	double x, y, z;
};

// �x�N�g���̓��ρE�O�� a,b�̒l�ŉ��Z���ĐV�������̂𐶐�����
double Dot( const Vector3& a, const Vector3& b );
Vector3 Cross( const Vector3& a, const Vector3& b );

// �x�N�g���̉����Z�@����
Vector3 operator+( const Vector3& a, const Vector3& b );
Vector3 operator-( const Vector3& a, const Vector3& b );