#pragma once

#include "RenderingData.hpp"

// RenderingData�^�����Ƃ�.ppm�t�@�C���𐶐�����(==ppm�t�@�C���ɕ`�悷��)
// length = ���� = x,  width = �c�� = y
void GeneratePpmFile( const RenderingData* color, const int length, const int width );

// 0.0~1.0�̐F�f�[�^��0~255�̐����l�ɕϊ�
int ToPixelValue( double n );