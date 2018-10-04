#pragma once

// 3�����x�N�g���N���X
// �x�N�g�����m�̉����Z,�X�J���[���揜�Z,����,�O��,�傫���̌v�Z,���K�����ł���
struct Vector3{
	// default : �������Ȃ�
	Vector3();

	// normal : �����̒l�������̂𐶐�
	explicit Vector3( const double x_, const double y_, const double z_ );

	// copy : �����Ɠ������l�����ʎ��̂𐶐�
	Vector3( const Vector3& vec );

	~Vector3();

	// ���ӂ̎���(this)��x,y,z�ɉE�ӂ̎��̂�x,y,z�̒l����
	Vector3& operator=( const Vector3& vec );

	// �x�N�g�����m�̉����Z�@����
	Vector3 operator+( const Vector3& vec ) const;
	Vector3 operator-( const Vector3& vec ) const;

	// �X�J���[�揜�Z (v/2 �̂悤�ɉE���ɃX�J���[)
	Vector3 operator/( const double num ) const;
	Vector3 operator*( const double num ) const;

	// �傫�������߂�
	double Abs() const;

	// ���K��
	Vector3 NormalizedVector() const;

	double x, y, z;
};

// �X�J���[��Z (2v �̂悤�ɍ����ɃX�J���[)
Vector3 operator*( const double num, const Vector3& vec );

// �x�N�g���̓��ρE�O��
double Dot( const Vector3& a, const Vector3& b );
Vector3 Cross( const Vector3& a, const Vector3& b );