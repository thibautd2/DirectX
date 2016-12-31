////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "cameraclass.h"


CameraClass::CameraClass()
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;

	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;
}


CameraClass::CameraClass(const CameraClass& other)
{
}


CameraClass::~CameraClass()
{
}


void CameraClass::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
	return;
}


void CameraClass::SetRotation(float x, float y, float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
	return;
}


Vector3 CameraClass::GetPosition()
{
	return Vector3(m_positionX, m_positionY, m_positionZ);
}


Vector3 CameraClass::GetRotation()
{
	return Vector3(m_rotationX, m_rotationY, m_rotationZ);
}


void CameraClass::Render()
{
	Vector3 up, position, lookAt;
	float yaw, pitch, roll;
	Matrix rotationMatrix;


	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	// Setup the position of the camera in the world.
	position.x = m_positionX;
	position.y = m_positionY;
	position.z = m_positionZ;

	// Setup where the camera is looking by default.
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	pitch = m_rotationX * 0.0174532925f;
	yaw   = m_rotationY * 0.0174532925f;
	roll  = m_rotationZ * 0.0174532925f;

	// Create the rotation matrix from the yaw, pitch, and roll values.
	rotationMatrix.CreateFromYawPitchRoll(yaw, pitch, roll);
		// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	lookAt.Transform(lookAt, rotationMatrix);
	up.Transform(up, rotationMatrix);

	// Translate the rotated camera position to the location of the viewer.
	lookAt = position + lookAt;

	// Finally create the view matrix from the three updated vectors.
	m_viewMatrix.CreateLookAt(position, lookAt, up);
	return;
}


void CameraClass::GetViewMatrix(Matrix& viewMatrix)
{
	viewMatrix = m_viewMatrix;
	return;
}


void CameraClass::RenderBaseViewMatrix()
{
	Vector3 up, position, lookAt;
	float yaw, pitch, roll;
	Matrix rotationMatrix;


	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	// Setup the position of the camera in the world.
	position.x = m_positionX;
	position.y = m_positionY;
	position.z = m_positionZ;

	// Setup where the camera is looking by default.
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	pitch = m_rotationX * 0.0174532925f;
	yaw   = m_rotationY * 0.0174532925f;
	roll  = m_rotationZ * 0.0174532925f;

	// Create the rotation matrix from the yaw, pitch, and roll values.
	rotationMatrix.CreateFromYawPitchRoll(yaw, pitch, roll);
	// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	lookAt.Transform(lookAt, rotationMatrix);
	up.Transform(up, rotationMatrix);


	// Translate the rotated camera position to the location of the viewer.
	lookAt = position + lookAt;

	// Finally create the base view matrix from the three updated vectors.
	m_baseViewMatrix.CreateLookAt( position, lookAt, up);
	return;
}


void CameraClass::GetBaseViewMatrix(Matrix& viewMatrix)
{
	viewMatrix = m_baseViewMatrix;
	return;
}


void CameraClass::RenderReflection(float height)
{
	Vector3 up, position, lookAt;
	float yaw, pitch, roll;
	Matrix rotationMatrix;


	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	// Setup the position of the camera in the world.  For planar reflection invert the Y position of the camera.
	position.x = m_positionX;
	position.y = -m_positionY + (height * 2.0f);
	position.z = m_positionZ;

	// Setup where the camera is looking by default.
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.  Invert the X rotation for reflection.
	pitch = -m_rotationX * 0.0174532925f;
	yaw   = m_rotationY * 0.0174532925f;
	roll  = m_rotationZ * 0.0174532925f;

	// Create the rotation matrix from the yaw, pitch, and roll values.
	rotationMatrix.CreateFromYawPitchRoll(yaw, pitch, roll);
	// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	lookAt.Transform(lookAt, rotationMatrix);
	up.Transform(up, rotationMatrix);

	// Translate the rotated camera position to the location of the viewer.
	lookAt = position + lookAt;

	// Finally create the reflection view matrix from the three updated vectors.
	m_reflectionViewMatrix.CreateLookAt(position, lookAt, up);

	return;
}


void CameraClass::GetReflectionViewMatrix(Matrix& viewMatrix)
{
	viewMatrix = m_reflectionViewMatrix;
	return;
}