#pragma once

#include "../../Common/d3dUtil.h"

struct KeyFrame
{
	KeyFrame();
	~KeyFrame();

	float TimePos;
	DirectX::XMFLOAT3 Translation;
	DirectX::XMFLOAT3 Scale;
	DirectX::XMFLOAT4 RotationQuat;

};

struct BoneAnimation
{
	float GetStartTime() const;
	float GetEndTime() const;

	void Interpolate(float t, DirectX::XMFLOAT4X4& M) const;

	std::vector<KeyFrame> Keyframes;

};